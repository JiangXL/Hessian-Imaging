#include <fstream>
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
//#include <opencv2/cudaarithm.hpp>
#include "hessian.h"

using namespace cv;
using namespace std;

/******************************************************************************
 * ./hessien <source-folder> <output-folder>
 * | Version | Commit
 * |   0.1   | 20190819 @H.F. 
 *****************************************************************************/

int main(int argc, char** argv)
{   
    //Glob tiff stack from given folder
    vector<String> filenames;
    vector<Mat> imgs;
    String src_folder = argv[1];
    String out_folder = argv[2];
    String tif_stack = "*.ome.tif";
    glob(src_folder + tif_stack, filenames);
    int window = 49;
    double kernel[window];
    int total_img = 0;
    vector<Mat> result;
    int rows, cols = 0;
    int img_type =0;

    if ( filenames.size() ==0 ){
        cout << "Not tif stack data" << endl;
    }else{
        cout << "Reading following img:" << endl;
    }

    for (size_t i = 0; i < filenames.size(); ++i)
    {
        cout << filenames[i] << endl;
        imreadmulti(filenames[i], imgs, -1);//IMREAD_ANYDEPTH);
    }

    total_img = imgs.size();
    rows = imgs[0].rows; cols = imgs[0].cols;
    img_type = imgs[1].type();
    cout << "Total number of read image: " << imgs.size() << endl;
    cout << "Image size is "<<rows<<"x" << cols <<", Type: "<<img_type<<endl;
    genkernel(kernel, window); // Generate convolution kernel

    // Process the filter
    cout <<"Procesing image "  << endl;
    for (int i=window/2; i<total_img-window/2; i++)
    {   
        if( i%100==0) cout << i <<" ";
        Mat _result = Mat(rows, cols, img_type);
        for(int j=0; j<window; j++){
           _result = _result + kernel[j]*imgs[i+(j-window/2)];
        }
        result.push_back(_result);
    }
    cout << "Processing DONE" << endl;

    // Save images to disk
    cout << "Saving images" << endl;
    for( int i=0; i< result.size(); i++)
    {
        char buffer[10];
        sprintf(buffer, "%04d.tiff", i);
        String title = buffer; 
        imwrite(out_folder+title, result[i]);
        cout <<".";
    }
    cout << "Save Image DONE!" << endl;
}

// Generate convolution kernel
void genkernel(double _kernel[],int n)
{
    for(int i=0; i<n; i++)
    {
        _kernel[i] = 1.0/n;
    }
}
