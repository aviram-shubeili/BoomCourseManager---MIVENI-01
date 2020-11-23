#ifndef BOOM_NODE_H
#define BOOM_NODE_H
#include <memory>
#include "library.h"
class Node {

private:
    int views;//not view = -1
    int course_id;
    int class_id;

    std::shared_ptr<Node> classes;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;

public:

    Node(int views);
    Node(int course_id, int class_id);
    ~Node();

    int getViews();
    int getCourseId();
    int getCalssId();

    void addViews(int views);

    std::shared_ptr<Node> getNext();
    std::shared_ptr<Node> getPrev();
    std::shared_ptr<Node> getClasses();

    void setNext(Node& new_next);
    void setPrev(Node& new_prev);
    void setclass(Node& new_class);

};


#endif //BOOM_NODE_H
