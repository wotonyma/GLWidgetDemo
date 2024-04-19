#pragma once

/*
* @file		find_cross_center.h
* @author	huq.
* @brief	寻找点胶十字交叉的中心.
* @date		2024.4.18
*/

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>

/*
* @brief    获取点到直线的距离
* @param    line    输入的直线{x1,y1,x2,y2}
* @param    pt      输入的点
* @return   点到直线的距离(可为负数)
*/
double getPoint2LineDist(cv::Vec4d line, cv::Point2d pt);


/*
* @brief    输入笛卡尔坐标直线转化为极坐标直线
* @param    line    输入的直线{x1,y1,x2,y2}
* @return   返回极坐标的{theta, rho}
*/
cv::Vec2f cart2Polar(cv::Vec4d line);


/*
* @brief    将相近的直线分组
* @param    lines   极坐标直线{ {theta, rho} }
* @return   返回分组{{avg_theta, avg_rho, count}}
*/
std::vector<cv::Vec3f> groupPolarLines(const std::vector<cv::Vec2f> lines, float theta_thresh = 0.01, float rho_thresh = 50.0);


/*
* @brief    获取极坐标直线的某两个点,此两点贯穿图片尺寸
* @param    size    图片尺寸
* @param    theta   极坐标直线theta
* @param    rho     极坐标直线rho
* @return   两点坐标{x1,y1,x2,y2}
*/
cv::Vec4d getPointsFromPolar(cv::Size size, float theta, float rho);



/*
* @brief     判断两条线是否相交，若相交则求出交点和夹角
* @param    l1  line1
* @param    l2  line2
* @return   返回值{br, x0, y0, angle}
*/
cv::Vec4d linesIntersection(const cv::Vec4d& l1, const cv::Vec4d& l2);



/*
* @brief    计算处理好的十字线图片的交点坐标
* @param	edges			处理好的轮廓图片
* @param	hough_param		HoughLinesP最后3个参数
* @param	edges_thresh	根据图片质量和十字宽度调整合适的参数
*/
cv::Point2d findCrossCenter(cv::Mat edges, cv::Vec3i hough_param, cv::Vec2f edges_thresh);
