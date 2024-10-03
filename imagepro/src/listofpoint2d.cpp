/* implementation of the class ListOfPoint2D
 */

#include "image/listofpoint2d.hpp"

namespace image{

    ListOfPoint2D::ListOfPoint2D(): head(nullptr){
    }

    void ListOfPoint2D::insertFirst(int fila, int columna){
        NodePoint2D* node = new NodePoint2D(fila, columna);
        node -> setNext(head);
        head = node;
    }

    void ListOfPoint2D::insertLast(int fila, int columna){
        NodePoint2D* node = new NodePoint2D(fila, columna);
        if (head == nullptr){
            head = node;
        }else{
            NodePoint2D* ptr = head;
            while(ptr->getNext()!=nullptr){
                ptr = ptr->getNext();
            }
            ptr->setNext(node);
        }
    }
}