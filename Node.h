#ifndef BOOM_NODE_H
#define BOOM_NODE_H
#include <memory>
#include "library.h"
#define CLASS_NODE -1
/**
 * Description:
 *
 *
 */
class Node {

private:
    int views;//not view = CLASS_NODE
    int course_id;
    int class_id;

    Node* classes;
    Node* next;
    Node* prev;

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
    void addViews(int views);

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
    std::shared_ptr<Node> getClasses();

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
