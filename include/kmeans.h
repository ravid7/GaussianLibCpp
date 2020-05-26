#pragma once
#include "utils.h"



class KMeans{
    
    cv::Mat image, kmeans_data_img, labels, centers;
    void doKmeans(int clusters);
    const cv::Mat mapAndRearrange() const;
    
public:
    Shape shape();
    KMeans(const char*);
    void Compress();
    void Show();
    vector<color> extractColors();
};