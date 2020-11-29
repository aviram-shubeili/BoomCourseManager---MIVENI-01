//
// Created by avira on 29/11/2020.
//

#ifndef BOOM_AVLNODE_H
#define BOOM_AVLNODE_H

#include "Auxiliaries.h"
/**
 * Assumptions on T:
 *      default constructor
 *      copy constructor
 *      assignment operator
 *      operator <
 *
 * @tparam T
 */
template< typename T>
class AVLNode {
private:
    int key;
    T data;
    AVLNode<T>* father;
    AVLNode<T>* right_son;
    AVLNode<T>* left_son;
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
    AVLNode<T>(int key, T& data=T());

    /**
     * Description:
     *      Copy Constructor.
     * T Assumptions:
     *      Copy constructor.
     * Exceptions:
     *      std::bad_alloc() - allocation problem (thrown from T copy ctor)
     */
    AVLNode<T>(const AVLNode<T>& other);

    /**
     * Description:
     *       Assignment Operator
     * T Assumptions:
     *      Assignment Operator - todo: make sure it doesnt overwrite before allocation!
     *
     * Exceptions:
     *      std::bad_alloc() - allocation problem (thrown from T Assignment operator)
     */
    AVLNode<T>& operator=(const AVLNode<T>& other);

    ~AVLNode<T>() = default;



    /**
     *           Getters And Setters:
     * **********************************************
     */
    const AVLNode<T>* getFather() const;

    void setFather(AVLNode<T>* node);

    const AVLNode<T>* getLeftSon() const;

    void setLeftSon(AVLNode<T>* node);

    const AVLNode<T>* getRightSon() const;

    void setRightSon(AVLNode<T>* node);

    /**
     * Description:
     *     return height of node (assume sons of node is height correct).
     * T Assumptions:
     *      none
     * Exceptions:
     *      none
     */
    int getHeight(const AVLNode<T> *node) ;

    void setHeight(int new_height);

    // todo: should this return T& ? T?  or T*? or maybe shared_ptr??
    T& getData();

    /**
     * Description:
     *       Data setter
     * T Assumptions:
     *      Assignment Operator - todo: make sure it doesnt overwrite before allocation!
     *
     * Exceptions:
     *      std::bad_alloc() - allocation problem (thrown from T Assignment operator)
     */
    void setData(T& new_data);

    /**
     * Compare keys function.
     */
    int getKey() const;
    bool operator<(const AVLNode<T>* other);
    bool operator==(const AVLNode<T>* other);


};
/*
 * ************************************************************************************************************
 * ************************************************************************************************************
 *                                                 Implementation
 * ************************************************************************************************************
 * ************************************************************************************************************
 */
template<typename T>
AVLNode<T>::AVLNode(int key, T &data):
        key(key),
        data(data),
        father(nullptr),
        left_son(nullptr),
        right_son(nullptr),
        height(-1) {

    if(isInvalid(key)) {
        throw InvalidInput();
    }
}

template<typename T>
AVLNode<T>::AVLNode(const AVLNode<T> &other):
        key(other.key),
        data(other.data),
        father(nullptr),
        left_son(nullptr),
        right_son(nullptr),
        height(-1) { }

template<typename T>
AVLNode<T> &AVLNode<T>::operator=(const AVLNode<T> &other) {
    if(this == &other) {
        return *this;
    }
    // todo: in case of allocation problem expect T to throw allocation error and do not touch this->data.
    data = other.data;
    key = other.key;
    father = nullptr;
    left_son = nullptr;
    right_son = nullptr;
    height = -1;

}


template<typename T>
const AVLNode<T> *AVLNode<T>::getFather() const {
    return father;
}

template<typename T>
void AVLNode<T>::setFather(AVLNode<T> *node) {
    father = node;
}

template<typename T>
const AVLNode<T> *AVLNode<T>::getLeftSon() const {
    return left_son;
}

template<typename T>
void AVLNode<T>::setLeftSon(AVLNode<T> *node) {
    left_son = node;
}

template<typename T>
const AVLNode<T> *AVLNode<T>::getRightSon() const {
    return right_son;
}

template<typename T>
void AVLNode<T>::setRightSon(AVLNode<T> *node) {
    right_son = node;
}

template<typename T>
T &AVLNode<T>::getData() {
    return data;
}

template<typename T>
void AVLNode<T>::setData(T& new_data) {
    data = new_data;
}

template<typename T>
int AVLNode<T>::getHeight(const AVLNode<T> *node) {
    return node == NULL ? -1 : node->height;
}

template<typename T>
void AVLNode<T>::setHeight(int new_height) {
    height = new_height;
}

template<typename T>
bool AVLNode<T>::operator<(const AVLNode<T> *other) {
    if(other == NULL) {
        return false;
    }
    return this->key < other->key;
}

template<typename T>
bool AVLNode<T>::operator==(const AVLNode<T> *other) {
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
bool AVLNode<T>::operator<(int other_key) {
    return this->key < other_key;

}

template<typename T>
bool AVLNode<T>::operator==(int other_key) {
    return this->key == other_key;
}


#endif //BOOM_AVLNODE_H
