#include "List.h"

List::List()
{
//    head = std::shared_ptr<Node>(new Node(0), std::shared_ptr<AVLTree<AVLTree<int>>>(new AVLTree<AVLTree<int>>()));
    max = head;
}

List::~List()
{
    max = head = NULL;
}

void List::removeLectureFromNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id)
{
    //find and store the data of course node
   std::shared_ptr<AVLTree<AVLTree<int*>>> tree_ptr = (node_ptr->getAvl());
   AVLNode<AVLTree<int*>>* course_data_node = tree_ptr->find(course_id,tree_ptr->getRoot());//the node of the course
   //if the course exist in this node
   if(course_data_node != NULL)
   {
       //remove calss from the course tree
       course_data_node->getData().remove(classes_id);
       //if it was the last class (the course tree is empty)
       if(course_data_node->getData().getRoot() == NULL)
       {
           //remove course tree
           node_ptr->getAvl()->remove(course_id);
           //if it is the last course
           if(node_ptr->getAvl()->getRoot() == NULL)
           {
               //remove all the node
               removeNode(node_ptr);
           }
       }
   }
}

void List::removeNode(std::shared_ptr<Node> node_ptr)
{
    //dont delete the 0 node
    if(node_ptr->getViews() == 0)
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
    int* a = new int(0);//ToDo: delete Debug
    //find the node of the course (with the course tree inside the data)
    AVLNode<AVLTree<int*>>* course_node = node_ptr->getAvl()->find(course_id,node_ptr->getAvl()->getRoot());
    //if the node doesnt exist (no course node for the couse)
    if(course_node == NULL)
    {
        AVLTree<int*>* new_tree = new AVLTree<int*>();
        new_tree->insert(classes_id, a);
        node_ptr->getAvl()->insert(course_id, *new_tree);
    }
    else
    {
        course_node->getData().insert(classes_id,a);
    }
}

void List::AddViewsToNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id, int time)
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
    //if needs to create new node
    if(iterator->getNext() == NULL || nextViews > old_time + time)
    {
        //create new views node and set it as next
        std::shared_ptr<Node> new_view = std::shared_ptr<Node>(new Node(old_time + time));

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

void removeCourseFromNode(std::shared_ptr<Node> node_ptr, int course_id)
{
    //find and store the data of course mode
   AVLNode<AVLTree<int*>>* course_data_node = node_ptr->getAvl()->find(course_id, node_ptr->getAvl()->getRoot());
   //if the course exist in this node
   if(course_data_node != NULL)
   {
        //remove course tree
        node_ptr->getAvl()->remove(course_id);
   }
}


void List::getMostViewd(int numOfClasses, int* courses, int* classes)
{

}

//asume SetVisit(bool) will flag visited 
void List::getMinTree(std::shared_ptr<Avl> min,int numOfClasses, int* courses, int* classes)
{
    if(min == null)
    {
        return;
    }

    min.SetVisit(true);
}

//asume SetVisit(bool) will flag visited 
void List::getMinTree(std::shared_ptr<Avl> min,int numOfClasses, int* courses, int* classes)
{
    if(min == null)
    {
        return;
    }
    
    min.SetVisit(true);
}




