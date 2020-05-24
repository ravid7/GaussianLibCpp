#include "kmeans.h"
// #define CV_32F  5

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
    Compress(MILD);
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
    cv::resize(image, image, cv::Size(shape.width/flr, shape.height/flr), 0, 0, \
    cv::INTER_AREA);
}


const cv::Mat KMeans::mapAndRearrange() const {
    // We do this because in order to perform kmeans algorithm,
    // img_.depth() must be of type CV_32F
    cv::Mat modifiedImg(image.total(), 3, CV_32F);
    auto modifiedImgPtr = modifiedImg.ptr<float>(0);

    // Rearrange img_ from
    // (b00,g00,r00) (b01,g01,r01) (b02,g02,r02) ...
    // (b10,g10,r10) (b11,g11,r11) (b12,g12,r12) ...
    // to
    // (r00,g00,b00)
    // (r01,g01,b01)
    // ...
    for (int row = 0; row != image.rows; ++row) {
        auto imgBeginPtr = image.ptr<uchar>(row);
        auto imgEndPtr = imgBeginPtr + image.cols * image.channels();

        while (imgBeginPtr != imgEndPtr) {
            modifiedImgPtr[0] = imgBeginPtr[2];
            modifiedImgPtr[1] = imgBeginPtr[1];
            modifiedImgPtr[2] = imgBeginPtr[0];

            modifiedImgPtr += 3;
            imgBeginPtr += 3;
        }
    }

    return modifiedImg;
}

void KMeans::doKmeans(int clusters = 3){
    cv::Mat rearranged = mapAndRearrange();
    cv::kmeans(rearranged, clusters, labels, cv::TermCriteria(cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS, \
    10, 1.0), 3, cv::KMEANS_PP_CENTERS, centers);
}

vector<color> KMeans::extractColors(){
    vector<color> container;
    if(centers.size() == cv::Size()){
        cout<<"inside"<<endl;
        doKmeans(3);
    }
    for(int row = 0; row < centers.rows; ++row){
        int r = static_cast<int>(centers.at<float>(row, 0));
        int g = static_cast<int>(centers.at<float>(row, 1));
        int b = static_cast<int>(centers.at<float>(row, 2));

        container.push_back({r, g, b});
    }

    return container;

}


const std::string color::getCommaSeparatedStr() const {
    return std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b);
}

const std::string color::getHexStr() const {
    std::stringstream ss;

    ss << std::hex << r << std::hex << g << std::hex << b;
    return std::string{"#" + ss.str()};
}
