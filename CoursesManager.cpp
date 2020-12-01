//
// Created by avira on 23/11/2020.
//

#include "CoursesManager.h"

CoursesManager::CoursesManager() {

}

CoursesManager::~CoursesManager() {

}

StatusType CoursesManager::addCourse(int course_id, int num_classes) {
    return FAILURE;
}

StatusType CoursesManager::removeCourse(int course_id) {
    return FAILURE;
}

StatusType CoursesManager::watchClass(int course_id, int class_id, int time) {
    return FAILURE;
}

StatusType CoursesManager::timeViewed(int course_id, int class_id, int *time_viewed) {
    return FAILURE;
}

StatusType CoursesManager::getMostViewedClasses(int num_of_classes, int *courses, int *classes) {
    return FAILURE;
}
