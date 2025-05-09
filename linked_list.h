#pragma once

#include "errors.h"
#include <stdio.h>
#include <stdexcept>

template <class T>
class Linked_list {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
        Node(T data, Node* next) : data(data), next(next) {}
    };

    Node* root;
    int size;

public:
    Linked_list();
    Linked_list(T* items, int count);
    Linked_list(int count);
    Linked_list(const Linked_list<T>& list);
    ~Linked_list();

    T get_first() const;
    T get_last() const;
    T get(int index) const;
    Linked_list<T>* get_sub_list(int start_index, int end_index) const;
    int get_length() const;

    void append(T item);
    void prepend(T item);
    void insert_at(T item, int index);
    void remove(int index);
    void print_list();
    Linked_list<T>* concat(Linked_list<T>* list);
    void clear();

    bool cycle_in_list();
    static Linked_list<T> create_cycle_list (const T* items, int size_list, int cycle_pos);
    T& operator[](int index);
    const T& operator[](int index) const;

};

template <class T>
Linked_list<T>::Linked_list() {
    root = nullptr;
    size = 0;
}

template <class T>
Linked_list<T>::Linked_list(int count){
    if (count < 0) {
        errors_detection(Error::INVALID_ARGUMENT); 
        throw Error(Error::INVALID_ARGUMENT);
    }
    if (count == 0) {
        root = nullptr;
        size = 0;
        return;
    }

    size = count;
    root = new Node{T(), nullptr}; 
    Node* curr = root;

    for (int i = 1; i < count; i++) {
        Node* new_node = new Node{T(), nullptr}; 
        curr->next = new_node;
        curr = new_node;
    }
}

template <class T>
Linked_list<T>::Linked_list(T* items, int count) {
    if (count < 0) {
        errors_detection(Error::INVALID_ARGUMENT); 
        throw Error(Error::INVALID_ARGUMENT);
    }

    if (count == 0) {
        root = nullptr;
        size = 0;
        return;
    }

    size = count;
    root = new Node{items[0], nullptr};
    Node* curr = root;

    for (int i = 1; i < count; i++) {
        Node* new_node = new Node{items[i], nullptr};
        curr->next = new_node;
        curr = new_node;
    }
}

template <class T>
Linked_list<T>::Linked_list(const Linked_list<T>& list) {
    if (list.root == nullptr) {
        root = nullptr;
        size = 0;
        return;
    }

    root = new Node{list.root->data, nullptr};
    Node* curr_this = root;
    Node* curr_other = list.root->next;

    while (curr_other != nullptr) {
        curr_this->next = new Node{curr_other->data, nullptr};
        curr_this = curr_this->next;
        curr_other = curr_other->next;
    }

    size = list.size;
}

template <class T>
Linked_list<T>::~Linked_list() {
    if (root == nullptr) return;

    Node* current = root;
    for (int i = 0; i < size && current != nullptr; ++i) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <class T>
T Linked_list<T>::get_first() const {
    if (root == nullptr) {
        errors_detection(Error::EMPTY_SEQ);
        throw Error(Error::EMPTY_SEQ);
    }
    return root->data;
}

template <class T>
T Linked_list<T>::get_last() const {
    if (root == nullptr) {
        errors_detection(Error::EMPTY_SEQ); 
        throw Error(Error::EMPTY_SEQ);
    }

    Node* curr = root;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    return curr->data;
}

template <class T>
T Linked_list<T>::get(int index) const {
    if (root == nullptr) {
        errors_detection(Error::EMPTY_SEQ);
        throw Error(Error::EMPTY_SEQ);
    }

    if (index < 0 || index >= size) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }

    Node* curr = root;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template <class T>
Linked_list<T>* Linked_list<T>::get_sub_list(int start_index, int end_index) const {
    if (start_index < 0 || end_index >= size || start_index > end_index) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }

    Linked_list<T>* sub_list = new Linked_list<T>();
    Node* curr = root;

    for (int i = 0; i < start_index; i++) {
        curr = curr->next;
    }

    sub_list->append(curr->data);

    for (int i = start_index + 1; i <= end_index; i++) {
        curr = curr->next;
        sub_list->append(curr->data);
    }

    return sub_list;
}

template <class T>
int Linked_list<T>::get_length() const {
    return size;
}

template <class T>
void Linked_list<T>::append(T item) {
    Node* new_node = new Node{item, nullptr};  
    if (root == nullptr) {
        root = new_node;
    } else {
        Node* curr = root;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    size++;
}

template <class T>
void Linked_list<T>::prepend(T item) {
    Node* new_node = new Node{item, root};
    root = new_node;
    size++;
}

template <class T>
void Linked_list<T>::insert_at(T item, int index) {
    if (index > size || index < 0) {
        errors_detection(Error::INVALID_INDEX);
        throw Error(Error::INVALID_INDEX);
    }

    if (index == 0) {
        prepend(item);
        return;
    }

    Node* curr = root;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    Node* new_node = new Node{item, curr->next};
    curr->next = new_node;
    size++;
}

template <class T>
void Linked_list<T>::remove(int index) {
    if (size == 0) {
        errors_detection(Error::EMPTY_SEQ); 
        throw Error(Error::EMPTY_SEQ);
    }
    
    if (index < 0 || index >= size) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }

    if (index == 0) {
        Node* temp = root;
        root = root->next;
        delete temp;
    } else {
        Node* curr = root;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    size--;
}

template <class T>
void Linked_list<T>::print_list() {
    Node* curr = root;
    std::cout << "[ ";
    while(curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "]";
}

template <class T>
Linked_list<T>* Linked_list<T>::concat(Linked_list<T>* list) {

    Linked_list<T>* result = new Linked_list<T>(*this);
    Node* curr = list->root;
    while (curr != nullptr) {
        result->append(curr->data);
        curr = curr->next;
    }
    return result;  
}

template <class T>
void Linked_list<T>::clear() {
    Node* current = root;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    root = nullptr;
    size = 0;
}

template <typename T>
bool Linked_list<T>::cycle_in_list() {
    if (root == nullptr || root->next == nullptr) {
        return false; 
    }
    Node* curr_1 = root;
    Node* curr_2 = root;
    while (curr_2 != nullptr && curr_2->next != nullptr) {
        curr_1 = curr_1->next;
        curr_2 = curr_2->next->next;

        if (curr_1 == curr_2) {
            return true;
        }
    }
    return false;
}

template <typename T>
Linked_list<T> Linked_list<T>::create_cycle_list(const T* items, int size_list, int cycle_pos) {
    Linked_list<T> list;
    if (size_list == 0) return list;

    list.root = new Node{items[0], nullptr};
    Node* curr = list.root;
    Node* cycle_node = (cycle_pos == 0) ? list.root : nullptr;

    for (int i = 1; i < size_list; ++i) {
        curr->next = new Node{items[i], nullptr};
        curr = curr->next;
        if (i == cycle_pos) {
            cycle_node = curr; 
        }
    }

    if (cycle_node != nullptr) {
        curr->next = cycle_node;
    }
    list.size = size_list;
    return list;
}

template <class T>
T& Linked_list<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        errors_detection(Error::INVALID_INDEX);
        throw Error(Error::INVALID_INDEX);
    }

    Node* curr = root;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template <class T>
const T& Linked_list<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        errors_detection(Error::INVALID_INDEX);
        throw Error(Error::INVALID_INDEX);
    }

    Node* curr = root;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

