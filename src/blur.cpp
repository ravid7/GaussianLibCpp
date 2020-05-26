#include "blur.h"

BlurBehind::BlurBehind(const char* filename){
    image = cv::imread(filename, cv::IMREAD_COLOR);
}

void BlurBehind::Gauss(int intensity, int radius){
    cv::GaussianBlur(
        image, 
        image, 
        {intensity, intensity},
        0
    );
}

void BlurBehind::Show(){
    show(image);
}

void BlurBehind::Compress(){
    compress(image, MILD);
}