#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

void main() {
	VideoCapture video(0);  //0 for webcam or add a path for a video

	CascadeClassifier Facedetect;
	Facedetect.load("haarcascade_frontalface_default.xml");


	Mat img; //mat is matrix data type


	//infinite loop as video is seq of images
	while (true) {
		//read the video
		video.read(img);

		//vector to store no of faces
		vector<Rect> face;
		Facedetect.detectMultiScale(img, face, 1.3, 5);

		//rectangle box
		for (int i = 0; i < face.size(); i++) {
			rectangle(img, face[i].tl(), face[i].br(), Scalar(50, 50, 255), 6);
		}

		//array output
		rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
		putText(img, to_string(face.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);

		//display frame
		imshow("Frame", img);
		// add delay of 1
		waitKey(1);


	}
}



