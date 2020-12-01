#include "Node.h"

Node::Node(int new_views) : views(new_views)
{
    courses_avl = std::shared_ptr<AVLTree<AVLTree<int*>>>(new AVLTree<AVLTree<int*>>());
}

int Node::getViews() {
    return views;
}


std::shared_ptr<Node> Node::getNext() {
    return next;
}

std::shared_ptr<Node> Node::getPrev() {
    return prev;
}

void Node::setNext(std::shared_ptr<Node> new_next) {
next = new_next;
}

void Node::setPrev(std::shared_ptr<Node> new_prev) {
prev = new_prev;
}

std::shared_ptr<AVLTree<AVLTree<int*>>> Node::getAvl()
{
    return courses_avl;
}
