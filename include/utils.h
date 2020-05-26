#pragma once

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

struct color {
    int r, g, b;

    const std::string getCommaSeparatedStr() const;
    const std::string getHexStr() const;

    // some operators
    friend bool operator==(const color &lhs, const color &rhs);
    friend bool operator!=(const color &lhs, const color &rhs);
};

enum SHRINK_INTENSITY { MILD = 4, AVERAGE = 8, AGGRESSIVE = 16};

void show(const cv::Mat&);
Shape shape(const cv::Mat&);
void compress(cv::Mat&, int);