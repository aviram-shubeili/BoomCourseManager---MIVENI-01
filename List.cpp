#include "List.h"

List::List()
{
    head = std::shared_ptr<Node>(new Node(0));
    max = head;
}