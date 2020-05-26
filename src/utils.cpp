#include "utils.h"

const std::string color::getCommaSeparatedStr() const {
    return std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b);
}

const std::string color::getHexStr() const {
    std::stringstream ss;
    ss << std::hex << r << std::hex << g << std::hex << b;
    return std::string{"#" + ss.str()};
}

void show(const cv::Mat& image){
    cv::namedWindow( "Display window", cv::WINDOW_NORMAL);
    cv::imshow("Display window", image);            
    cv::waitKey(0);
}

Shape shape(const cv::Mat& image) {
    cv::Size size = image.size();
    return {size.width, size.height};
}

void compress(cv::Mat& image, int intensity){
    Shape dimen = shape(image);
    double height = dimen.height;
    double width = dimen.width;
    double x = height / 100;
    int flr = 0;
    if(height > 1000){
        flr = ceil(x/5);
        height /= flr;
        width /= flr;
    }
    else if(height > 300){
        flr = ceil(x/2.5);
        height /= flr;
        width /= flr;
    }
    else{
        return;
    }
    flr *= 1 + (intensity/10);
    cv::resize(image, image, cv::Size(dimen.width/flr, dimen.height/flr), 0, 0, \
    cv::INTER_AREA);
}
