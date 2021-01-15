CXX = c++

# Linux Version
FLAGS = -O3 -L/usr/X11R6/lib -lm -lpthread -lX11

#Solaris Version
#FLAGS = -O2 -lm -lpthread -R/usr/X11R6/lib -lrt -lnsl -lsocket

#MAC OSX Version
#FLAGS = -O2 -lm -lpthread -I/usr/X11R6/include -L/usr/X11R6/lib -lm -lpthread -lX11

# Windows with MinGW Version
#FLAGS = -O2 -lgdi32

INCLUDES = -I/usr/include/eigen3/ -I/usr/local/include/eigen3

pixel.out: pixelator.cpp
	$(CXX) $(FLAGS) $(INCLUDES) CImg.h pixelator.cpp -o pixel.out
