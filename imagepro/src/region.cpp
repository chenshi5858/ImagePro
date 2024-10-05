/* implementation of the class Region
 */
#include <iostream>
#include "image/region.hpp"

namespace image{

    Region::Region():id(-1), n_points2d(-1), region_list(nullptr){}

    Region::Region(int id, int n_pixeles, ListOfPoint2D* Lista_region): id(id), n_points2d(n_pixeles), region_list(Lista_region){};

    void Region::showRegion(){ //para esto se necesita las dimensiones de la imagen
        NodePoint2D* ptr = region_list->getHead();
        while (ptr!=nullptr){
            std::cout<<ptr->getPoint()->
        }
    }




};