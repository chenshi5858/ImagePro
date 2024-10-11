/*
 Class ListOfRegion
*/

#ifndef LISTOFREGION_HPP
#define LISTOFREGION_HPP
#include "image/noderegion.hpp"


namespace image {
	class ListOfRegion{
	private:
	NodeRegion *head;		
	public:
	ListOfRegion();
	void insertFirst(Region* region);
	void insertLast(Region* region);
	void removeFirst();
	void remove(Region* region);
	void removeAll();
	NodeRegion* find(Region* region);
	void print();
	virtual ~ListOfRegion();
	};
}
#endif