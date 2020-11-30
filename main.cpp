/*
 * testAVLTree.cpp
 *
 *  Created on: 19 ���� 2013
 *      Author: shirel
 */

#include "AVLTree.h"
#include <vector>
#include <ostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "Auxiliaries.h"

int main(){
  AVLTree<int> tree;

    //Specific Cases

    /*correct output for the four next cases
    1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0 */

    //basic LL root change
    tree.insert(3,3);
    tree.insert(2,2);
    tree.insert(1,1);
    tree.printTree();
    print2D(tree.getRoot());
    tree.clearTree();
    tree.printTree();

    //basic LR root change
    tree.insert(3,3);
    tree.insert(1,1);
    tree.insert(2,2);
    tree.printTree();
    tree.clearTree();

    //basic RR root change
    tree.insert(1,1);
    tree.insert(2,2);
    tree.insert(3,3);
    tree.printTree();
    tree.clearTree();

    //basic RL root change
    tree.insert(1,1);
    tree.insert(3,3);
    tree.insert(2,2);
    tree.printTree();
    tree.clearTree();

    //basic LR not root change
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    4 BF: 1 Height: 2
    5 BF: 0 Height: 0
    6 BF: 1 Height: 3
    7 BF: 0 Height: 0
    8 BF: 1 Height: 1 */
    tree.insert(6,6);
    tree.insert(4,4);
    tree.insert(8,8);
    tree.insert(3,3);
    tree.insert(5,5);
    tree.insert(7,7);
    tree.insert(1,1);
    tree.insert(2,2);
    tree.printTree();
    tree.clearTree();

    //basic LL not root change
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    4 BF: 1 Height: 2
    5 BF: 0 Height: 0
    6 BF: 1 Height: 3
    7 BF: 0 Height: 0
    8 BF: 1 Height: 1 */
    tree.insert(6,6);
    tree.insert(4,4);
    tree.insert(8,8);
    tree.insert(3,3);
    tree.insert(5,5);
    tree.insert(7,7);
    tree.insert(2,2);
    tree.insert(1,1);
    tree.printTree();
    tree.clearTree();

    //basic RR not root change
    /*correct output
     * 1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    5 BF: 1 Height: 2
    7 BF: 0 Height: 0*/
    tree.insert(5,5);
    tree.insert(7,7);
    tree.insert(1,1);
    tree.insert(2,2);
    tree.insert(3,3);
    tree.printTree();
    tree.clearTree();

    //basic RL not root change
    /*correct output
     * 1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    5 BF: 1 Height: 2
    7 BF: 0 Height: 0*/
    tree.insert(5,5);
    tree.insert(7,7);
    tree.insert(1,1);
    tree.insert(3,3);
    tree.insert(2,2);
    tree.printTree();
    tree.clearTree();

    //root deletion no roll successor is a neighbour
    /*correct output
    2 BF: 0 Height: 0
    3 BF: 1 Height: 1
    5 BF: 1 Height: 2
    6 BF: 0 Height: 0*/
    tree.insert(4,4);
    tree.insert(5,5);
    tree.insert(3,3);
    tree.insert(2,2);
    tree.insert(6,6);
    tree.remove(4);
    tree.printTree();
    tree.clearTree();

    //root deletion no roll successor is not a neighbour
    /*correct output
    2 BF: 0 Height: 0
    3 BF: 1 Height: 1
    5 BF: 0 Height: 2
    6 BF: 0 Height: 0
    7 BF: 0 Height: 1
    8 BF: 0 Height: 0 */
    tree.insert(4,4);
    tree.insert(3,3);
    tree.insert(7,7);
    tree.insert(2,2);
    tree.insert(5,5);
    tree.insert(8,8);
    tree.insert(6,6);
    tree.remove(4);
    tree.printTree();
    tree.clearTree();

    //node deletion no roll successor is a neighbour case7
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 1 Height: 1
    4 BF: 1 Height: 2
    5 BF: 0 Height: 0
    7 BF: 1 Height: 3
    8 BF: -1 Height: 1
    9 BF: 0 Height: 0*/
    tree.insert(7,7);
    tree.insert(3,3);
    tree.insert(8,8);
    tree.insert(2,2);
    tree.insert(4,4);
    tree.insert(9,9);
    tree.insert(5,5);
    tree.insert(1,1);
    tree.remove(3);
    tree.printTree();
    tree.clearTree();

    //node deletion no roll successor is not a neighbour case8
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 1 Height: 1
    5 BF: 0 Height: 2
    6 BF: 0 Height: 0
    7 BF: 0 Height: 1
    8 BF: 0 Height: 0
    9 BF: 0 Height: 3
    10 BF: 0 Height: 0
    12 BF: -1 Height: 2
    13 BF: -1 Height: 1
    14 BF: 0 Height: 0*/
    tree.insert(9,9);
    tree.insert(3,3);
    tree.insert(12,12);
    tree.insert(2,2);
    tree.insert(7,7);
    tree.insert(10,10);
    tree.insert(13,13);
    tree.insert(1,1);
    tree.insert(5,5);
    tree.insert(8,8);
    tree.insert(14,14);
    tree.insert(6,6);
    tree.remove(3);
    tree.printTree();
    tree.clearTree();

    //node deletion causing LR case9
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 0 Height: 1
    3 BF: 0 Height: 0
    4 BF: 0 Height: 2
    7 BF: -1 Height: 1
    8 BF: 0 Height: 0*/
    tree.insert(7,7);
    tree.insert(2,2);
    tree.insert(8,8);
    tree.insert(1,1);
    tree.insert(4,4);
    tree.insert(9,9);
    tree.insert(3,3);
    tree.remove(9);
    tree.printTree();
    tree.clearTree();

    //node deletion causing LL case10
    /*correct output
    1 BF: 0 Height: 0
    2 BF: 1 Height: 1
    3 BF: 0 Height: 2
    4 BF: 0 Height: 0
    7 BF: 0 Height: 1
    8 BF: 0 Height: 0*/
    tree.insert(7,7);
    tree.insert(3,3);
    tree.insert(8,8);
    tree.insert(2,2);
    tree.insert(4,4);
    tree.insert(9,9);
    tree.insert(1,1);
    tree.remove(9);
    tree.printTree();
    tree.clearTree();

    //node deletion causing RR case11
    /*correct output
    2 BF: 0 Height: 0
    3 BF: 0 Height: 1
    7 BF: 0 Height: 0
    8 BF: 0 Height: 2
    9 BF: -1 Height: 1
    10 BF: 0 Height: 0*/
    tree.insert(3,3);
    tree.insert(2,2);
    tree.insert(8,8);
    tree.insert(7,7);
    tree.insert(1,1);
    tree.insert(9,9);
    tree.insert(10,10);
    tree.remove(1);
    tree.printTree();
    tree.clearTree();

    //node deletion causing RL case12
    /*correct output
    * 2 BF: 0 Height: 0
    3 BF: 1 Height: 1
    7 BF: 0 Height: 2
    10 BF: 0 Height: 0
    13 BF: 0 Height: 1
    14 BF: 0 Height: 0*/
    tree.insert(3,3);
    tree.insert(2,2);
    tree.insert(13,13);
    tree.insert(7,7);
    tree.insert(1,1);
    tree.insert(14,14);
    tree.insert(10,10);
    tree.remove(1);
    tree.printTree();
    tree.clearTree();

    //double rotations RL and RR case 13
    /*correct output
    3 BF: 0 Height: 0
    5 BF: 0 Height: 1
    7 BF: 0 Height: 0
    9 BF: 0 Height: 2
    11 BF: 0 Height: 0
    13 BF: 1 Height: 1
    15 BF: 0 Height: 3
    17 BF: 0 Height: 0
    19 BF: -1 Height: 2
    21 BF: -1 Height: 1
    23 BF: 0 Height: 0*/
    tree.insert(9,9);
    tree.insert(3,3);
    tree.insert(15,15);
    tree.insert(1,1);
    tree.insert(7,7);
    tree.insert(13,13);
    tree.insert(19,19);
    tree.insert(5,5);
    tree.insert(11,11);
    tree.insert(17,17);
    tree.insert(21,21);
    tree.insert(23,23);
    tree.remove(1);
    tree.printTree();
    tree.clearTree();

    //double rotations RR and RR case 14
    /*correct output
    3 BF: 0 Height: 0
    7 BF: 0 Height: 1
    8 BF: 0 Height: 0
    9 BF: 0 Height: 2
    11 BF: 0 Height: 0
    13 BF: 1 Height: 1
    15 BF: 0 Height: 3
    17 BF: 0 Height: 0
    19 BF: -1 Height: 2
    21 BF: -1 Height: 1
    23 BF: 0 Height: 0*/
    tree.insert(9,9);
    tree.insert(3,3);
    tree.insert(15,15);
    tree.insert(1,1);
    tree.insert(7,7);
    tree.insert(13,13);
    tree.insert(19,19);
    tree.insert(8,8);
    tree.insert(11,11);
    tree.insert(17,17);
    tree.insert(21,21);
    tree.insert(23,23);
    tree.remove(1);
    tree.printTree();
    tree.clearTree();

    //double rotations RL and LL case 15
    /*correct output
    6 BF: 0 Height: 0
    7 BF: 1 Height: 1
    8 BF: 1 Height: 2
    9 BF: 0 Height: 0
    10 BF: 0 Height: 3
    11 BF: -1 Height: 1
    12 BF: 0 Height: 0
    15 BF: 0 Height: 2
    17 BF: 0 Height: 0
    18 BF: 0 Height: 1
    20 BF: 0 Height: 0
     */
    tree.insert(15,15);
    tree.insert(10,10);
    tree.insert(20,20);
    tree.insert(8,8);
    tree.insert(11,11);
    tree.insert(17,17);
    tree.insert(21,21);
    tree.insert(7,7);
    tree.insert(9,9);
    tree.insert(12,12);
    tree.insert(18,18);
    tree.insert(6,6);
    tree.remove(21);
    tree.printTree();
    tree.clearTree();

    //double rotations LR and LL case 16
    /*correct output
    6 BF: 0 Height: 0
    7 BF: 1 Height: 1
    8 BF: 1 Height: 2
    9 BF: 0 Height: 0
    10 BF: 0 Height: 3
    11 BF: -1 Height: 1
    12 BF: 0 Height: 0
    15 BF: 0 Height: 2
    20 BF: 0 Height: 0
    21 BF: 0 Height: 1
    22 BF: 0 Height: 0 */
    tree.insert(15,15);
    tree.insert(10,10);
    tree.insert(20,20);
    tree.insert(8,8);
    tree.insert(11,11);
    tree.insert(17,17);
    tree.insert(22,22);
    tree.insert(7,7);
    tree.insert(9,9);
    tree.insert(12,12);
    tree.insert(21,21);
    tree.insert(6,6);
    std::shared_ptr<AVLNode<int>> test1 = tree.find(17, tree.getRoot());
    std::shared_ptr<AVLNode<int>> test2 = tree.find(9, tree.getRoot());
    std::shared_ptr<AVLNode<int>> test3 = tree.find(6, tree.getRoot());
    std::shared_ptr<AVLNode<int>> test4 = tree.getRoot();
    tree.remove(17);
    std::cout << test1.use_count() << std::endl;
    tree.printTree();
    tree.clearTree();
    std::cout << test2.use_count() << std::endl;
    std::cout << test3.use_count() << std::endl;
    std::cout << test4.use_count() << std::endl;

    //delete node cause LR
    /*correct output
     * 2 BF: 0 Height: 0
    3 BF: -1 Height: 2
    4 BF: 0 Height: 0
    6 BF: 1 Height: 1*/

    tree.insert(5,5);
    tree.insert(3,3);
    tree.insert(6,6);
    tree.insert(2,2);
    tree.insert(4,4);
    tree.remove(5);
    tree.printTree();
    tree.clearTree();

    //delete node cause LR
    /*correct output
     * 2 BF: 0 Height: 0
    3 BF: 0 Height: 1
    6 BF: 0 Height: 0*/
    tree.insert(5,5);
    tree.insert(3,3);
    tree.insert(6,6);
    tree.insert(2,2);
    tree.remove(5);
    tree.printTree();
    tree.clearTree();

    std::vector<int> vector;
    for (int i=1; i<=100; i++) vector.push_back(i);

    //Randomly insert and removes nodes
    for (int k = 1; k < 20; ++k) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
        for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
            tree.insert(*it,*it);

        }
        tree.printTree();
        shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
        for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
            tree.remove(*it);
            tree.printTree();

        }
        tree.clearTree();
        tree.printTree();
        std::cout << '\n';
    }

    return 0;
}

