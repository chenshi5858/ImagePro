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

    NodeRegion* ListOfRegion::getHead(){
        return head;
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

    int ListOfRegion::size() {
        int count = 0;
        NodeRegion* current = head;
        while (current != nullptr) {
            count++;
            current = current->getNext();
        }
        return count;
    }


    ListOfRegion::~ListOfRegion(){
        
    }
}