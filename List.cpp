#include "List.h"

List::List()
{
    head = std::shared_ptr<Node>(new Node(0), shared_ptr<Avl>(new Avl()));
    max = head;
}

List::~List()
{
    max = head = NULL;
}

void removeLectureFromNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id);
{
   std::shared_ptr<Avl_n> course_node = node_ptr->getAvl()->find(course_id);
   if(course_node != NULL)
   {
       course_node->getData()->remove(classes_id);
       //if it was the last class
       if(course_node->getData()->isEmpty())
       {
           node_ptr->getAvl()->remove(course_id);
           //if it is the last course
           if(node_ptr->getAvl()->isEmpty())
           {
               removeNode(node_ptr);
           }
       }
   }
}

void List::removeNode(std::shared_ptr<Node> node_ptr)
{
    //dont delete the 0 node
    if(node_ptr->getViews == 0)
    {
        return;
    }

    std::shared_ptr<Node> prev = node_ptr->getPrev();
    std::shared_ptr<Node> next = node_ptr->getNext();

    prev->setNext(next);
    if(next != NULL)
    {
       next->setPrev(prev);
    }    
}
void List::addLectureToNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id)
{
    std::shared_ptr<Avl_n> course_node = node_ptr->getAvl()->find(course_id);
    if(course_node == NULL)
    {
        std::shared_ptr<Avl> new_tree = shared_ptr<new Avl()>;
        new_tree->insert(classes_id,NULL);
        node_ptr->getAvl()->insert(course_id, new_tree);
    }
    else
    {
        course_node->getData()->insert(classes_id,NULL);
    }
}
void std::shared_ptr<Node> List::AddViewsToNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id, int time)
{
    std::shared_ptr<Node> iterator = node_ptr;
    int old_time = node_ptr->getViews();
    if(old_time != 0)
    {
        //if the current node will be deleted i will still hold the place in the list;
        iterator = node_ptr->getPrev();
    }

    removeLectureFromNode(node_ptr, classes_id,course_id);
    int nextViews = 0;

    while(iterator->getNext() != NULL)
    {
        nextViews = iterator->getNext()->getViews();
        if(nextViews >= old_time + time)
        {
            break;
        }

        iterator = iterator->getNext();
    }

    if(iterator->getNext() == NULL || nextViews > old_time + time)
    {
        //create new views node and set it as next
        std::shared_ptr<Node> new_view = std::shared_ptr<Node>(new Node(curr_views));

        new_view->setNext(iterator->getNext());
        new_view->setPrev(iterator);
    
        if(iterator->getNext() != NULL)
        {
        iterator->getNext()->setPrev(new_view);
        }
        iterator->setNext(new_view);
    }

    //insert lecture to views
    addLectureToNode(iterator->getNext(),classes_id,course_id);
    
    //check if needs to move max
    if(max->getViews() < iterator->getNext()->getViews())
    {
        max = iterator->getNext();
    }
}

int List::getLectureViews(std::shared_ptr<Node> node_lecture_ptr)
{
    return node_lecture_ptr->getViews();
}

void List::getMostViewd(int numOfClasses, int* courses, int* classes)
{
}




