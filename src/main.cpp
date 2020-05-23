#include "kmeans.h"
#include <math.h>

int main(int argc, char const *argv[])
{
    if(argc < 2){
        cout<<"Less params"<<endl;
        return 1;
    }
    KMeans kmeans(argv[1]);    
    Shape shape = kmeans.shape();
    cout<<shape.width<<" "<<shape.height<<endl;
    kmeans.Compress();
    shape = kmeans.shape();
    cout<<shape.width<<" "<<shape.height<<endl;
    kmeans.show();
}
