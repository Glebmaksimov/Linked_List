#ifndef MAIN_CPP_DECLARATIONS_H
#define MAIN_CPP_DECLARATIONS_H
#include <iomanip>
#include <iostream>
#include <memory>
using namespace std;
template<typename T>
class List{

private:
    class Node{

    public:

        T node_data;
        Node *next;
        explicit  Node(T _node_data = T(),Node* _next = nullptr):node_data(std::move(_node_data)),next(_next){}

    };

    Node* list_head;
    int list_size;

public:
    List();
    ~List();

    void pop_front();
    void pop_back();
    void clear();
    void print(List& list) const;
    void push_back(T data);
    void insert(T data,int need_index);
    void remove_at(int need_index);
    void push_front(T data);
    int  size(){return list_size;}

    T& operator []( const int& index);

};
#include "Implementations.hpp"
#endif
