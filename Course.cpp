#include "Course.h"

#include <memory>
#include "BoomExceptions.h"

Course::Course(int m, int course_id):
        num_classes(m),
        classes(new std::shared_ptr<Node>[m])
{
    for(int i=0 ; i<m ; i++) {
        classes[i] = std::make_shared<Node>(course_id,i);
    }
}

Course::~Course() {
    delete[] classes;
}


int Course::getViews(int class_id) {
    if(class_id < 0 or class_id >= num_classes) {
        throw InvalidInput();
    }
    return classes[class_id]->getViews();
}

