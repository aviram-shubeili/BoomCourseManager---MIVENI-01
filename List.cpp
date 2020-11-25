#include "list.h"
List::List()
{
    head = shared_ptr(new Node(0));
    max = head;
}