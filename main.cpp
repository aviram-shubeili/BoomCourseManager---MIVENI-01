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
    List* list = new List();
    cout<<"f \n";
    int courses[5];//= new int[5];
    int classes[5];// = new int[5];

         std::shared_ptr<Node> n00 = list->addLecture(0,0);
         std::shared_ptr<Node> n01 =list->addLecture(0,1);
         std::shared_ptr<Node> n02 =list->addLecture(0,2);  
         std::shared_ptr<Node> n20 =list->addLecture(2,0);
         std::shared_ptr<Node> n21 =list->addLecture(2,1);
         std::shared_ptr<Node> n22 =list->addLecture(2,2);


    cout<<"n \n";
    list->getMostViewd(5,courses,classes);
  
    printArry(courses,5);
    printArry(classes,5);

    cout<<"kk \n";
/*
    list->moveLecture(n01,12);
    list->moveLecture(n22,13);
    list->moveLecture(n21,12);
    list->moveLecture(n02,16);
    list->moveLecture(n01,3);
*/
    //list->get
    delete list;

    cout<<"kingg \n";
}




