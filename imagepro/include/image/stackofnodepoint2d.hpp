/*
 Class StackOfNodePoint2D
*/
#include "nodepoint2d.hpp"

namespace image {
class StackofNodePoint2D {
private:
	NodePoint2D* head;
public:
	StackofNodePoint2D();
	void push(int x, int y);
	void push(NodePoint2D* node);
	void pop();
	NodePoint2D* top();
	bool isEmpty();
	void clear();
	virtual ~StackofNodePoint2D();
};
}