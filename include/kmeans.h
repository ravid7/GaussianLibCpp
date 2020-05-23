#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;

struct Shape{
    int width;
    int height;
};


class KMeans{

private:
    bool success;
    cv::Mat image;
    enum SHRINK_INTENSITY { MILD = 4, AVERAGE = 8, AGGRESSIVE = 16};
    void Compress(int INTENSITY);
public:
    Shape shape();
    KMeans(const char*);
    void show();
    void Compress();
};