# Photo Pixelator

This is a simple pixelator program that takes in any picture and either applys a blur filter, or pixelates the image all together. 

## Requirements

- This program is written in C++ and therefore requries a C++ compiler, and the ability to use make files.
- This program makes use of the Eigen template library, which is not included in this repository. This library must be installed on your machine to be included in C++ programs. For more information about the Eigen library, go here: http://eigen.tuxfamily.org/index.php?title=Main_Page
- This program makes use of the CImg library, which is not included in this repository. This library must be in the same directory as the code for this project in order to compile properly. For more information about the CImg library, go here: http://cimg.eu/index.html
- This program, because of the use of the CImg library, also requires that the ImageMagick package be installed on your machine. For more information about ImageMagick, go here: https://imagemagick.org/index.php
- The makefile assumes a linux environment, if the program is being used on a different machine, the makefile must be modified by commenting the Linux version of the FLAGS variable, and uncommenting the FLAGS for the specified environment. If there is not a version of the FLAGS variable for your specific environment, please refer to the CImg library documentation.

## How to use the program

Once the CImg library header file is in the same directory as the code given in this repository, and ImageMagick has been installed properly, the first step is to simply run the makefile. If successful, the output of the makefile is an executeable called pixel.out. This program is run as follows:

./pixel.out input.[png/jpg] output.[png/jpg] (-b) (-s <int>)

input.[png/jpg] is the name of the original image for the program to modify. The program takes in png and jpg filetypes.

out.[png/jpg] is the name of the output image. The program only outputs using png and jpg filetypes.

-b is an optional flag for blurring the image. If this option is used, the image will be blurred and not pixelated.

-s is the number of steps for the blurring/pixelating of the image. Note, pixelating starts with 3x3 pixels and increases exponentially (3x3 to 9x9 and so on). The number of steps should be provided after a space.

### Some things to be aware of

- If the -b flag is not used, the program will pixelate the image.
- If the -s flag is not used, the program will only do one step. Also, this flag assumes that the number of steps is provided as an integer.
- Both flags can be used at the same time, but the program requires there to be a space between them, and that the flag be preceded by a "-". For example, 
    "./pixel.out input.png output.jpg -b -s 10"
    and
    "./pixel.out input.png output.jpg -s 10 -b"
    would achieve the same results but, 
    "./pixel.out input.png -bs 10"
    would not work as intended