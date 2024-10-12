
#include "image/image.hpp"
#include <iostream>
#include <string>


int main(int nargs, char** vargs){
    std::string filename("/home/edauandes/Desktop/tarea2eda/ImagePro/imagepro/images/image_1.bmp");
    std::cout << filename << std::endl;
    image::Image* im = nullptr;
    im = image::Image::readImage(filename);
    im->show();
    im->getRegions();
    return 0;
}
