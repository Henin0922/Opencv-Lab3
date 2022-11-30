#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//�����˲�����
void myfilter(Mat& image_input, Mat& image_output); //������
void myfilter2(Mat& image_input, Mat& image_output); //������

int main()
{
	Mat image, image_gray, image_output, image_output2;   //��������ͼ�񣬻Ҷ�ͼ�����ͼ��
	image = imread("C:\\Users\\zhx_8\\Pictures\\opencv\\dog.jpg");  //��ȡͼ��
	if (image.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}
	imshow("image", image);

	cvtColor(image, image_gray, COLOR_BGR2GRAY);
	imshow("image_gray", image_gray);

	//�Աຯ��
	myfilter(image_gray, image_output); //4����
	imshow("image_output", image_output);

	myfilter2(image_gray, image_output2); //8����
	imshow("image_output2", image_output2);

	waitKey(0);  //��ͣ������ͼ����ʾ���ȴ���������
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