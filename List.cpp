#include "List.h"

List::List()
{
    head = std::shared_ptr<Node>(new Node(0));
    max = head;
}

List::~List()
{
    std::shared_ptr<Node> iterator = head;
    while(iterator) {
       if(iterator->getPrev()) {
           iterator->getPrev()->setNext(nullptr);
           iterator->setPrev(nullptr);
       }
           iterator = iterator->getNext();
    }
    head = max = nullptr;
}

void List::removeLectureFromNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id)
{
    //find and store the data of course node
   std::shared_ptr<AVLNode<AVLTree<int*>>> course_data_node = node_ptr->getAvl()->find(course_id);//the node of the course
   //if the course exist in this node
   if(course_data_node != NULL)
   {
       //remove calss from the course tree
       course_data_node->getData()->remove(classes_id);

       //if it was the last class (the course tree is empty)
       if(course_data_node->getData()->getRoot() == NULL)
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
std::shared_ptr<Node> List::addNewLecture(int classes_id, int course_id)
{
    addLectureToNode(head, classes_id, course_id);
    return head;
}

void List::addLectureToNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id)
{
    //find the node of the course (with the course tree inside the data)
    std::shared_ptr<AVLNode<AVLTree<int*>>> course_node = node_ptr->getAvl()->find(course_id,node_ptr->getAvl()->getRoot());

    //if the node doesnt exist (no course node for the couse)
    if(course_node == NULL)
    {
        std::shared_ptr<AVLTree<int*>> new_tree = std::shared_ptr<AVLTree<int*>>(new AVLTree<int*>());
        new_tree->insert(classes_id,nullptr);
        node_ptr->getAvl()->insert(course_id,new_tree);
    }
    else
    {
        course_node->getData()->insert(classes_id,nullptr);
    }
}

std::shared_ptr<Node> List::addViewsToLecture(std::shared_ptr<Node> node_ptr, int class_id, int course_id, int time)
{
    std::shared_ptr<Node> iterator = node_ptr;
    int old_time = node_ptr->getViews();
    if(old_time != 0)
    {
        //if the current node will be deleted i will still hold the place in the list;
        iterator = node_ptr->getPrev();
    }


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
    addLectureToNode(iterator->getNext(), class_id, course_id);
    
    //check if needs to move max
    if(max->getViews() < iterator->getNext()->getViews())
    {
        max = iterator->getNext();
    }
    // after reallocating is done! delete the old lecture node
    removeLectureFromNode(node_ptr, class_id, course_id);

    return iterator->getNext();
}

int List::getLectureViews(std::shared_ptr<Node> node_lecture_ptr)
{
    return node_lecture_ptr->getViews();
}
//
//void List::removeCourseFromNode(std::shared_ptr<Node> node_ptr, int course_id)
//{
//    //find and store the data of course mode
//   std::shared_ptr<AVLNode<AVLTree<int*>>> course_data_node = node_ptr->getAvl()->find(course_id, node_ptr->getAvl()->getRoot());
//   //if the course exist in this node
//   if(course_data_node != NULL)
//   {
//        //remove course tree
//        node_ptr->getAvl()->remove(course_id);
//   }
//}

void List::getMostViewd(int numOfClasses, int* courses, int* classes)
{
    int counter = 0;
    std::shared_ptr<Node> curr_max = max;//points to the current views node
    //assumes that numOfClasses is indeed less the total classes
    while(numOfClasses > counter)
    {
        getMinTree(curr_max->getAvl()->getMin(), numOfClasses, courses, classes, counter);

        curr_max = curr_max->getPrev();
    }

}

//asume SetVisit(bool) will flag visited 
void List::getMinTree(std::shared_ptr<AVLNode<AVLTree<int*>>> min,int& numOfClasses, int* courses, int* classes, int& counter)
{
    if(min == NULL || numOfClasses == counter)
    {
        return;
    }
    getMinLectures(min->getData()->getMin(), numOfClasses, courses, classes, min->getKey(), counter);

    std::shared_ptr<AVLNode<AVLTree<int*>>> father = min->getFather();
    std::shared_ptr<AVLNode<AVLTree<int*>>> right = min->getRightSon();


    //never visited right
    if(right != NULL && numOfClasses > counter)
    {
        inOrderMostTree(right, numOfClasses, courses, classes,counter);
    }
    if(father != NULL && numOfClasses > counter)
    {
        getMinTree(father, numOfClasses, courses, classes,counter);
    }

}

void List::inOrderMostTree(std::shared_ptr<AVLNode<AVLTree<int*>>> root,int& numOfClasses, int* courses, int* classes, int& counter)
{
    if(root == NULL || numOfClasses == counter)
    {
        return;
    }

    std::shared_ptr<AVLNode<AVLTree<int*>>> right = root->getRightSon();
    std::shared_ptr<AVLNode<AVLTree<int*>>> left = root->getLeftSon();

    if(left != NULL&& numOfClasses > counter)
    {
        inOrderMostTree(left, numOfClasses, courses, classes, counter);
    }

    getMinLectures(root->getData()->getMin(), numOfClasses, courses, classes, root->getKey(), counter);

    if(right != NULL&& numOfClasses > counter)
    {
        inOrderMostTree(right, numOfClasses, courses, classes, counter);
    }
}

//asume SetVisit(bool) will flag visited
void List::getMinLectures(std::shared_ptr<AVLNode<int*>> min,int& numOfClasses, int* courses, int* classes, int curr_course, int& counter)
{
    if(min == NULL || numOfClasses == counter)
    {
        return;
    }

    std::shared_ptr<AVLNode<int*>> father = min->getFather();
    std::shared_ptr<AVLNode<int*>> left = min->getLeftSon();
    std::shared_ptr<AVLNode<int*>> right = min->getRightSon();


    *(courses + counter) = curr_course;
    *(classes + counter) = min -> getKey();
    counter++;

    //never visited right
    if(right != NULL&& numOfClasses > counter)
    {
        inOrderMostNode(right, numOfClasses, courses, classes, curr_course, counter);
    }
    if(father != NULL&& numOfClasses > counter)
    {
        getMinLectures(father, numOfClasses, courses, classes,curr_course,counter);
    }
}

void List::inOrderMostNode(std::shared_ptr<AVLNode<int*>> root,int& numOfClasses, int* courses, int* classes, int curr_course, int& counter)
{
    if(root == NULL || numOfClasses == counter)
    {
        return;
    }
    std::shared_ptr<AVLNode<int*>> left = root->getLeftSon();
    std::shared_ptr<AVLNode<int*>> right = root->getRightSon();

    if(left != NULL&& numOfClasses > counter)
    {
        inOrderMostNode(left, numOfClasses, courses, classes, curr_course, counter);
    }
    if(numOfClasses > counter) {
        *(courses + counter) = curr_course;
        *(classes + counter) = root->getKey();
        counter++;
    }
    if(right != NULL&& numOfClasses > counter)
    {
        inOrderMostNode(right, numOfClasses, courses, classes, curr_course, counter);
    }
}



