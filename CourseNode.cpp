//
// Created by avira on 01/12/2020.
//

#include "CourseNode.h"

CourseNode::CourseNode(int num_classes) :
        lecture_ptrs(new std::shared_ptr<Node>[num_classes]),
        num_classes(num_classes)    {}

CourseNode::~CourseNode() {
    delete[] lecture_ptrs;
}


