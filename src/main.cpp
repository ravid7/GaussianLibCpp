#include "kmeans.h"
#include <math.h>

int main(int argc, char const *argv[])
{
    if(argc < 2){
        cout<<"Less params"<<endl;
        return 1;
    }
    KMeans kmeans(argv[1]);    
    kmeans.Compress();
    vector<color> container =  kmeans.extractColors();
    for(int i = 0; i < container.size(); i++){
        cout<<container[i].getHexStr()<<endl;
    }
    kmeans.show();
}
