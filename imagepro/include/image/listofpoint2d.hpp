/*
 Class ListOfPoint2D
*/
#include "image/nodepoint2d.hpp"

namespace image {
	class ListOfPoint2D{
	private:
	NodePoint2D* head;		
	public:		
	ListOfPoint2D();
	void insertFirst(int fila, int columna);
	void insertLast(int fila, int columna);
	void removeFirst();
	void remove(int fila, int columna);
	void removeAll();
	NodePoint2D* find(int fila, int columna);
	void print();
	virtual ~ListOfPoint2D();
	};
}
