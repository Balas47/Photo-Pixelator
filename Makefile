CXX = c++
FLAGS = -O3 -L/usr/X11R6/lib -lm -lpthread -lX11

INCLUDES = -I/usr/include/eigen3/ -I/usr/local/include/eigen3

pixel.out: pixelator.cpp
	$(CXX) $(FLAGS) $(INCLUDES) CImg.h pixelator.cpp -o pixel.out
