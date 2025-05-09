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

    // virtual T& GetRear() = 0;
    // virtual const T& GetRear() const = 0;

    virtual bool is_empty() const = 0;
    virtual bool is_full() const = 0;
    virtual int count() const = 0;
    virtual void clear() = 0;
    virtual bool operator==(const Queue<T>& other) const = 0;

    // virtual Queue<T>* Concat(const Queue<T>& other) const = 0;
    // virtual Queue<T>* Subqueue(std::size_t start, std::size_t end) const = 0;

    // virtual bool ContainsSubqueue() const = 0;
    // virtual std::pair<Queue<T>*, Queue<T>*> Split() const = 0;

    // virtual Queue<T>* Where() const = 0;
    // virtual Queue<T>* Map() const = 0;
    // virtual T Reduce() const = 0;

    virtual ~Queue() = default;
   // virtual const char* type_name() const = 0;
    //virtual Queue<T>* clone() const = 0;

   /////////////////////////////////////////////////////////
    

};