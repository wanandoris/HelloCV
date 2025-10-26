#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

Mat getCoutours(Mat imgDil,Mat img,String color){
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
        if(area>=2100){
            float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            boundRect[i]=boundingRect(conPoly[i]);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 2);
            putText(img,color,Point(25, 25), FONT_HERSHEY_DUPLEX,1,Scalar(255, 255, 255),1);
        }
    }
    return img;
}


Mat findThecolor(Mat imgHSV,Scalar lower,Scalar upper,Mat img,string color){
    Mat mask,imgGauss,imgCanny,imgDil;
    inRange(imgHSV, lower, upper, mask);
    GaussianBlur(mask,imgGauss,Size(3,3),3,0);
    Canny(imgGauss,imgCanny,25,75);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(2,2));
    dilate(imgCanny,imgDil,kernel);
    imshow("Video",imgDil);
    Mat imgDetect=getCoutours(imgDil,img,color);
    return img;
}


int main(){
   
    string path2="/home/wanan/下载/opencv小测试/TrafficLight.mp4";
    VideoCapture cap(path2);
    Mat img,imgResize,imgHSV,mask;
    Mat imgDetect;
  
    VideoWriter writer;
    bool isWriterInitialized = false;
    double fps = cap.get(CAP_PROP_FPS);
    int frameWidth, frameHeight;
    
    while(true){
        
        bool success = cap.read(img);
        if (!success || img.empty()) {
            break;
        }

        //163 179 70 237 133 255
        //82 89 151 255 126 207
        //0 42 28 209 95 255
        Scalar Redlower(163,70,133);
		Scalar Redupper(179,237,255);
        Scalar Greenlower(82,151,126);
        Scalar Greenupper(89,255,207);
        Scalar Yellowlower(0,28,95);
        Scalar Yelloupper(42,209,255);

        
        resize(img, imgResize, Size(),0.25,0.25);
        
        if (!isWriterInitialized) {
            frameWidth = imgResize.cols;
            frameHeight = imgResize.rows;
            
            writer.open("result.avi", VideoWriter::fourcc('M','J','P','G'), fps, 
                       Size(frameWidth, frameHeight));
            
            if (!writer.isOpened()) {
                writer.open("result.avi", VideoWriter::fourcc('X','V','I','D'), fps, 
                           Size(frameWidth, frameHeight));
            }
            
        }

        cvtColor(imgResize, imgHSV, COLOR_BGR2HSV);
        imgDetect=findThecolor(imgHSV,Redlower,Redupper,imgResize,"RED");
        imgDetect=findThecolor(imgHSV,Greenlower,Greenupper,imgDetect,"GREEN");
        imgDetect=findThecolor(imgHSV,Yellowlower,Yelloupper,imgDetect,"YELLOW");

        if (isWriterInitialized) {
            writer.write(imgDetect);
        }

        imshow("Video",imgDetect);
         if (waitKey(30) == 27) { 
            break;
        }
    }

    if (isWriterInitialized) {
        writer.release();
    }
    
    cap.release();
    destroyAllWindows();
    return 0;
}
