#ifndef BOOM_COURSESMANAGER_H
#define BOOM_COURSESMANAGER_H
#include "Auxiliaries.h"
#include "AVLTree.h"
#include "List.h"

class CoursesManager {


public:
    CoursesManager();
    ~CoursesManager();

    StatusType addCourse(int course_id, int num_classes);

    StatusType removeCourse(int course_id);

    StatusType watchClass(int course_id, int class_id, int time);

    StatusType timeViewed(int course_id, int class_id,int* time_viewed);


    StatusType getMostViewedClasses(int num_of_classes, int* courses,int* classes);


};


#endif //BOOM_COURSESMANAGER_H
