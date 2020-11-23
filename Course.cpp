#include "Course.h"



Course::Course(int num_classes, int course_id) {
classes = new std::shared_ptr<Node>[num_classes];
num_views = new std::shared_ptr<Node>[num_classes];
}

Course::~Course() {
    delete[] classes;
    delete[] num_views;
}

std::shared_ptr<Node> Course::getClass(int class_id) {
    return std::shared_ptr<Node>();
}

std::shared_ptr<Node> Course::getViews(int class_id) {
    return std::shared_ptr<Node>();
}

StatusType Course::addViews(int class_id) {
    return FAILURE;
}
