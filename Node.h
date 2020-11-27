#ifndef BOOM_NODE_H
#define BOOM_NODE_H
#include <memory>
#include "Avl.h"

/**
 * Description:
 *
 *
 */
class Node {

private:
    int views;
    std::shared_ptr<Avl> courses_avl;

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
    Node(int views);
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
    void setNext(std::shared_ptr<Node> new_next);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    void setPrev(std::shared_ptr<Node> new_prev);    
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Avl> getAvl();

};


#endif //BOOM_NODE_H
