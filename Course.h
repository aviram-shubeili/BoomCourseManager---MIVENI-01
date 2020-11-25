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
    int num_classes;
    std::shared_ptr<Node>* classes;
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
     *      return a shared pointer to the node of class_id
     * may throw this exceptions:
     *      InvalidInput - if class_id is not valid
     *
     */
    std::shared_ptr<Node> getClass(int class_id);
    /**
     * Description:
     *  // TODO: IS THIS THE RIGHT RETURN VALUE? SHOULDNT WE RETURN INT?
     * may throw this exceptions:
     *      InvalidInput - if class_id is not valid
     *
     */
    std::shared_ptr<Node> getViews(int class_id);
    /**
     * Description:
     * TODO: transfer the class node to the new updated list of views
     * may throw this exceptions:
     *      InvalidInput - if class_id is not valid or if time is not positive
     *      TODO: allocation problem?
     */
    StatusType addViews(int class_id, int time);

};


#endif //BOOM_COURSE_H
