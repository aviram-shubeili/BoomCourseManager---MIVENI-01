#ifndef LIST_H
#define LIST_H
#include "Node.h"

/**
 * Description:
 *
 *
 *
 *
 */
class List {
private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> max;
public:
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    List();
        /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    ~List();
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    void removeLecture(std::shared_ptr<Node> node_lecture_ptr);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> addLecture(int new_course_id, int new_class_id);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> moveLecture(std::shared_ptr<Node> node_lecture_ptr, int time);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    int getLectureViews(std::shared_ptr<Node> node_lecture_ptr);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    void getMostViewd(int numOfClasses, int* courses, int* classes);

};
#endif
