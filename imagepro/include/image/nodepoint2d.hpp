/*
 Class NodePoint2D
*/
#include "point2D.hpp"

namespace image {
	class NodePoint2D{
	private:
	Point2D* point;
	NodePoint2D* ptr_next;		
	public:
	NodePoint2D();
	NodePoint2D(Point2D* punto, NodePoint2D* siguiente=nullptr);
	Point2D* getPoint();
	NodePoint2D* getNext();
	void setPoint(Point2D* punto);
	void setNext(NodePoint2D *nuevo);
	};
}

// namespace image {
// 	class NodePoint2D{
// 	private:
// 	int row;
// 	int col;
// 	NodePoint2D* ptr_next;		
// 	public:
// 	NodePoint2D();
// 	NodePoint2D(int fila, int columna, NodePoint2D* siguiente=nullptr);
// 	int getRow();
// 	int getCol();
// 	NodePoint2D* getNext();
// 	void setRow(int fila);
// 	void setCol(int columna);
// 	void setNext(NodePoint2D *nuevo);
// 	};
// }
