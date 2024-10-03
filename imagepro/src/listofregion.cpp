/* implementation of the class ListOfRegion
 */
#include "image/listofregion.hpp"

namespace image{
    ListOfRegion::ListOfRegion():head(nullptr){
    }

    void ListOfRegion::insertFirst(Region* region){
        NodeRegion* node = new NodeRegion(region);
        node -> setNext(head);
        head = node;
    }

    void ListOfRegion::insertLast(Region* region){
        NodeRegion* node = new NodeRegion(region);
        if (head == nullptr){
            head = node;
        }else{
            NodeRegion* ptr = head;
            while(ptr->getNext()!=nullptr){
                ptr = ptr->getNext();
            }
            ptr->setNext(node);
    }
    }
}