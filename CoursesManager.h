#ifndef BOOM_COURSESMANAGER_H
#define BOOM_COURSESMANAGER_H
#include "List.h"
#include "CourseNode.h"
class CoursesManager {
    std::shared_ptr<AVLTree<CourseNode>> course_tree;
    std::shared_ptr<List> views_list;
    unsigned int total_num_classes;
public:

    CoursesManager();

    ~CoursesManager() = default;

    StatusType addCourse(int course_id, int num_classes);

    StatusType removeCourse(int course_id);

    StatusType watchClass(int course_id, int class_id, int time);

    StatusType timeViewed(int course_id, int class_id, int* time_viewed);

    StatusType getMostViewedClasses(int num_of_classes, int* courses, int* classes);


};


#endif //BOOM_COURSESMANAGER_H
