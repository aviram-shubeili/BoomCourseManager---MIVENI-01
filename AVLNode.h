#ifndef BOOM_AVLNODE_H
#define BOOM_AVLNODE_H


#include "Auxiliaries.h"


template< typename T>
class AVLNode {
private:
    int key;
    std::shared_ptr<T> data;
    std::shared_ptr<AVLNode<T>> father;
    std::shared_ptr<AVLNode<T>> right_son;
    std::shared_ptr<AVLNode<T>> left_son;
    int height;

public:
    /**
     * Description:
     *      Constructor.
     * T Assumptions:
     *      Copy constructor
     * Exceptions:
     *      InvalidInput - if key is invalid
     *      std::bad_alloc() - allocation problem
     */
    explicit AVLNode<T>(int key, std::shared_ptr<T> data);

    /**
     * Description:
     *      Copy Constructor.
     * T Assumptions:
     *      Copy constructor.
     * Exceptions:
     *      std::bad_alloc() - allocation problem (thrown from T copy ctor)
     *      todo: do i need this? or just assignment op is good
     */
    AVLNode<T>(const AVLNode<T>& other);

    /**
     * Description:
     *       Assignment Operator - doesnt change place in tree
     *
     * Exceptions:
     *      none
     */
    AVLNode<T>& operator=(const AVLNode<T>& other);

    ~AVLNode<T>() = default;



    /**
     *           Getters And Setters:
     * **********************************************
     */
    std::shared_ptr<AVLNode<T>> getFather() ;

    void setFather(std::shared_ptr<AVLNode<T>> node);

    std::shared_ptr<AVLNode<T>> getLeftSon() ;

    void setLeftSon(std::shared_ptr<AVLNode<T>> node);

    std::shared_ptr<AVLNode<T>> getRightSon() ;

    void setRightSon(std::shared_ptr<AVLNode<T>> node);

    int getHeight() { return height; };

    void setHeight(int new_height);

    std::shared_ptr<T> getData();

    void setData(std::shared_ptr<T> new_data);

    int getKey() const;
    // re-setting key is not allowed - only get.

    /**
     * Compare keys function.
     */
    bool operator<( std::shared_ptr<AVLNode<T>> other);
    bool operator==( std::shared_ptr<AVLNode<T>> other);


};

/*
 * ************************************************************************************************************
 * ************************************************************************************************************
 *                                                 Implementation
 * ************************************************************************************************************
 * ************************************************************************************************************
 */

template<typename T>
AVLNode<T>::AVLNode(const AVLNode<T> &other):
        key(other.key),
        data(other.data),
        father(nullptr),
        left_son(nullptr),
        right_son(nullptr),
        height(0) { }

template<typename T>
AVLNode<T> &AVLNode<T>::operator=(const AVLNode<T> &other) {
    if(this == &other) {
        return *this;
    }
    data = other.data;
    key = other.key;
    return *this;
}


template<typename T>
std::shared_ptr<AVLNode<T>> AVLNode<T>::getFather()  {
    return father;
}

template<typename T>
void AVLNode<T>::setFather(std::shared_ptr<AVLNode<T>> node) {
    father = node;
}

template<typename T>
std::shared_ptr<AVLNode<T>> AVLNode<T>::getLeftSon()  {
    return left_son;
}

template<typename T>
void AVLNode<T>::setLeftSon(std::shared_ptr<AVLNode<T>> node) {
    left_son = node;
}

template<typename T>
std::shared_ptr<AVLNode<T>> AVLNode<T>::getRightSon()  {
    return right_son;
}

template<typename T>
void AVLNode<T>::setRightSon(std::shared_ptr<AVLNode<T>> node) {
    right_son = node;
}

template<typename T>
std::shared_ptr<T> AVLNode<T>::getData() {
    return data;
}

template<typename T>
void AVLNode<T>::setData(std::shared_ptr<T> new_data) {
    data = new_data;
}

template<typename T>
void AVLNode<T>::setHeight(int new_height) {
    height = new_height;
}

template<typename T>
bool AVLNode<T>::operator<( std::shared_ptr<AVLNode<T>> other) {
    if(other == NULL) {
        return false;
    }
    return this->key < other->key;
}

template<typename T>
bool AVLNode<T>::operator==( std::shared_ptr<AVLNode<T>> other) {
    if(other == NULL) {
        return false;
    }
    return this->key == other->key;
}

template<typename T>
int AVLNode<T>::getKey() const {
    return key;
}


template<typename T>
AVLNode<T>::AVLNode(int key, std::shared_ptr<T> data) :
        key(key),
        data(data),
        father(nullptr),
        right_son(nullptr),
        left_son(nullptr),
        height(0)
{
    if(isInvalid(key)) {
        throw InvalidInput();
    }
}


// This will return -1 if node given is null (according to assumption that leaf height is 0)
template<typename T>
int getHeight(std::shared_ptr<AVLNode<T>> node)  {
    return node == NULL ?  -1 : node->getHeight();
}


/**
 * assuming son has a father, return true if son is his left son, false otherwise
 */
template<typename T>
static bool isLeftSon(std::shared_ptr<AVLNode<T>> son) {
    assert(son->getFather() != NULL);
    return (son->getFather())->getLeftSon() == son;
}

/**
 * return number of sons (0,1,2)
 */
template<typename T>
static int getNumSons(std::shared_ptr<AVLNode<T>> node) {
    int sum = 0;
    if(node->getLeftSon()) {
        sum++;
    }
    if(node->getRightSon()) {
        sum++;
    }
    return sum;
}

#endif //BOOM_AVLNODE_H
