
#include "Declarations.h"

template<typename T>
List<T>::List():list_head(nullptr),list_size(0){ cout<<endl;cout<<"List was created"<<endl;}

template<typename T>
List<T>::~List(){
    cout<<endl;
    cout<<"List was destroyed"<<endl;
    clear();
}

template<typename T>
T& List<T>::operator []( const int& search_index){
    int counter = 0;
    Node* current_node = list_head;
    while(true){
        if(counter == search_index)return current_node->node_data;
        current_node = current_node->next;
        ++counter;
    }
}

template<typename T>
void List<T>::push_back(T data){
    if(list_head == nullptr){
        list_head = new Node(data);
    }else{
        Node* current_node = list_head;
        while(true){
            if(current_node->next == nullptr){
                Node* new_node = new Node(data);
                current_node->next = new_node;
                break;
            }
            current_node = current_node->next;
        }
    }
    ++list_size;
}

template<typename T>
void List<T>::push_front(T data){
    list_head = new Node(data,list_head);
    ++list_size;
}

template<typename T>
void List<T>::pop_front() {
    Node* temporary =  list_head;
    list_head = list_head -> next;
    delete temporary;
    --list_size;
}

template<typename T>
void List<T>::pop_back() {
    remove_at(list_size - 1);
}

template<typename T>
void List<T>::insert(T data, int need_index){

    if(need_index == 0){
        push_front(data);
    }
    else{
        int counter = 0;
        Node* current_node = list_head;
        Node* new_node = new Node(data, nullptr);
        while(true){
            if(counter == (need_index-1)){
                new_node -> next = current_node->next;
                current_node-> next = new_node;
                break;
            }
            current_node = current_node -> next;
            ++counter;
        }
    }
   ++list_size;
}

template<typename T>
void List<T>::clear() {
    while (list_size) pop_front();
}

template<typename T>
void List<T>::print(List& list) const{
    cout<<endl<<endl;
    cout<<"---Your List Data: ";
    for (int i = 0; i <list.list_size; ++i) {
        cout<<list[i]<<setw(10);
    }
}

template<typename T>
void List<T>::remove_at(int need_index) {
    if (need_index == 0) {
        pop_front();
    } else {
        Node* previous_node = list_head;
        for (int i = 0; i < need_index - 1; ++i) {
            previous_node = previous_node -> next;
        }
        Node* node_to_delete = previous_node -> next;
        previous_node -> next = node_to_delete->next;
        delete node_to_delete;
        --list_size;
    }
}

