#ifndef Course
#define Course
#include "Node.h"
#include "library.h"

class Course{
    private:
    std::shared_ptr<Node_classes>* classes;
    std::shared_ptr<Node_views>* num_views;
    public:
    Course(int num_classes, int course_id);
    ~Course();

    std::shared_ptr<Node_classes> getClass(int class_id);
    std::shared_ptr<Node_views> getViews(int class_id);
    StatusType addViews(int class_id);
    
}

#endif