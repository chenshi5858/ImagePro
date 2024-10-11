
#include "image/listofpoint2d.hpp"
#include "image/image.hpp"
#ifndef REGION_HPP
#define REGION_HPP
namespace image{
    class Region{
        private:
        int id;
        int n_points2d;
        ListOfPoint2D* region_list;
        int height;
        int width;
        public:
        Region();
        Region(int id, int n_pixeles, ListOfPoint2D* lista_region);
        void setId(int id);
        void setNumberOfPoints(int n);
        void setRegionList(ListOfPoint2D lista_region);
        int getId();
        int getNumberOfPoints();
        ListOfPoint2D* getRegionList();
		void showRegion();
        virtual ~Region(); 
    };
};
#endif