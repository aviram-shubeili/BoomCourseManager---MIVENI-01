#ifndef BOOM_NODE_H
#define BOOM_NODE_H
#include <memory>
#include "library.h"
#define LECTURE_NODE -1
/**
 * Description:
 *
 *
 */
class Node {

private:
    int views;//not view = LECTURE_NODE
    int course_id;
    int class_id;

    std::shared_ptr<Node> right;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;

public:

    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    Node(int new_views);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    Node(int new_course_id, int new_class_id);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    ~Node();

    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    int getViews();
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    int getCourseId();
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    int getCalssId();
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> getNext();
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> getPrev();
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> getRight();

    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    void setNext(Node& new_next);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    void setPrev(Node& new_prev);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    void setclass(Node& new_class);

};


#endif //BOOM_NODE_H
