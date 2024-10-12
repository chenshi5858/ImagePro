/* implementation of the class StackOfNodePoint2D
 */
#include <iostream>
#include "image/stackofnodepoint2d.hpp"

namespace image{

StackofNodePoint2D::StackofNodePoint2D() : head(nullptr) {}

void StackofNodePoint2D::push(int x, int y) {
    Point2D* point = new Point2D(x, y);
    if (point == nullptr) {
        std::cerr << "Error: No se pudo crear el punto." << std::endl;
    }
    NodePoint2D* node = new NodePoint2D(point);
    if (node == nullptr) {
        std::cerr << "Error: No se pudo crear el nodo." << std::endl;
    }
    node->setNext(head);
    head = node;
}


NodePoint2D* StackofNodePoint2D::top() {
    return head;  // Retorna el nodo de la cima de la pila
}

void StackofNodePoint2D::pop() {
    if (head) {  // Verifica que la pila no esté vacía
        NodePoint2D* temp = head;
        head = head->getNext();  // Actualiza la cabeza de la pila
        delete temp;  // Libera la memoria del nodo que fue desapilado
    }
}

bool StackofNodePoint2D::isEmpty() {
    return head == nullptr;
}

StackofNodePoint2D::~StackofNodePoint2D() {
    while (!isEmpty()) {
        pop();  // Libera todos los nodos de la pila
    }
}


};