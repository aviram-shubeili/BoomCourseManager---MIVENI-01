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
    cout<<"kingg \n";
}




