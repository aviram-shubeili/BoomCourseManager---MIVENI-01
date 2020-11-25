#include "Node.h"

Node::Node(int new_views) : views(new_views){}

Node::Node(int new_course_id, int new_class_id) : 
views(LECTURE_NODE), course_id(new_course_id), class_id(new_class_id){}

int Node::getViews() {
    return 0;
}

int Node::getCourseId() {
    return 0;
}

int Node::getCalssId() {
    return 0;
}

std::shared_ptr<Node> Node::getNext() {
    return std::shared_ptr<Node>();
}

std::shared_ptr<Node> Node::getPrev() {
    return std::shared_ptr<Node>();
}

std::shared_ptr<Node> Node::getRight() {
    return this->right;
}

void Node::setNext(std::shared_ptr<Node> new_next) {
next = new_next;
}

void Node::setPrev(std::shared_ptr<Node> new_prev) {
prev = new_prev;
}

void Node::setRight(std::shared_ptr<Node> new_right) {
right = new_right;
}
