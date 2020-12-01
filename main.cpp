#include <iostream>
#include "List.h"
using namespace std;

static void printArry(int a[],int num)
{
    for(int i =0;i<num;i++)
    {
        cout<<a[i] <<",";
    }
    cout<<"\n";
}

int main(int argc,char* argv[])
{
    std::shared_ptr<List> list = std::shared_ptr<List>(new List());
    std::shared_ptr<Node> head = list->addNewLecture(1,1);    
    list->addNewLecture(2,1);    
    list->addNewLecture(3,1);  

    list->addNewLecture(1,2);    
    list->addNewLecture(2,2);      


    list->AddViewsToNode(head,2,1,33);
    list->AddViewsToNode(head,3,1,33);
    list->AddViewsToNode(head,1,2,44);
    list->AddViewsToNode(head,2,2,44);



    //std::cout<<"THE MAX"<<head20->getNext()->getViews()<<"\n";//Debug

    int classes[5];
    int courses[5];
    
    //std::shared_ptr<Node> AddViewsToNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id, int time);
    //std::shared_ptr<Node> addNewLecture(int classes_id, int course_id);
    //void getMostViewd(int numOfClasses, int* courses, int* classes);

    list->getMostViewd(5,courses,classes);
    printArry(classes, 5);
    printArry(courses, 5);


    list->printList();
    list->printMax();

    //std::cout<<"THE nodes"<<<<"\n";//Debug
  //  head44->getAvl()->find(1,head44->getAvl()->getRoot())->getData()->printTree();



    cout<<"kingg \n";
}




