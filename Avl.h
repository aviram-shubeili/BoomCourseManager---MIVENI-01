#ifndef BOOM_AVL_H
#define BOOM_AVL_H
#include "Course.h"




/*
 * T ==>
 * T = AVL_Tree
 * T = course_node - array of shared_ptr
 * T = lecture_node
 *
 *
 *
 */
/**
 * Description:
 T t;
 t.getData()
 */
<template T>
class Avl {
    struct Avl_n {
        int key;
        std::shared_ptr<T> data;
        struct Avl_n* right;
        struct Avl_n* left;
        //  struct Avl_n* father;  todo: do i need this?
        int height;

        T* getData();
    };
private:

    int height();
public:
    Avl_n* root;

    void insert(int key,std::shared_ptr<T> data);
    void remove(int key);
    /**
     *
     * @param key
     * @return
     */
    std::shared_ptr<Avl_n> find(int key);
    int* findMin(int* start_of_classes, int* start_of_courses, int num_classes);
};


#endif //BOOM_AVL_H
