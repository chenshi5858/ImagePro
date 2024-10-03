/* implementation of the class NodeRegion
 */

#include "image/noderegion.hpp"
#include <iostream>

namespace image {

    NodeRegion::NodeRegion(): region(), next(nullptr) {
    }

    NodeRegion::NodeRegion(Region* region, NodeRegion* next): region(region), next(next) {

    }

    void NodeRegion::setRegion(Region* _region){
        region = _region;
    }

    void NodeRegion::setNext(NodeRegion* ptrnext){
        next = ptrnext;
    }

    Region* NodeRegion::getRegion(){
        return region;
    }

    NodeRegion* NodeRegion::getNext(){
        return next;
    }

}