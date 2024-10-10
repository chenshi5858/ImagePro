/* implementation of the class Region
 */
#include <iostream>
#include "image/region.hpp"

namespace image{

    Region::Region():id(-1), n_points2d(-1), region_list(nullptr){}

    Region::Region(int id, int n_pixeles, ListOfPoint2D* Lista_region): id(id), n_points2d(n_pixeles), region_list(Lista_region){};

    void Region::setId(int _id) {
        id = _id;
    }

    void Region::setNumberOfPoints(int n) {
        n_points2d = n;
    }

    void Region::setRegionList(ListOfPoint2D* _region_list) {
        region_list = _region_list;
    }

    void Region::setImage(Image* img) {
        image = img;
    }

    int Region::getId() {
        return id;
    }

    int Region::getNumberOfPoints() {
        return n_points2d;
    }

    ListOfPoint2D* Region::getRegionList() {
        return region_list;
    }

    Image* Region::getImage() {
        return image;
    }

    Region::~Region() {
        if (region_list != nullptr) {
            delete region_list;
            region_list = nullptr;
        }
    }

    void Region::showRegion() {
        int width = image->getWidth();
        int height = image->getHeight();
        char** regionMatrix = new char*[height];
        
        for (int i = 0; i < height; i++) {
            regionMatrix[i] = new char[width];
            std::memset(regionMatrix[i], '0', width); 
        }

        NodePoint2D* actual = region_list->getHead();
        while (actual != nullptr) {
            Point2D* point = actual->getPoint();
            int x = point->getX();
            int y = point->getY();
            regionMatrix[y][x] = id;
            actual = actual->getNext();
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << regionMatrix[i][j];
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < height; i++) {
            delete[] regionMatrix[i];
        }
        delete[] regionMatrix;
    }

};