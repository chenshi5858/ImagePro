/*
 Class ListOfPoint2D
*/
#ifndef LISTOFPOINT2D_HPP
#define LISTOFPOINT2D_HPP
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
	void print();
	virtual ~ListOfPoint2D();
	};
}
#endif