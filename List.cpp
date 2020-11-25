#include "List.h"

List::List()
{
    head = std::shared_ptr<Node>(new Node(0));
    max = head;
}

List::~List()
{
    max = head = NULL;
}

std::shared_ptr<Node> List::removeLecture(std::shared_ptr<Node> node_lecture_ptr)
{
    if(node_lecture_ptr->getNext() != NULL)
    {
       node_lecture_ptr->getPrev()->setNext(node_lecture_ptr->getNext());
       node_lecture_ptr->getNext()->setPrev(node_lecture_ptr->getPrev());
    }
    else if(node_lecture_ptr->getPrev()->getViews() != LECTURE_NODE)//if the current node is the last one
    {

    }
}