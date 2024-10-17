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

    // User inputs
    cout << "Total input images: ";
    cin >> totalImages;

    cout << "Image resolution (2048 or 1024): ";
    cin >> resolution;

    int imgCount = 1;

    // The loop will pass through each image and merge them with every other image

    for (int i = 1; i <= totalImages && imgCount <= 1225; i++) {
        for (int j = 1; j <= totalImages; j++) {

            // Load images

            Mat img1 = imread("images/" + std::to_string(i) + ".png");
            Mat img2 = imread("images/" + std::to_string(j) + ".png");

            // Resize images

            int height = 2048;
            int width = 2048;
            resize(img1, img1, Size(resolution, resolution), INTER_LINEAR);
            resize(img2, img2, Size(resolution, resolution), INTER_LINEAR);

            // Create the result

            Mat res; // empty pixel matrix
            double alpha = 0.55; // transparency of the image on top
            double beta = (1.0 - alpha);
            addWeighted(img1, alpha, img2, beta, 0.0, res); // blend the 2 images and output the result into res

            // Save res as png
            imwrite("outputs/Texture_" + std::to_string(i) + "+" + "Texture_"  + std::to_string(j) + ".png", res); // A PNG FILE IS BEING SAVED

            imgCount++;
        }
    }
    return 0;
}