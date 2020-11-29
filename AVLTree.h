#ifndef BOOM_AVL_H
#define BOOM_AVL_H
#include "Course.h"
#include "AVLNode.h"
#include "Auxiliaries.h"
#include "library.h"


/*
 * T ==>
 * T = AVL_Tree
 * T = course_node - array of shared_ptr
 * T = lecture_node
 *
 *
 *
 */

template<typename T>
class AVLTree {
private:

    AVLNode<T>* root;
    AVLNode<T>* min_node;

    /**
     * Description:
     *     return BF of node (assume sub tree of node is height correct).
     * T Assumptions:
     *      none
     * Exceptions:
     *      none
     */
    int getBF(AVLNode<T>* node);
    /**
     * Description:
     *     update node Height (assume sub tree of node is height correct).
     * T Assumptions:
     *      none
     * Exceptions:
     *      none
     */
    void updateHeight(AVLNode<T>* node);


    AVLNode<T>* LL(AVLNode<T> *son, AVLNode<T> *father);
    AVLNode<T>* RR(AVLNode<T> *son, AVLNode<T> *father);
    AVLNode<T>* LR(AVLNode<T> *son, AVLNode<T> *father, AVLNode<T> *grand_father);
    AVLNode<T>* RL(AVLNode<T> *son, AVLNode<T> *father, AVLNode<T> *grand_father);

    AVLNode<T>* removeNode(AVLNode<T>* to_remove);
    /**
     * Recursive call to clear Tree
     * @param node
     */
    void clearTree(AVLNode<T>* node);
    /**
     * return true if is leaf
     * false if null or not leaf
     * @param node
     * @return
     */
    bool isLeaf(AVLNode<T>* node) const;
    /**
     * return true if node points to the tree`s root
     * @param node
     * @return
     */
    bool isRoot(AVLNode<T>* node) const;

    /**
  * Description:
  *    inserts given node to tree and keep it balanced.
  * T Assumptions:
  *      none
  * Exceptions:
     *
  */

    void insert(AVLNode<T> *new_node, AVLNode<T> *root);

public:
    /**
     * Default c'tor - creates an empty AVL Tree.
     */
    AVLTree<T>();


    // TODO: do i need those???
    //AVLTree<T>(const AVLTree<T>& other);
//    AVLTree<T>& operator=(const AVLTree<T>& other);

    /**
     * D'or - destroy Nodes and tree.
     */
    ~AVLTree();

    /**
     * return pointer to the min key node
     * @return
     */
    AVLNode<T>* getMin();
    /**
     * return pointer to the root
     * @return
     */
    AVLNode<T> * getRoot() ;


    /**
  * Description:
  *    create a Node containing data and key and insert it to the tree
  * T Assumptions:
  *      none
  * Exceptions:
  *     std::bad_alloc
  *     Invalid Input - if key is invalid
  *     NodeAlreadyExists - if key already exists in tree
  */

    void insert(int key, T &data);

    StatusType remove(int key);


    /**
     * TODO: return value??
     * @param key
     * @return
     */
    AVLNode<T>* find(int key, AVLNode<T> *node);



    // TODO: do i need this?
    int* findMin(int* start_of_classes, int* start_of_courses, int num_classes);
    void printTree();

};



template<typename T>
void AVLTree<T>::updateHeight(AVLNode<T> *node) {
    if(node == NULL) {
        return;
    }
    node->setHeight(1 + max(getHeight(node->getLeftSon()), getHeight(node->getRightSon())));
}

template<typename T>
int AVLTree<T>::getBF(AVLNode<T> *node) {
    if(node == NULL) {
        return 0;
    }
    // h(l) - h(r)
    return getHeight(node->getLeftSon()) - getHeight(node->getRightSon());
}

template<typename T>
AVLNode<T> *AVLTree<T>::LL(AVLNode<T> *son, AVLNode<T> *father) {
    // TODO: IS IT POSSIBLE THAT son OR father IS NULL?
    father->setLeftSon(son->getRightSon());
    son->setRightSon(father);


    // update Heights!

    updateHeight(father);
    updateHeight(son);

    // return the subtree`s new root.
    return son;
}

