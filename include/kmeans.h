#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;

struct color {
    int r, g, b;

    const std::string getCommaSeparatedStr() const;
    const std::string getHexStr() const;

    // some operators
    friend bool operator==(const color &lhs, const color &rhs);
    friend bool operator!=(const color &lhs, const color &rhs);
};


struct Shape{
    int width;
    int height;
};


class KMeans{

private:
    bool success;
    cv::Mat image, kmeans_data_img, labels, centers;
    enum SHRINK_INTENSITY { MILD = 4, AVERAGE = 8, AGGRESSIVE = 16};
    void Compress(int INTENSITY);
    void doKmeans(int clusters);
    const cv::Mat mapAndRearrange() const;
public:
    Shape shape();
    KMeans(const char*);
    void show();
    void Compress();
    vector<color> extractColors();
};