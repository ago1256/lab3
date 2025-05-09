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
        errors_detection(Error::EMPTY_SEQ); 
        throw Error(Error::EMPTY_SEQ);
    }
    T front = list->get_index(0);
    list->remove(0);
    return front;
}

template <typename T>
T& List_queue<T>::get_front() {
    if (is_empty()) {
        errors_detection(Error::EMPTY_SEQ); 
        throw Error(Error::EMPTY_SEQ);
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
void List_queue<T>::clear() {
    list->clear();
}

template <typename T>
bool List_queue<T>::operator==(const Queue<T>& other) const {
    const List_queue<T>& other_queue = dynamic_cast<const List_queue<T>&>(other);
    return *list == *other_queue.list;

}