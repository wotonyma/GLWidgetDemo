#pragma once

#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <numeric>
#include <unordered_map>
#include <algorithm>

cv::Mat getGrayMatHist(cv::Mat grayImg)
{
	//需要计算的图像的通道，灰度图像为0，BGR图像需要指定B,G,R
	const int channels[] = { 0 };
	cv::Mat hist;//定义输出Mat类型
	int dims = 1;//设置直方图维度
	const int histSize[] = { 256 }; //直方图每一个维度划分的柱条的数目
	//每一个维度取值范围
	float pranges[] = { 0, 255 };//取值区间
	const float* ranges[] = { pranges };

	calcHist(&grayImg, 1, channels, cv::Mat(), hist, dims, histSize, ranges, true, false);//计算直方图
	return hist;
}

/* ww wh = diplay window size*/
void drawGrayMatHist(cv::Mat grayImg, uint32_t ww, uint32_t wh)
{
	auto hist = getGrayMatHist(grayImg);
	int hist_w = ww;
	int hist_h = wh;
	int nHistSize = 256;
	int bin_w = cvRound((double)hist_w / nHistSize);	//区间
	cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));//创建一个黑底的8位的3通道图像，高300，宽500
	normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());//将直方图归一化到[0,histImage.rows]
	for (int i = 1; i < nHistSize; i++)
	{
		line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))), cv::Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))), cv::Scalar(255, 255, 255));
	}
	cv::imshow("hist", histImage);
	cv::waitKey(0);
}

template <class T>
std::vector<size_t> findPeaks(const std::vector<T>& src, int distance = 0);
template <class T>
std::vector<size_t> findPeaks(const std::vector<T>& src, int distance)
{
	size_t length = src.size();
	if (length <= 1) return std::vector<size_t>();
	//we dont need peaks at start and end points
	std::vector<int> sign(length, -1);
	std::vector<T> difference(length, 0);
	std::vector<size_t> temp_out;
	//first-order difference (sign)
	adjacent_difference(src.begin(), src.end(), difference.begin());
	difference.erase(difference.begin());
	difference.pop_back();
	for (int i = 0; i < difference.size(); ++i) {
		if (difference[i] >= 0) sign[i] = 1;
	}
	//second-order difference
	for (int j = 1; j < length - 1; ++j)
	{
		int  diff = sign[j] - sign[j - 1];
		if (diff < 0) {
			temp_out.push_back(j);
		}
	}
	if (temp_out.size() == 0 || distance == 0) return temp_out;
	//sort peaks from large to small by src value at peaks
	std::sort(temp_out.begin(), temp_out.end(), [&src](size_t a, size_t b) {
		return (src[a] > src[b]);
		});

	std::vector<size_t> ans;

	//Initialize the answer and the collection to be excluded
	//ans.push_back(temp_out[0]);
	std::unordered_map<size_t, int> except;
	////    int left=temp_out[0]-distance>0? temp_out[0]-distance:0;
	////    int right=temp_out[0]+distance>length-1? length-1:temp_out[0]+distance;
	//    int left=temp_out[0]-distance;
	//    int right=temp_out[0]+distance;
	//    for (int i = left;i<=right; ++i) {
	//        except.insert(i);
	//    }
	for (auto it : temp_out) {
		if (!except.count(it))//如果不在排除范围内
		{
			ans.push_back(it);
			//更新
			size_t left = it - distance > 0 ? it - distance : 0;
			size_t right = it + distance > length - 1 ? length - 1 : it + distance;
			for (size_t i = left; i <= right; ++i)
				++except[i];
		}
	}
	//sort the ans from small to large by index value
	std::sort(ans.begin(), ans.end());
	return ans;
}

std::vector<size_t> findGrayImgPeaks(cv::Mat grayImg, int distance)
{
	auto hist = getGrayMatHist(grayImg);
	std::vector<int> in_vec;
	for (int i = 0; i < 256; ++i) {
		in_vec.emplace_back(hist.at<float>(i));
	}

	auto peaks = findPeaks(in_vec, distance);

	int minHeight = grayImg.cols * grayImg.rows / 200.0; //柱状图最低高度
	auto iter = std::remove_if(peaks.begin(), peaks.end(), [&in_vec, minHeight](size_t idx) {
		return in_vec[idx] < minHeight;
		});

	auto filter = std::vector<size_t>(peaks.begin(), iter); //按照波峰灰度分布从大到小排序
	std::sort(filter.begin(), filter.end(), [&in_vec](int idx1, int idx2) {
		return in_vec[idx1] > in_vec[idx2];
		});
	
	return filter;
}
