/* implementation of the class StackOfNodePoint2D
 */
#include <iostream>
#include "image/stackofnodepoint2d.hpp"

namespace image{

StackofNodePoint2D::StackofNodePoint2D():head(nullptr){

}

void StackofNodePoint2D::push(NodePoint2D* node){
	node->setNext(head);
	head = node;
}

void StackofNodePoint2D::push(int x, int y){
	Point2D* punto2d = new Point2D(x, y);
    NodePoint2D* nodo2d = new NodePoint2D(punto2d);
	push(nodo2d);
}

void StackofNodePoint2D::pop(){
	if (!isEmpty()){
		NodePoint2D* ptr = head;
		head = head->getNext();
		delete ptr;
	}
}

NodePoint2D* StackofNodePoint2D::top(){
	return head;
}

bool StackofNodePoint2D::isEmpty(){
	return (head == nullptr);
}

void StackofNodePoint2D::clear(){
	while (!isEmpty()){
		pop();
	}
}

StackofNodePoint2D::~StackofNodePoint2D() {
	std::cout<<"destructor Stack"<<std::endl;
	clear();
}

};