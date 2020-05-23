#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgcodecs/imgcodecs.hpp>
#include <iostream>

using namespace std;
using namespace cv;

struct Shape{
    int width;
    int height;
};

class KMeans{

private:
    bool success;
    cv::Mat image;
public:
    Shape shape();
    KMeans(const char*);
    void show();
    
};