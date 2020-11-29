#ifndef BOOM_AVL_H
#define BOOM_AVL_H
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


    AVLNode<T>* LL(AVLNode<T> *A, AVLNode<T> *B);
    AVLNode<T>* RR(AVLNode<T> *A, AVLNode<T> *B);
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

    void insert(AVLNode<T> *new_node, AVLNode<T> *current_root);

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
AVLNode<T> *AVLTree<T>::LL(AVLNode<T> *A, AVLNode<T> *B) {
    // TODO: IS IT POSSIBLE THAT A OR B IS NULL?
    B->setLeftSon(A->getRightSon());
    A->setRightSon(B);
    if(B->getLeftSon()) {
        (B->getLeftSon())->setFather(B);
    }
    A->setFather(B->getFather());
    B->setFather(A);
//    if(B == root) {
//        root = A;
//    }


    // update Heights!

    updateHeight(A);
    updateHeight(B);

    // return the subtree`s new root.
    return A;
}

template<typename T>
AVLNode<T> *AVLTree<T>::RR(AVLNode<T> *A, AVLNode<T> *B) {
    // TODO: IS IT POSSIBLE THAT B OR A IS NULL?
    B->setRightSon(A->getLeftSon());
    A->setLeftSon(B);
    if(B->getRightSon()) {
        (B->getRightSon())->setFather(B);
    }
    A->setFather(B->getFather());
    B->setFather(A);

    // update Heights!
    updateHeight(A);
    updateHeight(B);

    if(B == root) {
        root = A;
    }
    // return the subtree`s new root.
    return A;
}

template<typename T>
AVLNode<T> *AVLTree<T>::LR(AVLNode<T> *son, AVLNode<T> *father, AVLNode<T> *grand_father) {
    // TODO: IS IT POSSIBLE THAT father OR son IS NULL?

    grand_father->setLeftSon(RR(son,father));
    return LL(father,grand_father);
}

template<typename T>
AVLNode<T> *AVLTree<T>::RL(AVLNode<T> *son, AVLNode<T> *father, AVLNode<T> *grand_father) {
    // TODO: IS IT POSSIBLE THAT father OR son IS NULL?

    grand_father->setRightSon(LL(son,father));
    return RR(father,grand_father);
}

template<typename T>
void AVLTree<T>::clearTree(AVLNode<T> *node) {
    if(node == NULL) {
        return;
    }
    // post order deleting
    clearTree(node->getLeftSon());
    clearTree(node->getRightSon());
    node->~AVLNode();
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
    AVLNode<T>* new_node = new AVLNode<T>(key,data);
    // empty tree
    if(root == NULL) {
        root = new_node;
        min_node = new_node;
        return;
    }
    // todo: preserve min node!
    if(min_node->getKey() > new_node->getKey()) {
        min_node = new_node;
    }
    insert(new_node,root);

}

template<typename T>
void AVLTree<T>::insert(AVLNode<T> *new_node, AVLNode<T> *current_root) {


    // new_node should be placed in the left subtree
    if(new_node->getKey() < current_root->getKey()) {
        if(current_root->getLeftSon() != NULL) {
            // keep searching for a place in left subtree
            insert(new_node, current_root->getLeftSon());
        }
        else {
            // there is no left subtree --> insert new_node
            current_root->setLeftSon(new_node);
            new_node->setFather(current_root);
        }
    }
        // new_node should be placed in the left subtree

    else {
        if(current_root->getRightSon() != NULL) {
            // keep searching for a place in right subtree
            insert(new_node, current_root->getRightSon());
        }
        else {
            // there is no right subtree --> insert new_node
            current_root->setRightSon(new_node);
            new_node->setFather(current_root);
        }
    }

    // Done with insertion!

    // Start balancing:
    int bf = getBF(current_root);

// Left Subtree is unbalanced!
    if(bf > 1) {
            // LR
        if(getBF(current_root->getLeftSon()) == -1) {
            current_root = LR((current_root->getLeftSon())->getRightSon(), current_root->getLeftSon(), current_root);
        }
            // LL
        else {
            current_root = LL(current_root->getLeftSon(), current_root);
        }
    }
// right Subtree is unbalaced!
    else if( bf < -1) {

        if(getBF(current_root->getRightSon()) == 1) {
            // RL
            current_root = RL((current_root->getRightSon())->getLeftSon(),current_root->getRightSon(),current_root);
        } // RR
        else {
            current_root = RR(current_root->getRightSon(),current_root);
        }

    }
    updateHeight(current_root);

}


#endif //BOOM_AVL_H
