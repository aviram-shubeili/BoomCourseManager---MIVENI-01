#include "CoursesManager.h"
using std::shared_ptr;
CoursesManager::CoursesManager() :
        course_tree(std::shared_ptr<AVLTree<CourseNode>>(new AVLTree<CourseNode>())),
        views_list(std::shared_ptr<List>(new List())),
        total_num_classes(0) {}


StatusType CoursesManager::addCourse(int course_id, int num_classes) {

    if(isInvalidCourseID(course_id) or num_classes <= 0) {
        return INVALID_INPUT;
    }
    if(course_tree->find(course_id) != nullptr) {
        return  FAILURE;
    }
    shared_ptr<CourseNode> new_course;
    try {
        new_course = shared_ptr<CourseNode>(new CourseNode(num_classes));

        course_tree->insert(course_id, new_course);

    } catch (std::bad_alloc&) {
        return ALLOCATION_ERROR;
    }
    try {
        for(int i = 0 ; i < num_classes ; i++) {
            new_course->lecture_ptrs[i] = views_list->addNewLecture(i,course_id);
        }

    } catch (std::bad_alloc&) {
        course_tree->remove(course_id);
        return ALLOCATION_ERROR;
    }
    total_num_classes += num_classes;
    return SUCCESS;
}

StatusType CoursesManager::removeCourse(int course_id) {
    if(isInvalidCourseID(course_id)) {
        return INVALID_INPUT;
    }
    shared_ptr<AVLNode<CourseNode>> course = course_tree->find(course_id);
    // course doesnt exist
    if(course == nullptr) {
        return FAILURE;
    }
    // remove from views list
    std::shared_ptr<Node>* course_lecture_ptrs = course->getData()->lecture_ptrs;
    int num_classes = course->getData()->num_classes;
    for(int i = 0 ; i< num_classes ; i++) {
        views_list->removeLectureFromNode(course_lecture_ptrs[i], i,course_id);
        course_lecture_ptrs[i] = nullptr;
    }
    // remove from course tree
    course_tree->remove(course_id);
    total_num_classes -= num_classes;
    return SUCCESS;

}

StatusType CoursesManager::watchClass(int course_id, int class_id, int time) {

    if(isInvalidCourseID(course_id) or isInvalidClassID(class_id) or time <= 0) {
        return INVALID_INPUT;
    }
    shared_ptr<AVLNode<CourseNode>> course = course_tree->find(course_id);
    if(course == nullptr) {
        return FAILURE;
    }
    if(class_id >= course->getData()->num_classes) {
        return INVALID_INPUT;
    }
    try{
        course->getData()->lecture_ptrs[class_id] =
                views_list->addViewsToLecture(course->getData()->lecture_ptrs[class_id],class_id,course_id,time);

    }
    // moving of the lecture failed
    catch (std::bad_alloc&) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType CoursesManager::timeViewed(int course_id, int class_id, int *time_viewed) {

    if(isInvalidCourseID(course_id) or isInvalidClassID(class_id)) {
        return INVALID_INPUT;
    }
    shared_ptr<AVLNode<CourseNode>> course = course_tree->find(course_id);
    if(course == nullptr) {
        return FAILURE;
    }
    if(class_id >= course->getData()->num_classes) {
        return INVALID_INPUT;
    }

    *time_viewed = views_list->getLectureViews(course->getData()->lecture_ptrs[class_id]);

    return SUCCESS;
}

StatusType CoursesManager::getMostViewedClasses(int num_of_classes, int *courses, int *classes) {
    if(num_of_classes <= 0) {
        return INVALID_INPUT;
    }
    if(num_of_classes > total_num_classes) {
        return FAILURE;
    }

    views_list->getMostViewd(num_of_classes,courses,classes);

    return SUCCESS;
}





