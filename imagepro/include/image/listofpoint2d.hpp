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
	NodePoint2D* getHead();
	void insertFirst(Point2D* punto);
	void insertLast(Point2D* punto);
	void removeFirst();
	void remove(Point2D* punto);
	void removeAll();
	NodePoint2D* find(Point2D* punto);
	void print();
	virtual ~ListOfPoint2D();
	};
}
