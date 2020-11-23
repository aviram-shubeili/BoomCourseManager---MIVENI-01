#include "Course.h"



Course::Course(int num_classes, int course_id) {
}

Course::~Course() {


std::shared_ptr<Node> Course::getClass(int class_id) {

}

std::shared_ptr<Node> Course::getViews(int class_id) {
    return std::shared_ptr<Node>();
}

StatusType Course::addViews(int class_id) {
    return FAILURE;
}
