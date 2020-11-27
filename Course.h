#ifndef BOOM_COURSE_H
#define BOOM_COURSE_H
#include "List.h"

/**
 * Description:
 *
 *
 *
 *
 */
class Course {
private:
    int num_classes;
    std::shared_ptr<Node>* classes;
    std::shared_ptr<Node>* num_views;
public:

    /**
     * Description:
     *      Creates a Course
     *      todo:    This doesnt initialize pointers!
     * may throw this exceptions:
     *      std::bad_alloc() - in case of an allocation error.
     *
     */
    Course(int num_classes, int course_id);
    /**
     * Description:
     *      removes a Course
     *      todo: this doesnt Destroy Nodes.
     * may throw this exceptions:
     *      None!
     *
     */
    ~Course();

    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> getClass(int class_id);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> getViews(int class_id);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    StatusType addViews(int class_id);

};


#endif //BOOM_COURSE_H
