#include"library.h"
#include"CoursesManager.h"
void *Init() {
    CoursesManager *DS;
    try {
        DS = new CoursesManager ();
    } catch (std::bad_alloc&) {
        return nullptr;
    }
    return (void*)DS;
}
StatusType AddCourse(void *DS, int courseID, int numOfClasses) {
    if(DS == NULL) return INVALID_INPUT;
    return (StatusType) (((CoursesManager *)DS)-> addCourse(courseID, numOfClasses));
}

StatusType RemoveCourse(void *DS, int courseID) {
    if(DS == NULL) return INVALID_INPUT;

    return (StatusType) ((CoursesManager*) DS)-> removeCourse(courseID);
}

StatusType WatchClass(void *DS, int courseID, int classID, int time) {
    if(DS == NULL) return INVALID_INPUT;

    return (StatusType)((CoursesManager*) DS)-> watchClass(courseID, classID, time);
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed) {
    if(DS == NULL) return INVALID_INPUT;

    return (StatusType)((CoursesManager*) DS)-> timeViewed(courseID, classID, timeViewed);
}

StatusType GetMostViewedClasses(void *DS, int numOfClasses, int *courses, int *classes) {
    if(DS == NULL) return INVALID_INPUT;

    return (StatusType)((CoursesManager*) DS)-> getMostViewedClasses(numOfClasses,courses,classes);
}

void Quit(void **DS) {
    if(*DS != NULL) {
        delete ((CoursesManager*) *DS);
    }
    *DS = NULL;
}
