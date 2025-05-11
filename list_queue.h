#pragma once
#include "queue.h"
#include "list_sequence.h"


template <typename T>
class List_queue : public Queue<T> {
protected:
    List_sequence<T>* list;

public:
    List_queue();
    List_queue(const List_queue& other);
    List_queue(const List_sequence<T>& list1);
    ~List_queue() override;

    void enqueue(const T& value) override;
    T dequeue() override;
    T& get_front() override;
    const T& get_front() const override;
    bool is_empty() const override;
    bool is_full() const override;
    int count() const override;
    void print_queue() const override;

    Queue<T>* concat(const Queue<T>& other) const;
    Queue<T>* sub_queue(int start_ind, int end_ind) const;
    Queue<T>* clone() const override;
    void clear() override;

    bool operator==(const Queue<T>& other) const override;
};

template <typename T>
List_queue<T>::List_queue() {
    list = new List_sequence<T>();
}

template <typename T>
List_queue<T>::List_queue(const List_sequence<T>& list1){
    list = new List_sequence<T>(list1);
}

template <typename T>
List_queue<T>::List_queue(const List_queue& other) {
    list = new List_sequence<T>(*other.list);
}

template <typename T>
List_queue<T>::~List_queue() {
    delete list;
}

template <typename T>
void List_queue<T>::enqueue(const T& value) {
    list->append(value);
}

template <typename T>
T List_queue<T>::dequeue() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_CONTAINER); 
        throw Error(Error::EMPTY_CONTAINER);
    }
    T front = list->get_index(0);
    list->remove(0);
    return front;
}

template <typename T>
T& List_queue<T>::get_front() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_CONTAINER); 
        throw Error(Error::EMPTY_CONTAINER);
    }
    return (*list)[0];
}

template <typename T>
const T& List_queue<T>::get_front() const {
    return const_cast<List_queue*>(this)->get_front();
}

template <typename T>
bool List_queue<T>::is_empty() const {
    return list->get_length() == 0;
}

template <typename T>
bool List_queue<T>::is_full() const {
    return false;
}

template <typename T>
int List_queue<T>::count() const {
    return list->get_length();
}

template <typename T>
Queue<T>* List_queue<T>::concat(const Queue<T>& other) const{
    Queue<T>* queue_res = new List_queue<T>(*this); ;
    Queue<T>* other_copy = other.clone();
    while(!(other_copy->is_empty())){
        queue_res->enqueue(other_copy->dequeue());
    }
    delete other_copy;
    return queue_res;
}

template <typename T>
Queue<T>* List_queue<T>::sub_queue(int start_ind, int end_ind) const{
    if (start_ind >= list->get_length()|| start_ind < 0 || end_ind >= list->get_length()|| end_ind < 0) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }
    List_queue<T>* queue_res = new List_queue<T>();
    for(int i = start_ind; i<=end_ind; i++){
        queue_res->enqueue((*list)[i]);
    }
    return queue_res;
}

template <typename T>
Queue<T>* List_queue<T>::clone() const{
    return new List_queue<T>(*this);
}

template <typename T>
void List_queue<T>::print_queue() const{
    list->print_seq();
}


template <typename T>
void List_queue<T>::clear() {
    list->clear();
}

template <typename T>
bool List_queue<T>::operator==(const Queue<T>& other) const {
    const List_queue<T>& other_queue = dynamic_cast<const List_queue<T>&>(other);
    return *list == *other_queue.list;

}