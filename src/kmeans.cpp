#include "kmeans.h"

KMeans::KMeans(const char* filename){
    image = cv::imread(filename, cv::IMREAD_COLOR);
    success = true;
    if(!image.data){
        success = false;
    }
}

void KMeans::show(){
    if(!success){
        std::cout<<"Invalid file"<<std::endl;
        return;
    }
    cv::namedWindow( "Display window", cv::WINDOW_NORMAL);
    cv::imshow("Display window", image);            
    cv::waitKey(0);
    
}

Shape KMeans::shape(){
    cv::Size size = image.size();
    return {size.width, size.height};
}

void KMeans::Shred(){
    if(!success){
        return;
    }
    Shape shape = this->shape();
    double height = shape.height;
    double width = shape.width;
    double x = height / 100;
    if(height > 1000){
        int flr = ceil(x/5);
        height /= flr;
        width /= flr;
    }
    else if(height > 300){
        int flr = ceil(x/2.5);
        height /= flr;
        width /= flr;
    }
    height /= shape.height;
    width /= shape.width;
    cv::Mat target;
    cv::resize(image, target, cv::Size(), shape.height, shape.width);
}