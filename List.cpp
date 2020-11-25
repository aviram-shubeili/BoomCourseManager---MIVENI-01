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
    if(next != NULL)
    {
        prev = 
    }
    else if(prev-> views != LECTURE_NODE)//if the current node is the last one
    {

    }
}