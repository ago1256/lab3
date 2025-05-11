#pragma once
#include "errors.h"
#include <stdexcept>

template <class T>
class Stack {
public:

    virtual void push(const T& item) = 0; 
    virtual T pop() = 0;                
    virtual T& top() = 0;                  
    virtual const T& top() const = 0;  
    virtual ~Stack() = default;    
    
    virtual bool is_empty() const = 0;
    virtual bool is_full() const = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual bool operator==(const Stack<T>& other) const = 0;
    virtual Stack<T>* concat(const Stack<T>& other) const = 0;
    virtual Stack<T>* sub_stack(int start_ind, int end_ind) const = 0;
    virtual void print_stack() const= 0;

    virtual Stack<T>* clone() const = 0;

};