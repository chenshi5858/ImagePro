/* implementation of the class ListOfPoint2D
 */

#include "image/listofpoint2d.hpp"

namespace image{

    ListOfPoint2D::ListOfPoint2D(): head(nullptr){
    }

    NodePoint2D* ListOfPoint2D::getHead(){
        return head;
    }

    void ListOfPoint2D::insertFirst(Point2D* punto){
        NodePoint2D* node = new NodePoint2D(punto);
        node -> setNext(head);
        head = node;
    }

    void ListOfPoint2D::insertLast(Point2D* punto){
        NodePoint2D* node = new NodePoint2D(punto);
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

    void ListOfPoint2D::print(){

    }

    ListOfPoint2D::~ListOfPoint2D(){
        
    }
}