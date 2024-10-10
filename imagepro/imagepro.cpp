
#include "image.hpp"
#include <iostream>
#include <string>


int main(int nargs, char** vargs){
    std::string filename("C:/Users/chens/OneDrive/Escritorio/tarea2_eda/imagepro/images/image_1.bmp");
    std::cout << filename << std::endl;
    image::Image* im = nullptr;
    im = image::Image::readImage(filename);
    im->show();
    return 0;
}
