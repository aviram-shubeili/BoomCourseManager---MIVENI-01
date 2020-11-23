#ifndef BOOM_COURSE_H
#define BOOM_COURSE_H
#include "Node.h"

/**
 * Description:
 *
 *
 *
 *
 */
class Course {
private:
    std::shared_ptr<Node>* classes;
    std::shared_ptr<Node>* num_views;
public:

    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    Course(int num_classes, int course_id);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
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
