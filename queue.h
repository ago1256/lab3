#pragma once
#include <cstddef>
#include"errors.h"

template<class T>
class Queue {
public:

    virtual void enqueue(const T& item) = 0;
    virtual T dequeue() = 0;
    virtual T& get_front() = 0;
    virtual const T& get_front() const = 0;

    virtual bool is_empty() const = 0;
    virtual bool is_full() const = 0;
    virtual int count() const = 0;
    virtual void clear() = 0;
    virtual bool operator==(const Queue<T>& other) const = 0;

    virtual Queue<T>* concat(const Queue<T>& other) const = 0;
    virtual Queue<T>* sub_queue(int start, int end) const = 0;

    virtual ~Queue() = default;
    virtual Queue<T>* clone() const = 0;
    virtual void print_queue() const= 0;

};