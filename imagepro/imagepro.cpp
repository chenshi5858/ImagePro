
#include "image/image.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

int main(int nargs, char** vargs){

    std::cout<<"Bienvenido a ImagePro"<<std::endl;

    std::string comando;
    
    int id = 1;
    std::vector <std::string> imagenes; 
    while (1){
        std::cout<<"Ingrese comando: ";
        std::getline(std::cin, comando);
        std::istringstream iss(comando);
        std::string nombre_comando;
        std::string argumento;
        iss>>nombre_comando;
        iss>>argumento;
        if (nombre_comando == "read"){
            std::string filename = "/home/pbn/Desktop/tarea2eda/ImagePro/imagepro/images/"+argumento;
            imagenes.push_back(filename);
            std::cout << "im"+std::to_string(id) + " = " <<filename << std::endl;
            id++;
        }
        else if(nombre_comando == "show"){
            std::regex pattern("im(\\d+)");
            std::smatch match;
            if (std::regex_match(argumento, match, pattern)){
                image::Image* im = nullptr;
                int id_imagen = std::stoi(match[1]);
                im = image::Image::readImage(imagenes[id_imagen-1]);
                im->show();
            }else {
                std::cout<<"Imagen no encontrada"<<std::endl;
            }
        }
        else if(nombre_comando == "showRegion"){
            std::regex pattern("im(\\d+)");
            std::smatch match;
            if (std::regex_match(argumento, match, pattern)){
                std::string id_region;
                iss>>id_region;
                int num_region = std::stoi(id_region);
                image::Image* im = nullptr;
                int id_imagen = std::stoi(match[1]);
                im = image::Image::readImage(imagenes[id_imagen-1]);
                image::NodeRegion* nodo_region = new image::NodeRegion;
                nodo_region = im->getRegions()->getHead();
                while(nodo_region!=nullptr){
                    if(nodo_region->getRegion()->getId()==num_region){
                        nodo_region->getRegion()->showRegion();
                        break;
                    }else{
                        nodo_region = nodo_region->getNext();
                    }
                }
                if(nodo_region==nullptr){
                    std::cout<<"Region "+id_region+" no encontrada"<<std::endl;
                }
            }else {
                std::cout<<"Imagen no encontrada"<<std::endl;
            }
        }else if(nombre_comando == "getRegions"){
            std::regex pattern("im(\\d+)");
            std::smatch match;
            if (std::regex_match(argumento, match, pattern)){
                image::Image* im = nullptr;
                int id_imagen = std::stoi(match[1]);
                im = image::Image::readImage(imagenes[id_imagen-1]);
                image::ListOfRegion* regiones = im->getRegions(); 
                int num_regiones = regiones->size(); 
                std::cout << "La imagen de im" << id_imagen << " tienes " << num_regiones << " regiones" << std::endl;
                image::NodeRegion* nodo_region = regiones->getHead();
                int contador_region = 1;
                while(nodo_region != nullptr){
                    std::cout << "Region " << contador_region << " -> size " << nodo_region->getRegion()->size() << std::endl;
                    nodo_region = nodo_region->getNext();
                    contador_region++;
                }
            }else {
                std::cout << "Imagen no encontrada" << std::endl;
            }
        }else if (comando=="exit"){
            std::cout<<"Saliendo del programa..."<<std::endl;
            break;
        }else{
            std::cout<<"Comando no reconocido"<<std::endl;
        }
    }

    return 0;
}
