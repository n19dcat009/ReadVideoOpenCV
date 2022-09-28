//Code demo Group 05

//Bao g?m th? vi?n
#include<opencv2/opencv.hpp>
#include<iostream>
//Namespace v� hi?u h�a vi?c s? d?ng cv::function();
using namespace std;
using namespace cv;
int main() {
    VideoCapture vid_capture("C:\\Users\\84395\\Music\\MEmu Music\\ReadVideoOpenCV\\bandicam 2022-09-29 00-26-48-172.mp4");
    // In thong bao loi neu luong khong hop le
    if (!vid_capture.isOpened())
    {
        cout << "Error opening video stream or file" << endl;
    }
    else
    {

        // Nh?n fps v� s? khung h�nh b?ng ph??ng th?c get () v� in

        // B?n c?ng c� th? thay th? 5 b?ng CAP_PROP_FPS, ch�ng l� ki?u li?t k�              
        int fps = vid_capture.get(5);

        cout << "Frames per second :" << fps;

        int frame_count = vid_capture.get(7);

        cout << "  Frame count :" << frame_count;

    }





    // ??c c�c khung ??n khung cu?i c�ng

    while (vid_capture.isOpened())

    {

        // Kh?i t?o ma tr?n khung

        Mat frame;



        // Kh?i t?o boolean ?? ki?m tra xem khung c� ? ?� hay kh�ng

        bool isSuccess = vid_capture.read(frame);



        // N?u c� khung, h�y hi?n th? n�

        if (isSuccess == true)

        {

            //khung hi?n th?

            imshow("Frame", frame);

        }



        // N?u kh�ng c� khung ? ?�, h�y ?�ng n� l?i

        if (isSuccess == false)

        {

            cout << "Video camera is disconnected" << endl;

            break;

        }



        //wait 20 ms between successive frames and break the loop if key q is pressed

        int key = waitKey(20);

        if (key == 'q')

        {

            cout << "q key is pressed by the user. Stopping the video" << endl;

            break;

        }





    }

    // Release the video capture object

    vid_capture.release();

    destroyAllWindows();

    return 0;

}


