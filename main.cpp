#include <opencv2\opencv.hpp>
#include <iostream>
using namespace cv;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int totalImages, resolution;

    cout << "==========================================================" << endl;
    cout << "1. Put all images in source images" << endl;
    cout << "2. Rename them to be numbered (ex: 1.png, 2.png, ...)" << endl;
    cout << "3. Make sure to enter the right number of total images" << endl;
    cout << "4. This will take a while lmao" << endl;
    cout << "==========================================================" << endl << endl;
    cout << "Total input images: ";
    cin >> totalImages;

    cout << "Image resolution (2048 or 1024): ";
    cin >> resolution;

    int imgCount = 1;

    for (int i = 1; i <= totalImages && imgCount <= 1225; i++) {
        for (int j = 1; j <= totalImages; j++) {
            // Load images
            Mat img1 = imread("images/" + std::to_string(i) + ".png");
            Mat img2 = imread("images/" + std::to_string(j) + ".png");


            int height = 2048;
            int width = 2048;
            resize(img1, img1, Size(resolution, resolution), INTER_LINEAR);
            resize(img2, img2, Size(resolution, resolution), INTER_LINEAR);

            Mat res;
            double alpha = 0.55;
            double beta = (1.0 - alpha);
            addWeighted(img1, alpha, img2, beta, 0.0, res);

            // Save the frame into a file
            imwrite("outputs/" + std::to_string(imgCount) + ".png", res); // A PNG FILE IS BEING SAVED

            imgCount++;
        }
    }
    return 0;
}