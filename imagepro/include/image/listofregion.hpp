/*
 Class ListOfRegion
*/

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
	bool isWithinBounds(int x, int y, int width, int height);
	};
}
