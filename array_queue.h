#pragma once
#include "queue.h"
#include "array_sequence.h"

template <typename T>
class Array_queue : public Queue<T> {
protected:
    Array_sequence<T>* items;

public:
    Array_queue();
    Array_queue(const Array_queue& other);
    Array_queue(const Array_sequence<T>& array);
    ~Array_queue() override;

    void enqueue(const T& value) override;
    T dequeue() override;
    T& get_front() override;
    const T& get_front() const override;
    bool is_empty() const override;
    bool is_full() const override;
    int count() const override;
    Queue<T>* clone() const override;
    void print_queue() const override;

    Queue<T>* concat(const Queue<T>& other) const;
    Queue<T>* sub_queue(int start, int end) const;
    void clear() override;
    bool operator==(const Queue<T>& other) const override;
};


template <typename T>
Array_queue<T>::Array_queue() {
    items = new Array_sequence<T>();
}

template <typename T>
Array_queue<T>::Array_queue(const Array_sequence<T>& array){
    items = new Array_sequence<T>(array);
}

template <typename T>
Array_queue<T>::Array_queue(const Array_queue& other) {
    items = new Array_sequence<T>(*other.items);
}

template <typename T>
Array_queue<T>::~Array_queue() {
    delete items;
}

template <typename T>
void Array_queue<T>::enqueue(const T& value) {
    items->append(value);
}

template <typename T>
T Array_queue<T>::dequeue() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_CONTAINER);
        throw Error(Error::EMPTY_CONTAINER);
    }
    T front = items->get_index(0);
    items->remove(0);
    return front;
}

template <typename T>
T& Array_queue<T>::get_front() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_CONTAINER);
        throw Error(Error::EMPTY_CONTAINER);
    }
    return (*items)[0];
}

template <typename T>
const T& Array_queue<T>::get_front() const {
    return const_cast<Array_queue*>(this)->get_front();
}

template <typename T>
bool Array_queue<T>::is_empty() const {
    return items->get_length() == 0;
}

template <typename T>
bool Array_queue<T>::is_full() const {
    return false;
}

template <typename T>
int Array_queue<T>::count() const {
    return items->get_length();
}

template <typename T>
void Array_queue<T>::clear() {
    items->clear();
}

template <typename T>
Queue<T>* Array_queue<T>::concat(const Queue<T>& other) const{
    Queue<T>* queue_res = new Array_queue<T>(*this); 
    Queue<T>* other_copy = other.clone();
    while(!(other_copy->is_empty())){
        queue_res->enqueue(other_copy->dequeue());
    }
    delete other_copy;
    return queue_res;
}

template <typename T>
Queue<T>*  Array_queue<T>::sub_queue(int start_ind, int end_ind) const{
    if (start_ind >= items->get_length()|| start_ind < 0 || end_ind >= items->get_length()|| end_ind < 0) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }
    Array_queue<T>* queue_res = new Array_queue<T>();
    for(int i = start_ind; i<=end_ind; i++){
        queue_res->enqueue((*items)[i]);
    }
    return queue_res;
}

template <typename T>
void Array_queue<T>::print_queue() const {
    items->print_seq();
}

template <typename T>
Queue<T>* Array_queue<T>::clone() const{
    return new Array_queue<T>(*this);
}

template <typename T>
bool Array_queue<T>::operator==(const Queue<T>& other) const {
    const Array_queue<T>& other_queue = dynamic_cast<const Array_queue<T>&>(other);
    return *items == *other_queue.items;
   
}

