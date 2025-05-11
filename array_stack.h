#pragma once
#include "stack.h"
#include "array_sequence.h"

template <typename T>
class Array_stack : public Stack<T> {
protected:
    Array_sequence<T>* items;

public:
    Array_stack();
    Array_stack(const Array_stack& other);
    Array_stack(const Array_sequence<T>& array);
    ~Array_stack() override;
    
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
Array_stack<T>::Array_stack() {
    items = new Array_sequence<T>(); 
}

template <typename T>
Array_stack<T>::Array_stack(const Array_sequence<T>& array) {
    items = new Array_sequence<T>(array);
}

template <typename T>
Array_stack<T>::Array_stack(const Array_stack& other) {
    items = new Array_sequence<T>(*other.items);
}

template <typename T>
Array_stack<T>::~Array_stack() {
    delete items;
}

template <typename T>
void Array_stack<T>::push(const T& value) {
    items->append(value);
}

template <typename T>
T Array_stack<T>::pop() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_CONTAINER);
        throw Error(Error::EMPTY_CONTAINER);
    }
    T top = items->get_index(items->get_length() - 1);
    items->remove(items->get_length() - 1);
    return top;
}

template <typename T>
T& Array_stack<T>::top() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_CONTAINER);
        throw Error(Error::EMPTY_CONTAINER);
    }
    return (*items)[items->get_length()-1];
}
template <typename T>
const T& Array_stack<T>::top() const {
    return const_cast<Array_stack*>(this)->top();
}

template <typename T>
bool Array_stack<T>::is_empty() const {
    return items->get_length() == 0;
}

template <typename T>
bool Array_stack<T>::is_full() const {
    return false; 
}

template <typename T>
int Array_stack<T>::size() const {
    return items->get_length();
}

template <typename T>
void Array_stack<T>::clear() {
    items->clear();
}

template <typename T>
void Array_stack<T>::print_stack() const {
    items->print_seq();
}

template <typename T>
Stack<T>* Array_stack<T>::clone() const {
    return new Array_stack<T>(*this);
}

template <typename T>
Stack<T>* Array_stack<T>::concat(const Stack<T>& other) const {
    Stack<T>* res_stack = new Array_stack<T>(*this); 
    Array_stack<T> tmp_stack;
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
Stack<T>* Array_stack<T>::sub_stack(int start_ind, int end_ind) const {
    if (start_ind < 0 || end_ind >= items->get_length() || start_ind > end_ind) {
        errors_detection(Error::INVALID_INDEX);
        throw Error(Error::INVALID_INDEX);
    }
    Array_stack<T> stack_copy(*this);
    
    Array_stack<T> tmp_stack;

    for (int i = items->get_length(); i > start_ind; i--) {
        tmp_stack.push(stack_copy.pop());
    }
    Array_stack<T>* result = new Array_stack<T>();
    
    for (int i = start_ind; i <= end_ind; i++) {
        result->push(tmp_stack.pop());
    }
    
    return result;
}

template <typename T>
bool Array_stack<T>::operator==(const Stack<T>& other) const {
    const Array_stack<T>& other_stack = dynamic_cast<const Array_stack<T>&>(other);
    return *items == *other_stack.items;
}