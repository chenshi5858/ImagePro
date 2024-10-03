/* implementation of the class NodePoint2D
 */

#include "image/nodepoint2d.hpp"

namespace image {
	NodePoint2D::NodePoint2D(): row(-1), col(-1), ptr_next(nullptr){
    }

    NodePoint2D::NodePoint2D(int fila, int columna, NodePoint2D* siguiente): row(fila), col(columna), ptr_next(siguiente){
    }

    int NodePoint2D::getRow(){
        return row;
    }

    int NodePoint2D::getCol(){
        return col;
    }

    void NodePoint2D::setRow(int fila){
        row = fila; 
    }

    void NodePoint2D::setCol(int columna){
        col = columna;
    }

    void NodePoint2D::setNext(NodePoint2D *nuevo){
        ptr_next = nuevo;
    }


}
