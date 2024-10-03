/*
 Class NodeRegion
*/

#include "region.hpp"

namespace image {
    class NodeRegion{
    private:
    Region* region;
    NodeRegion* next;
    public:
	NodeRegion();
    NodeRegion(Region* region, NodeRegion* next = nullptr); 
    Region* getRegion();
    void setRegion(Region*);
    void setNext(NodeRegion*);
    NodeRegion* getNext();
    };
}