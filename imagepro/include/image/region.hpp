#ifndef REGION_HPP
#define REGION_HPP

#include "image/listofpoint2d.hpp"

namespace image {
    class Region {
    private:
        int id;                   // Identificador de la región
        int n_points2d;           // Número de puntos en la región
        ListOfPoint2D* region_list;  // Lista de puntos en la región
        int width;                // Ancho de la imagen
        int height;               // Alto de la imagen

    public:
        Region();
        Region(int id, int n_pixeles, ListOfPoint2D* lista_region, int width, int height);
        
        void setId(int id);
        void setNumberOfPoints(int n);
        void setRegionList(ListOfPoint2D* lista_region);
        
        int getId();
        int getNumberOfPoints();
        ListOfPoint2D* getRegionList();

        void showRegion();         // Método para mostrar la región

        virtual ~Region();         // Destructor
    };
}

#endif  // REGION_HPP
