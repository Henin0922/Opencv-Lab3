#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//¶¨ÒåÂË²¨º¯Êı
void myfilter(Mat& image_input, Mat& image_output); //ËÄÁÚÓò
void myfilter2(Mat& image_input, Mat& image_output); //°ËÁÚÓò

int main()
{
	Mat image, image_gray, image_output, image_output2;   //¶¨ÒåÊäÈëÍ¼Ïñ£¬»Ò¶ÈÍ¼Ïñ£¬Êä³öÍ¼Ïñ
	image = imread("C:\\Users\\zhx_8\\Pictures\\opencv\\dog.jpg");  //¶ÁÈ¡Í¼Ïñ£»
	if (image.empty())
	{
		cout << "¶ÁÈ¡´íÎó" << endl;
		return -1;
	}
	imshow("image", image);

	cvtColor(image, image_gray, COLOR_BGR2GRAY);
	imshow("image_gray", image_gray);

	//×Ô±àº¯Êı
	myfilter(image_gray, image_output); //4ÁÚÓò
	imshow("image_output", image_output);

	myfilter2(image_gray, image_output2); //8ÁÚÓò
	imshow("image_output2", image_output2);

	waitKey(0);  //ÔİÍ££¬±£³ÖÍ¼ÏñÏÔÊ¾£¬µÈ´ı°´¼ü½áÊø
	return 0;
}


void myfilter(Mat& image_input, Mat& image_output) //4
{
	image_output = image_input.clone();
	int la;
	for (int i = 1; i < (image_input.rows - 1); i++)
	{
		for (int j = 1; j < (image_input.cols - 1); j++)
		{
			la = 4 * image_input.at<uchar>(i, j) - image_input.at<uchar>(i + 1, j) - image_input.at<uchar>(i - 1, j) - image_input.at<uchar>(i, j + 1) - image_input.at<uchar>(i, j - 1);

			image_output.at<uchar>(i, j) = saturate_cast<uchar>(image_output.at<uchar>(i, j) + la);

		}
	}
}

void myfilter2(Mat & image_input, Mat & image_output) //8
{
	image_output = image_input.clone();
	int la2;
	for (int i = 1; i < (image_input.rows - 1); i++)
	{
		for (int j = 1; j < (image_input.cols - 1); j++)
		{
			la2 = 8 * image_input.at<uchar>(i, j) - image_input.at<uchar>(i + 1, j) - image_input.at<uchar>(i - 1, j) - image_input.at<uchar>(i, j + 1) - image_input.at<uchar>(i, j - 1)
				- image_input.at<uchar>(i - 1, j - 1) - image_input.at<uchar>(i + 1, j + 1) - image_input.at<uchar>(i - 1, j + 1) - image_input.at<uchar>(i + 1, j - 1);

			image_output.at<uchar>(i, j) = saturate_cast<uchar>(image_output.at<uchar>(i, j) + la2);

		}
	}
}