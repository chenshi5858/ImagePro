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
	virtual ~ListOfRegion();
	};
}
#endif