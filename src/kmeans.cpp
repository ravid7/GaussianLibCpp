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

void KMeans::Compress(){
    Compress(AGGRESSIVE);
}

void KMeans::Compress(int intensity){
    if(!success){
        std::cout<<"Invalid file"<<std::endl;
        return;
    }
    Shape shape = this->shape();
    double height = shape.height;
    double width = shape.width;
    double x = height / 100;
    int flr;
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
    flr *= 1 + (intensity/10);
    cv::resize(image, image, cv::Size(shape.width/flr, shape.height/flr), 0, 0, cv::INTER_AREA);
}