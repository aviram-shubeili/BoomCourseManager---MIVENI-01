#include "Node.h"

Node::Node(int views) {

}

Node::Node(int course_id, int class_id) {

}

Node::~Node() {

}

int Node::getViews() {
    return 0;
}

int Node::getCourseId() {
    return 0;
}

int Node::getCalssId() {
    return 0;
}

void Node::addViews(int views) {

}

std::shared_ptr<Node> Node::getNext() {
    return std::shared_ptr<Node>();
}

std::shared_ptr<Node> Node::getPrev() {
    return std::shared_ptr<Node>();
}

std::shared_ptr<Node> Node::getClasses() {
    return std::shared_ptr<Node>();
}

void Node::setNext(Node &new_next) {

}

void Node::setPrev(Node &new_prev) {

}

void Node::setclass(Node &new_class) {

}
