#ifndef BOOM_COURSE_H
#define BOOM_COURSE_H
#include "Node.h"

class Course {
private:
    std::shared_ptr<Node>* classes;
    std::shared_ptr<Node>* num_views;
public:
    Course(int num_classes, int course_id);
    ~Course();

    std::shared_ptr<Node> getClass(int class_id);
    std::shared_ptr<Node> getViews(int class_id);
    StatusType addViews(int class_id);

};


#endif //BOOM_COURSE_H
