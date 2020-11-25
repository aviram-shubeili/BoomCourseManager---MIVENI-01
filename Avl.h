#ifndef BOOM_AVL_H
#define BOOM_AVL_H
#include "Course.h"

/**
 * Description:
 *
 */



class Avl {
    struct Avl_n {
        int key;
        Course data;
        struct Avl_n* right;
        struct Avl_n* left;
        int height;
    };
private:

int height();

public:
    Avl_n* root;

void insert(int key, Course data);
void remove(int key);
std::shared_ptr<Course> find(int key);

};


#endif //BOOM_AVL_H
