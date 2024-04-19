#include "find_cross_center.h"

double getPoint2LineDist(cv::Vec4d line, cv::Point2d pt)
{
    double x1 = line[0];
    double y1 = line[1];
    double x2 = line[2];
    double y2 = line[3];
    double x0 = pt.x;
    double y0 = pt.y;
    double distance;
    distance = ((y1 - y2) * x0 - (x1 - x2) * y0 + (x1 * y2 - x2 * y1)) / sqrt(pow(y1 - y2, 2) + pow(x1 - x2, 2));
    return distance;
}


cv::Vec2f cart2Polar(cv::Vec4d line)
{
    float k = 0; //直线斜率
    float dist = 0; //(0，0)点到直线的距离

    dist = getPoint2LineDist(line, { 0, 0 });

    if ((line[2] - line[0]) == 0)
        k = CV_PI / 2.0;
    else
        k = (double)(line[3] - line[1]) / (double)(line[2] - line[0]); //求出直线的斜率

    float theta = atan(k) + CV_PI / 2.0;
    float rho = -dist;
    return { theta, rho };
}


std::vector<cv::Vec3f> groupPolarLines(const std::vector<cv::Vec2f> lines, float theta_thresh, float rho_thresh)
{
    std::vector<cv::Vec3f> group_lines; //{avg_theta, avg_rho, count}
    group_lines.emplace_back(cv::Vec3f(lines[0][0], lines[0][1], 1.f)); //init push one
    for (int i = 1; i < lines.size(); ++i)
    {
        float theta = lines[i][0];
        float rho = lines[i][1];

        bool findgroup = false;
        for (auto &avg : group_lines)
        {
            if (theta > avg[0] + theta_thresh || theta < avg[0] - theta_thresh)
                continue;
            if (rho > avg[1] + rho_thresh || rho < avg[1] - rho_thresh)
                continue;

            avg[0] = (avg[0] * avg[2] + theta) / (avg[2] + 1);
            avg[1] = (avg[1] * avg[2] + rho) / (avg[2] + 1);
            avg[2]++;
            findgroup = true;
            break;
        }

        if (!findgroup) // a new group line
            group_lines.emplace_back(theta, rho, 1.f);
    }

    return group_lines;
}


cv::Vec4d getPointsFromPolar(cv::Size size, float theta, float rho)
{
    if (theta < CV_PI / 4.0 || theta > 3.0 * CV_PI / 4.0)// ~vertical line
    {
        cv::Point2d pt1(rho / cos(theta), 0);
        cv::Point2d pt2((rho - size.height * sin(theta)) / cos(theta), size.height);
        return { pt1.x, pt1.y, pt2.x, pt2.y };
    }
    else
    {
        cv::Point2d pt1(0, rho / sin(theta));
        cv::Point2d pt2(size.width, (rho - size.width * cos(theta)) / sin(theta));
        return { pt1.x, pt1.y, pt2.x, pt2.y };
    }
}


cv::Vec4d linesIntersection(const cv::Vec4d& l1, const cv::Vec4d& l2)
{
    double x1 = l1[0], y1 = l1[1], x2 = l1[2], y2 = l1[3];
    double a1 = -(y2 - y1), b1 = x2 - x1, c1 = (y2 - y1) * x1 - (x2 - x1) * y1; // 一般式：a1x+b1y1+c1=0
    double x3 = l2[0], y3 = l2[1], x4 = l2[2], y4 = l2[3];
    double a2 = -(y4 - y3), b2 = x4 - x3, c2 = (y4 - y3) * x3 - (x4 - x3) * y3; // 一般式：a2x+b2y1+c2=0
    bool br = false;                                                             // 判断结果
    double x0 = 0, y0 = 0;                                                      // 交点
    double angle = 0;                                                           // 夹角
    // 判断相交
    if (b1 == 0 && b2 != 0) // l1垂直于x轴，l2倾斜于x轴
        br = true;
    else if (b1 != 0 && b2 == 0) // l1倾斜于x轴，l2垂直于x轴
        br = true;
    else if (b1 != 0 && b2 != 0 && a1 / b1 != a2 / b2)
        br = true;
    if (br)
    {
        //计算交点
        x0 = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
        y0 = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2);
        // 计算夹角
        double a = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2));
        double b = sqrt(pow(x4 - x0, 2) + pow(y4 - y0, 2));
        double c = sqrt(pow(x2 - x0, 2) + pow(y2 - y0, 2));
        angle = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / CV_PI;
    }
    return cv::Vec4d(br, x0, y0, angle);
}

cv::Point2d findCrossCenter(cv::Mat edges, cv::Vec3i hough_param, cv::Vec2f edges_thresh)
{
    int houghThresh = hough_param[0];
    double minLineLength = hough_param[1];
    double minLineGap = hough_param[2];

    std::vector<cv::Vec4i> cartLines;
    cv::HoughLinesP(edges, cartLines, 1, CV_PI / 180, houghThresh, minLineLength, minLineGap);

    std::vector<cv::Vec2f> polarLines;
    for (auto line : cartLines)
        polarLines.emplace_back(cart2Polar(line));

    auto groupLines = groupPolarLines(polarLines, edges_thresh[0], edges_thresh[1]);
    std::sort(groupLines.begin(), groupLines.end(), [](const cv::Vec3f l1, const cv::Vec3f l2) {
        return l1[2] > l2[2]; //compare count
        });

    /*筛选出两组平行直线并转化为两点表示*/
    std::vector<cv::Vec4d> vLines;
    std::vector<cv::Vec4d> hLines;

    float theta0 = groupLines[0][0];
    float rho0 = groupLines[0][1];
    auto pts0 = getPointsFromPolar({ edges.cols, edges.rows }, theta0, rho0);
    vLines.emplace_back(pts0);

    for (int i = 1; i < 4; ++i)
    {
        float theta = groupLines[i][0];
        float rho = groupLines[i][1];
        auto pts = getPointsFromPolar({ edges.cols, edges.rows }, theta, rho); //获取直线上的两个点
        if (abs(theta - theta0) < 0.1)
            vLines.emplace_back(pts);
        else 
            hLines.emplace_back(pts);   
    }

    std::vector<cv::Point> cross_pts; //四个交点
    for (auto& vl : vLines)
        for (auto& hl : hLines) {
            auto res = linesIntersection(vl, hl);
            cross_pts.emplace_back((int)res[1], (int)res[2]);
        }
          
    auto rect = cv::boundingRect(cross_pts);
    return { rect.tl().x + rect.width / 2.0, rect.tl().y + rect.height / 2.0 };
}