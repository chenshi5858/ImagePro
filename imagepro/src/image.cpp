#include "image/image.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stack>
#include "image/listofregion.hpp"
#include "image/region.hpp"
#include "image/nodepoint2d.hpp"
#include "image/listofpoint2d.hpp"
#include "image/noderegion.hpp"
#include "image/point2D.hpp"

namespace image{

    Image::Image(): width(0), height(0), th_value(120), data(nullptr){

    }

    Image::Image(int w, int h): width(w), height(h), th_value(120),  data(nullptr){

    }

    Image::Image(int w, int h, uchar* _data): width(w), height(h), th_value(120), data(_data){
       threshold();
    }

    void Image::threshold(){
        if (data != nullptr) {
            for(int i = 0; i < height*width; i++){            
                if (static_cast<int>(data[i]) < th_value){
                    data[i] = static_cast<char>(0);
                }
                else{
                    data[i] = static_cast<char>(1);                    
                }
            }
        }
    }
    int Image::getValue(int row, int col){
        int pos = row*width + col;
        return static_cast<int>(data[pos]);
    }

    void Image::show(){
        std::cout << "----------------------" << std::endl;
        std::cout << "size [ (w: " << width << ") x   ( h:" << height << ")]" <<  std::endl;        
        std::cout << "---------------------" << std::endl;
        for(int i = 0 ; i < height ; i++ ){
            for(int j = 0; j < width; j++ ){
                //std::cout<< getValue(i,j) << " "; 
                if (getValue(i,j) == 0) {
                    std::cout<<" ";
                }
                else{
                    std::cout<<"*";
                }
            }
            std::cout<<std::endl;
        }
    }

    Image::~Image(){

    }

    Image* Image::readImage(std::string &path){

        Image* im = nullptr;
        std::ifstream fin(path, std::ios::binary);
        char info[54];
        // read the 54-byte header
        fin.read(info, 54);
        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];
        short int planes = *(short int*)&info[26];
        short int bits = *(short int*)&info[28];
        int imagesize = *(int*)&info[34];
        int numcolors = *(int*)&info[46];
        assert(info[0]=='B' && info[1] =='M');
        assert(bits == 8);
        // std::cout<< "planes " << planes << std::endl;
        // std::cout<< "bits " << bits << std::endl;
        // std::cout<< "imagesize " << imagesize << std::endl;
        // std::cout<< "numcolors " << numcolors << std::endl;
        // std::cout<< info[0] << info[1] << std::endl;
        //reading colortable
        char  colors[numcolors*4];
        fin.read(colors, numcolors*4);        
        if (imagesize == height * width) {            
            char* data = new char[imagesize];
            //read the pixel values
            fin.read(data, imagesize); 
            fin.close();
            char* ordered_data = new char[imagesize];
            //copy data in in a proper order            
            std::cout<< "----------------" <<std::endl;
            for(int i = 0; i < height ; i++){
                std::memcpy(ordered_data + width*i, data + width*(height - 1 - i ), width);
            }                    
            delete[]  data;            
            im = new Image(width, height, reinterpret_cast<uchar*>(ordered_data));        
        }
        assert(im != nullptr);
        return im;
    }

    bool Image::isWithinBounds(int x, int y, int width, int height) {
        return x >= 0 && y >= 0 && x < width && y < height;
    }

    ListOfRegion* Image::getRegions() {
        ListOfRegion* regions = new ListOfRegion;
        bool* visited = new bool[width * height];

        // Inicializa el arreglo de visitados en falso
        for (int i = 0; i < width * height; i++) {
            visited[i] = false;
        }

        int regionId = 1;  
        int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (getValue(y, x) == 1 && !visited[y * width + x]) {
                    ListOfPoint2D* regionPoints = new ListOfPoint2D();
                    int regionSize = 0;

                    // Usar std::stack para la búsqueda en profundidad
                    std::stack<NodePoint2D*> stack;
                    stack.push(new NodePoint2D(new Point2D(x, y)));  // Agregamos el primer nodo

                    visited[y * width + x] = true;

                    // Búsqueda en profundidad (DFS) usando la pila estándar
                    while (!stack.empty()) {
                        NodePoint2D* node = stack.top();
                        stack.pop();

                        if (node != nullptr && node->getPoint() != nullptr) {
                            int currentX = node->getPoint()->getX();
                            int currentY = node->getPoint()->getY();

                            // Agregamos el punto actual a la lista de puntos de la región
                            regionPoints->insertLast(new Point2D(currentX, currentY));
                            regionSize++;

                            // Recorremos los vecinos en las 8 direcciones
                            for (int i = 0; i < 8; i++) {
                                int nx = currentX + dx[i];
                                int ny = currentY + dy[i];

                                if (isWithinBounds(nx, ny, width, height) &&
                                    getValue(ny, nx) == 1 && !visited[ny * width + nx]) {
                                    
                                    stack.push(new NodePoint2D(new Point2D(nx, ny)));  // Agregamos el nuevo nodo a la pila
                                    visited[ny * width + nx] = true;  // Lo marcamos como visitado
                                }
                            }

                            delete node;  // Liberamos memoria del nodo procesado
                        }
                    }

                    // Crear la región y agregarla a la lista de regiones
                    Region* region = new Region(regionId++, regionSize, regionPoints, width, height);
                    regions->insertLast(region);
                }
            }
        }

        // Liberamos memoria del arreglo de visitados
        delete[] visited;

        // Devolvemos la lista de regiones
        return regions;
    }





    


    // ListOfRegion* Image::getRegions(){
    //     int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    //     int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    //     StackofNodePoint2D s;
    //     ListOfRegion regiones;
    //     s.push(0, 0); //elegimos un punto inicial arbitrario
    //     bool visited[height][width];
    //     for (int i = 0, i < height; i++){
    //         for (int j = 0; j < width; j++){
    //             visited[i][j] = false;
    //         }
    //     }
    //     visited[0][0] = true;
    //     int x_actual, y_actual, x_nuevo, y_nuevo;
    //     bool wasVisited;
        
    //     while (!s.isEmpty()){
    //         x_actual = s.top()->getPoint()->getX();
    //         y_actual = s.top()->getPoint()->getY();
    //         s.pop();
    //         if(getvalue(x_actual,y_actual)=='1'){
    //             Point2D* agregar_punto2d = new Point2D;
    //             NodePoint2D* agregar_nodo2d = new NodePoint2D;
    //             ListOfPoint2D* agregar_lista2d = new ListOfPoint2D;
    //             NodeRegion* agregar_region = new NodeRegion;

    //             agregar_punto2d->setX(x_actual);
    //             agregar_punto2d->setX(y_actual);
    //             agregar_nodo2d->setPoint(agregar_punto2d);
    //             agregar_lista2d->
    //         }
    //         for (int i = 0; i < 8; i++){
    //             x_nuevo = x_actual + dx[i];
    //             y_nuevo = y_actual + dy[i];
    //             wasVisited = visited[x_nuevo][y_nuevo];
    //             if (!wasVisited){
    //                 s.push(x_nuevo, y_nuevo);
    //                 visited[x_nuevo][y_nuevo] = true;
    //             }
    //         }
            
    //     }

    // }

}

