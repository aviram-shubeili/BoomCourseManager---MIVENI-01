#ifndef BOOM_COURSE_H
#define BOOM_COURSE_H
#include "Node.h"
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
public:

    /**
     * Description:
     *      Creates a Course
     * may throw this exceptions:
     *      std::bad_alloc() - in case of an allocation error.
     *
     */
    Course(int m, int course_id);
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
    int getViews(int class_id);

};


#endif //BOOM_COURSE_H