template<typename T>
AVLNode<T> *AVLTree<T>::RR(AVLNode<T> *son, AVLNode<T> *father) {
    // TODO: IS IT POSSIBLE THAT father OR son IS NULL?
    father->setRightSon(son->getLeftSon());
    son->setLeftSon(father);

    // update Heights!

    updateHeight(father);
    updateHeight(son);

    // return the subtree`s new root.
    return son;
}

template<typename T>
AVLNode<T> *AVLTree<T>::LR(AVLNode<T> *son, AVLNode<T> *father, AVLNode<T> *grand_father) {
    // TODO: IS IT POSSIBLE THAT father OR son IS NULL?

    father = RR(son,father);
    grand_father = LL(father,grand_father);

    return grand_father;
}

template<typename T>
AVLNode<T> *AVLTree<T>::RL(AVLNode<T> *son, AVLNode<T> *father, AVLNode<T> *grand_father) {
    // TODO: IS IT POSSIBLE THAT father OR son IS NULL?

    father = LL(son,father);
    grand_father = RR(father,grand_father);

    return grand_father;

}

template<typename T>
void AVLTree<T>::clearTree(AVLNode<T> *node) {
    if(node == NULL) {
        return;
    }
    // post order deleting
    clearTree(node->getLeftSon());
    clearTree(node->getRightSon());
    ~node;
}

template<typename T>
bool AVLTree<T>::isLeaf(AVLNode<T> *node) const {
    if(node == NULL) {
        return false;
    }
    return node->getLeftSon() == NULL and node->getRightSon() == NULL;
}

template<typename T>
bool AVLTree<T>::isRoot(AVLNode<T> *node) const {
    return node == root;
}

template<typename T>
AVLTree<T>::AVLTree() :
        root(NULL),
        min_node(NULL) {}

template<typename T>
AVLTree<T>::~AVLTree() {
    clearTree(root);
}

template<typename T>
AVLNode<T> *AVLTree<T>::getMin() {
    return min_node;
}

template<typename T>
AVLNode<T> * AVLTree<T>::getRoot() {
    return root;
}

template<typename T>
AVLNode<T> *AVLTree<T>::find(int key, AVLNode<T> *node) {

    if(node == NULL or node->getKey() == key) {
        return node;
    }
    // search in left or right sub tree according to compare.
    return (node->getKey() < key) ? find(key,node->getRightSon()) : find(key,node->getLeftSon());

}

template<typename T>
void AVLTree<T>::insert(int key, T &data) {
    // invalid key
    if(isInvalid(key)) {
        throw InvalidInput();
    }
    // node with same key already in the tree
    if(find(key,root) != NULL) {
        throw NodeAlreadyExists();
    }
    // T will be copied to AVLNode
    AVLNode<T> new_node = new AVLNode<T>(key,data);

    // empty tree
    if(root = NULL) {
        root = new_node;
        min_node = new_node;
        return;
    }
    // todo: preserve min node!
    if(min_node->getKey() > new_node.getKey()) {
        min_node = new_node;
    }
    insert(new_node,root);

}

template<typename T>
void AVLTree<T>::insert(AVLNode<T> *new_node, AVLNode<T> *root) {

        // new_node should be placed in the left subtree
    if(new_node->getKey() < root->getKey()) {
        if(root->getLeftSon() != NULL) {
            // keep searching for a place in left subtree
            insert(new_node, root->getLeftSon());
        }
        else {
            // there is no left subtree --> insert new_node
            root->setLeftSon(new_node);
        }
    }
        // new_node should be placed in the left subtree

    else {
        if(root->getRightSon() != NULL) {
            // keep searching for a place in right subtree
            insert(new_node, root->getRightSon());
        }
        else {
            // there is no right subtree --> insert new_node
            root->setRightSon(new_node);
        }
    }



}


#endif //BOOM_AVL_H
