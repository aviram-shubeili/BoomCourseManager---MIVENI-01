#include "Course.h"
#include "BoomExceptions.h"

Course::Course(int num_classes, int course_id):
        num_classes(num_classes),
        classes(new std::shared_ptr<Node>[num_classes])
{
}

Course::~Course() {
    delete[] classes;
}


std::shared_ptr<Node> Course::getClass(int class_id) {
    if(class_id < 0 or class_id >= num_classes) {
        throw InvalidInput();
    }
    return classes[class_id];
}

std::shared_ptr<Node> Course::getViews(int class_id) {
    if(class_id < 0 or class_id >= num_classes) {
        throw InvalidInput();
    }
    return num_views[class_id];
//    return num_views[class_id]->getViews();
}

StatusType Course::addViews(int class_id, int time) {
    if(class_id < 0 or class_id >= num_classes or time <= 0) {
        throw InvalidInput();
    }
    classes[class_id]->addViews(time);
    return SUCCESS;
    // TODO:
    // num_views[class_id]->transferToNewList(classes[class_id])
}
