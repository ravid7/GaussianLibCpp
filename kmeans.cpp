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
    Size size = image.size();
    return {size.width, size.height};
}