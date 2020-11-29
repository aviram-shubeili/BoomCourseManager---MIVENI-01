#include <iostream>
#include "AVLTree.h"
#include <vector>
#include <ostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
int main(int argc,char* argv[])
{
    cout<<"kingg \n";

    AVLTree<int> tree;
    AVLNode<int> node(1,1);
    int one = 1;
    int two = 2;
    int three = 3;
    tree.insert(3,three);
    tree.insert(2,two);
    tree.insert(1,one);
    tree.insert(1,one);

}




