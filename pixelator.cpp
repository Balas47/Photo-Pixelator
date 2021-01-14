#define cimg_display 0

#include "CImg.h"
#include <iostream>
#include <Eigen/Dense>
using namespace cimg_library;

int main(int argc, char *argv[]){

    // Read in the base image and store its contents in a vector to manipulate later
    CImg<double> input(argv[1]);
    Eigen::Vector3d *image = new Eigen::Vector3d[input.height()*input.width()];
    for (unsigned int i=0; i<input.height(); i++) {
        for (unsigned int j=0; j<input.width(); j++) {
	        image[i*input.width()+j][0] = input(j, i, 0);
	        image[i*input.width()+j][1] = input(j, i, 1);
	        image[i*input.width()+j][2] = input(j, i, 2);
        }
    }

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
    if (strstr(argv[2], "png"))
	    output.save_png(argv[2]);
    else if (strstr(argv[2], "jpg"))
	    output.save_jpeg(argv[2]);

    delete[] image;

    return 0;
}