#include "Node.h"

Node::Node(int new_views) : views(new_views){}

Node::Node(int new_course_id, int new_class_id) : 
views(CLASS_NODE), course_id(new_course_id), class_id(new_class_id){}

Node::~Node() 
{
    if(this->next != NULL)
    {
        next->setPrev(*(this->prev));    
    }
    else if(this->views == CLASS_NODE) // if it is the last class node
    {
        delete(this->prev);//Deubg : check if need to delete? or ok with shared ptr
    }
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
