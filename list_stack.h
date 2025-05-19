#pragma once
#include "stack.h"
#include "list_sequence.h"

template <typename T>
class List_stack : public Stack<T> {
protected:
    List_sequence<T>* list;

public:
    List_stack();
    List_stack(const List_sequence<T>& list1);
    List_stack(const List_stack& other);
    ~List_stack()  = default;
    
    void push(const T& value) override;
    T pop() override;
    T& top() override;
    const T& top() const override;
    bool is_empty() const override;
    bool is_full() const override;
    int size() const override;
    Stack<T>* clone() const override;
    void clear() override;
    void print_stack() const override;

    Stack<T>* concat(const Stack<T>& other) const override;
    Stack<T>* sub_stack(int start_ind, int end_ind) const override;

    bool operator==(const Stack<T>& other) const override;
};


template <typename T>
List_stack<T>::List_stack() { 
    list = new List_sequence<T>();
}

template <typename T>
List_stack<T>::List_stack(const List_sequence<T>& list1) {
    list = new List_sequence<T>(list1);
}

template <typename T>
List_stack<T>::List_stack(const List_stack& other) {
    list = new List_sequence<T>(*other.list);
}

template <typename T>
void List_stack<T>::push(const T& value) {
    list->append(value);
}

template <typename T>
T List_stack<T>::pop() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_CONTAINER);
        throw Error(Error::EMPTY_CONTAINER);
    }
    T top = list->get_last();
    list->remove(list->get_length() - 1);
    return top;
}

template <typename T>
T& List_stack<T>::top() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_CONTAINER);
        throw Error(Error::EMPTY_CONTAINER);
    }
    return (*list)[list->get_length()-1];
}

template <typename T>
const T& List_stack<T>::top() const {
    return const_cast<List_stack*>(this)->top();
}

template <typename T>
bool List_stack<T>::is_empty() const {
    return list->get_length() == 0;
}

template <typename T>
bool List_stack<T>::is_full() const {
    return false; 
}

template <typename T>
int List_stack<T>::size() const {
    return list->get_length();
}

template <typename T>
Stack<T>* List_stack<T>::clone() const {
    return new List_stack<T>(*this);
} 

template <typename T>
void List_stack<T>::print_stack() const {
    list->print_seq();
}

template <typename T>
void List_stack<T>::clear() {
    list->clear();
}

template <typename T>
Stack<T>* List_stack<T>::concat(const Stack<T>& other) const {
    Stack<T>* res_stack = new List_stack<T>(*this); 
    List_stack<T> tmp_stack;
    Stack<T>* other_copy = other.clone();

    while (!other_copy->is_empty()) {
        tmp_stack.push(other_copy->pop());
    }
    delete other_copy;
    
    while (!tmp_stack.is_empty()) {
        res_stack->push(tmp_stack.pop());
    }
    return res_stack;
}

template <typename T>
Stack<T>* List_stack<T>::sub_stack(int start_ind, int end_ind) const {
    if (start_ind < 0 || end_ind >= list->get_length() || start_ind > end_ind) {
        errors_detection(Error::INVALID_INDEX);
        throw Error(Error::INVALID_INDEX);
    }
    List_stack<T> stack_copy(*this);
    
    List_stack<T> tmp_stack;

    for (int i = list->get_length(); i > start_ind; i--) {
        tmp_stack.push(stack_copy.pop());
    }
    List_stack<T>* result = new List_stack<T>();
    
    for (int i = start_ind; i <= end_ind; i++) {
        result->push(tmp_stack.pop());
    }
    
    return result;
}
template <typename T>
bool List_stack<T>::operator==(const Stack<T>& other) const {
    const List_stack<T>& other_stack = dynamic_cast<const List_stack<T>&>(other);
    return *list == *other_stack.list;
}