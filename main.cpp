//Alexander Urbanyak

#include <list>
#include <iostream>
#include <stdlib.h>
#include "bintree.h"

using namespace main_savitch_10;

binary_tree_node<int>* create_tree();

template <class T>
std::list<T>* convert_to_list(binary_tree_node<T>* t, std::list<T>* list);

template <class T>
void print_list(const std::list<T>* list);

int main() {
    binary_tree_node<int> *tree = create_tree();
    std::list<int> empty_list;

    print(tree, 1);
    std::cout << std::endl;

    std::list<int>* list1 = convert_to_list(tree, &empty_list);
    print_list(list1);

    return 0;
}

binary_tree_node<int>* create_tree() {
    binary_tree_node<int>* t1 = new binary_tree_node<int>(10);
    binary_tree_node<int>* t2 = new binary_tree_node<int>(20);
    binary_tree_node<int>* t3 = new binary_tree_node<int>(30);
    binary_tree_node<int>* t4 = new binary_tree_node<int>(40);
    binary_tree_node<int>* t5 = new binary_tree_node<int>(50);
    binary_tree_node<int>* t6 = new binary_tree_node<int>(60);
    binary_tree_node<int>* t7 = new binary_tree_node<int>(70);
    binary_tree_node<int>* t8 = new binary_tree_node<int>(80);
    binary_tree_node<int>* t9 = new binary_tree_node<int>(90);

    //start with root
    t5->set_left(t3);
    t5->set_right(t7);

    //left sub-tree
    t3->set_left(t2);
    t3->set_right(t4);
    t2->set_left(t1);

    //right sub-tree
    t7->set_left(t6);
    t7->set_right(t8);
    t8->set_right(t9);

    return t5;
}

template <class T>
std::list<T>* convert_to_list(binary_tree_node<T>* t, std::list<T>* list) {
    if(t != NULL) {
        list = convert_to_list(t ->left(), list);
        list ->push_back(t ->data());
        list = convert_to_list(t ->right(), list);
    }
    return list;
}

template <class T>
void print_list(const std::list<T>* list) {
    for(typename std::list<T>::const_iterator it = list ->begin(); it != list ->end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
