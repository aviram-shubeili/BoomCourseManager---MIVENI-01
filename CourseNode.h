#ifndef BOOM_COURSENODE_H
#define BOOM_COURSENODE_H
#include "Node.h"

class CourseNode {
public:
    std::shared_ptr<Node>* lecture_ptrs;
    int num_classes;
    CourseNode(int num_classes);
    ~CourseNode();

};


#endif //BOOM_COURSENODE_H
