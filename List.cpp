#include "List.h"
//NOTES: funtions will not check if they are getting legal input!

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

void List::addLectureToViews(std::shared_ptr<Node> node_views_ptr, std::shared_ptr<Node> node_lecture_ptr)
{
    std::shared_ptr<Node> first = node_views_ptr->getRight();
    node_lecture_ptr->setNext(first);
    node_lecture_ptr->setPrev(node_views_ptr);
    node_lecture_ptr->setRight(node_views_ptr);

    if(first!=NULL)
    {
        first->setPrev(node_lecture_ptr);
    }
    node_views_ptr->setRight(node_lecture_ptr);
}


std::shared_ptr<Node> List::addLecture(int new_course_id, int new_class_id)
{
    std::shared_ptr<Node> new_node = std::shared_ptr<Node>(new Node(new_course_id,new_class_id));
    std::cout<<new_node->getCourseId()<<","<<new_node->getCalssId()<<"new node\n";//Debug
    addLectureToViews(head, new_node);
    std::cout<<head->getRight()->getCourseId()<<","<<head->getRight()->getCalssId()<<"first node\n";//Debug
    return new_node;
}

void List::moveLecture(std::shared_ptr<Node> node_lecture_ptr, int time)
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
    
    if(views_node->getNext() != NULL)
    {
        views_node->getNext()->setPrev(new_view);
    }
    views_node->setNext(new_view);
    }

    //insert node to views
    addLectureToViews(views_node->getNext(), node_lecture_ptr);
    
    //check if needs to move max
    if(max->getViews() < views_node->getNext()->getViews())
    {
        max = views_node->getNext();
    }

    //if needs to remove old view node
    removeViews(next,prev);
}


int List::getLectureViews(std::shared_ptr<Node> node_lecture_ptr)
{
    return node_lecture_ptr->getRight()->getViews();
}

void List::getMostViewd(int numOfClasses, int* courses, int* classes)
{
    std::cout<<"sl \n";
    
    std::shared_ptr<Node> iterator = max->getRight();
    while(numOfClasses != 0)
    {
        //should never be null
        assert(iterator != NULL);

        *classes = iterator->getCalssId();
        *courses = iterator->getCourseId();
        courses++;
        classes++;

        if(iterator->getNext() == NULL)
        {
            iterator = iterator->getRight()->getPrev()->getRight();
        }
        else
        {
            iterator = iterator -> getNext();
        }
        numOfClasses--;
    }
}
