/* implementation of the class NodePoint2D
 */

#include "image/nodepoint2d.hpp"

namespace image {
	NodePoint2D::NodePoint2D(): point(), ptr_next(nullptr){
    }

    NodePoint2D::NodePoint2D(Point2D* punto, NodePoint2D* siguiente): point(punto), ptr_next(siguiente){
    }

    Point2D* NodePoint2D::getPoint(){
        return point;
    }

    NodePoint2D* NodePoint2D::getNext(){
        return ptr_next;
    }

    void NodePoint2D::setPoint(Point2D* punto){
        point = punto;
    }

    void NodePoint2D::setNext(NodePoint2D *nuevo){
        ptr_next = nuevo;
    }
}
