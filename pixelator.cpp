#define cimg_display 0
#define debug

#include "CImg.h"
#include <iostream>
#include <Eigen/Dense>
using namespace cimg_library;

const int MIN_IN = 3;
const double FILTER = 9.0;

// Simple 3x3 blur filter
void blurFilter(Eigen::Vector3d *&image, int height, int width){

    Eigen::Vector3d *avg = image;
    image = new Eigen::Vector3d[height*width];

    for(unsigned int i=0;i<height;i++){
        for(unsigned int j=0;j<width;j++){

            Eigen::Vector3d pixlavg = avg[i*width+j];

            // Get information from the pixles above if possible
            if(i > 0){
                pixlavg += avg[(i-1)*width+j];
                if(j > 0) pixlavg += avg[(i-1)*width+(j-1)];
                if(j < (width-1)) pixlavg += avg[(i-1)*width+(j+1)];
            }

            //Get information from the pixels in the current row if possible              
            if(j > 0) pixlavg += avg[i*width+(j-1)];
            if(j < (width-1)) pixlavg += avg[i*width+(j+1)];

            // Get information from the pixels above if possible
            if(i < (height-1)){
                pixlavg += avg[(i+1)*width+j];
                if(j > 0) pixlavg += avg[(i+1)*width+(j-1)];
                if(j < (width-1)) pixlavg += avg[(i+1)*width+(j+1)];
            }

            pixlavg /= FILTER;
            image[i*width+j] = pixlavg;

        }
    }

    delete[] avg;

}

int main(int argc, char *argv[]){

    char *inFile, *outFile;

    // Storing all input into appropriate variables
    if(argc < MIN_IN){
        std::cout << "NOT ENOUGH ARGUMENTS!" << std::endl;
        return 1;
    }else{
        inFile = argv[1];
        outFile = argv[2];
    }

    // Read in the base image and store its contents in a vector to manipulate later
    CImg<double> input(inFile);
    Eigen::Vector3d *image = new Eigen::Vector3d[input.height()*input.width()];
    for (unsigned int i=0; i<input.height(); i++) {
        for (unsigned int j=0; j<input.width(); j++) {
	        image[i*input.width()+j][0] = input(j, i, 0);
	        image[i*input.width()+j][1] = input(j, i, 1);
	        image[i*input.width()+j][2] = input(j, i, 2);
        }
    }

    // Apply the simple blur filter
    blurFilter(image, input.height(), input.width());

#ifdef debug
    // Just for testing, apply the filter 10 times
    for(int i=0;i<10;i++){
        blurFilter(image, input.height(), input.width());
    }
#endif

    // Save the image information appropriately for output
    CImg<double> output(input.width(), input.height(), input.depth(), input.spectrum(), 0);
    for (unsigned int i=0; i<output.height(); i++) {
	    for (unsigned int j=0; j<output.width(); j++) {
	        output(j, i, 0) = image[i*output.width()+j][0];
	        output(j, i, 1) = image[i*output.width()+j][1];
	        output(j, i, 2) = image[i*output.width()+j][2];
        }
    }

    // Save the image in the appropriate format (just png, jpg for now)
    if (strstr(outFile, "png"))
	    output.save_png(outFile);
    else if (strstr(outFile, "jpg"))
	    output.save_jpeg(outFile);

    delete[] image;

    return 0;
}