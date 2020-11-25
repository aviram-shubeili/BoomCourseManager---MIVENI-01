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

void List::removeLecture(std::shared_ptr<Node> node_lecture_ptr)
{
    std::shared_ptr<Node> prev = node_lecture_ptr->getPrev();
    std::shared_ptr<Node> next = node_lecture_ptr->getNext();

    disconnectLecture(next,prev);
    removeViews(next,prev);

}

void List::removeViews(std::shared_ptr<Node> next, std::shared_ptr<Node> prev)
{
    //the node removed was the last one in the views list
    if(next == NULL && prev->getViews() != LECTURE_NODE)
    {
        if(prev->getViews() != 0) //dont delete 0
        {
            prev->setPrev(prev->getNext());
            if(prev->getNext() != NULL)
            {
                prev->getNext()->setPrev(prev->getPrev());
            }
        }
    }
}

void List::disconnectLecture(std::shared_ptr<Node> next, std::shared_ptr<Node> prev)
{
    if(prev->getViews() != LECTURE_NODE)
    {
        prev->setNext(next);
    }
    else
    {
        prev->setRight(next);
    }

    //middle one
    if(next != NULL)
    {
       next->setPrev(prev);
    }    
}

std::shared_ptr<Node> List::addLectureToViews(std::shared_ptr<Node> node_views_ptr, std::shared_ptr<Node> node_lecture_ptr)
{
    std::shared_ptr<Node> first = node_views_ptr->getRight();

    node_lecture_ptr->setNext(first);
    node_lecture_ptr->setPrev(node_views_ptr);
    node_lecture_ptr->setRight(node_views_ptr);

    first->setPrev(node_lecture_ptr);
    head->setRight(node_lecture_ptr);
}


std::shared_ptr<Node> List::addLecture(int new_course_id, int new_class_id)
{
    std::shared_ptr<Node> new_node = std::shared_ptr<Node>(new Node(new_course_id,new_class_id));
    addLectureToViews(head, new_node);
}

std::shared_ptr<Node> List::moveLecture(std::shared_ptr<Node> node_lecture_ptr, int time)
{
    std::shared_ptr<Node> prev = node_lecture_ptr->getPrev();
    std::shared_ptr<Node> next = node_lecture_ptr->getNext();
    std::shared_ptr<Node> views_node = node_lecture_ptr->getRight();

    int curr_views = views_node->getViews() + time;

    disconnectLecture(next,prev);

    int nextViews;
    while(views_node->getNext() != NULL)
    {
        nextViews = views_node->getNext()->getViews();
        if(nextViews >= curr_views)
        {
            break;
        }

        views_node = views_node->getNext();
    }

    if(views_node->getNext() == NULL || nextViews > curr_views)
    {
    //create new views node and set it as next
    std::shared_ptr<Node> new_view = std::shared_ptr<Node>(new Node(curr_views));
    new_view->setNext(views_node->getNext());
    new_view->setPrev(views_node);

    views_node->setNext(new_view);
    }

    //insert node to 
    addLectureToViews(views_node->getNext(), node_lecture_ptr);
    

    removeViews(next,prev);
}


//to do:
int List::getLectureViews(std::shared_ptr<Node> node_lecture_ptr);
void List::getMostViewd(int numOfClasses, int* courses, int* classes);
