/* implementation of the class Region
 */
#include <iostream>
#include "image/region.hpp"

namespace image{

    Region::Region():id(-1), n_points2d(-1), region_list(nullptr){}

    Region::Region(int _id, int _n_pixeles, ListOfPoint2D* _region_list, int _width, int _height): id(_id), n_points2d(_n_pixeles), region_list(_region_list), width(_width), height(_height) {}

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
        char** regionMatrix = new char[height];

        for (int i = 0; i < height; i++) {
            regionMatrix[i] = new char[width];
            for (int j = 0; j < width; j++) {
                regionMatrix[i][j] = ' '; 
            }
        }

        NodePoint2D current = region_list->getHead();
        while (current != nullptr) {
            Point2D* point = current->getPoint();
            int x = point->getX();
            int y = point->getY();
            regionMatrix[y][x] = '';
            current = current->getNext();
        }

        std::cout << "Región ID: " << id << " | Número de puntos: " << n_points2d << std::endl;
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