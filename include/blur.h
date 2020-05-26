#pragma once

#include "utils.h"

class BlurBehind{

        cv::Mat image;
    public:
        BlurBehind(const char*);
        void Gauss(int, int);
        void Show();
        void Compress();
};