#pragma once
#include"sequence.h"
#include"linked_list.h"
#include "errors.h"
#include <stdexcept>

template <typename T>
class List_sequence : public Sequence<T> {
protected:
    Linked_list<T>* list;
    Sequence<T>* seq_by_list(Linked_list<T>* list) const;

public:
    List_sequence();
    List_sequence(T* items, int count);
    List_sequence(int count_list);
    List_sequence(const List_sequence<T>& other);
    List_sequence(const Linked_list<T>& list);
    ~List_sequence() = default;

    T get_first() const override;
    T get_last() const override;
    T get_index(int index) const override;
    int get_length() const override;

    Sequence<T>* get_sub_sequence(int start_index, int end_index) const override;
    Sequence<T>* concat(const Sequence<T>* other) const override;

    Sequence<T>* append(T item) override;
    Sequence<T>* prepend(T item) override;
    Sequence<T>* insert_at(T item, int index) override;
    Sequence<T>* remove(int index) override;

    void print_seq() const;
    bool operator==(const Sequence<T>& other) const override;
    Sequence<T>& operator=(const Sequence<T>& other);
    T& operator[](int index);
    const T& operator[](int index) const;

    Sequence<T>* instance() override;
    void clear();
    Sequence<T>* clone() const override;
};


template <typename T>
Sequence<T>* List_sequence<T>::seq_by_list(Linked_list<T>* list) const {
    return new List_sequence<T>(*list);
}


template <typename T>
List_sequence<T>::List_sequence() {
    list = new Linked_list<T>();
}
template <typename T>
List_sequence<T>::List_sequence(int count_list) {
    list = new Linked_list<T>(count_list);
}

template <typename T>
List_sequence<T>::List_sequence(T* items, int count) {
    list = new Linked_list<T>(items, count);
}

template <typename T>
List_sequence<T>::List_sequence(const List_sequence<T>& other) {
    list = new Linked_list<T>(*other.list);
}

template <typename T>
List_sequence<T>::List_sequence(const Linked_list<T>& list) {
    this->list = new Linked_list<T>(list);
}


template <typename T>
T List_sequence<T>::get_first() const {
    return list->get_first();
}

template <typename T>
T List_sequence<T>::get_last() const {
    return list->get_last();
}

template <typename T>
T List_sequence<T>::get_index(int index) const {
    return list->get(index);
}

template <typename T>
int List_sequence<T>::get_length() const {
    return list->get_length();
}

template <typename T>
Sequence<T>* List_sequence<T>::get_sub_sequence(int start_index, int end_index) const {
    Linked_list<T>* sub = list->get_sub_list(start_index, end_index);
    return seq_by_list(sub);
}

template <typename T>
Sequence<T>* List_sequence<T>::concat(const Sequence<T>* other) const {
    List_sequence<T>* concat_seq = new List_sequence<T>(*this);
    for (int i = 0; i < other->get_length(); i++) {
        concat_seq->append(other->get_index(i));
    }
    return concat_seq;
}

template <typename T>
Sequence<T>* List_sequence<T>::append(T item) {
    list->append(item);
    return this;
}

template <typename T>
Sequence<T>* List_sequence<T>::prepend(T item) {
    list->prepend(item);
    return this;
}

template <typename T>
Sequence<T>* List_sequence<T>::insert_at(T item, int index) {
    list->insert_at(item, index);
    return this;
}

template <typename T>
Sequence<T>* List_sequence<T>::remove(int index) {
    if (list->get_length() == 0) {
        errors_detection(Error::EMPTY_CONTAINER);
        throw Error(Error::EMPTY_CONTAINER);
    }
    list->remove(index);
    return this;
}

template <typename T>
void List_sequence<T>::print_seq() const{
    list->print_list();
}


template <typename T>
Sequence<T>* List_sequence<T>::instance() {
    return this;
}

template <typename T>
void List_sequence<T>::clear() {
    if (list) {
        list->clear();  
    }
}

template <typename T>
Sequence<T>* List_sequence<T>::clone() const {
    return new List_sequence<T>(*this);
}

template <typename T>
bool List_sequence<T>::operator==(const Sequence<T>& other) const {
    if (this->get_length() != other.get_length()) {
        return false;
    }
    for (int i = 0; i < this->get_length(); ++i) {
        if (!(this->get_index(i) == other.get_index(i))) {
            return false;
        }
    }
    return true;
}

template <typename T>
Sequence<T>& List_sequence<T>::operator=(const Sequence<T>& other) {
    const List_sequence<T>* other_list_seq = dynamic_cast<const List_sequence<T>*>(&other);
    delete list;
    if (other_list_seq->list && other_list_seq->list->get_length() > 0) {
        list = new Linked_list<T>(*(other_list_seq->list)); 
    } else {
        list = new Linked_list<T>(); 
    }

    return *this;
}

template <typename T>
T& List_sequence<T>::operator[](int index) {
    if (index < 0 || index >= get_length()) {
        errors_detection(Error::INVALID_INDEX);
        throw Error(Error::INVALID_INDEX);
    }
    return (*list)[index]; 
}

template <typename T>
const T& List_sequence<T>::operator[](int index) const {
    if (index < 0 || index >= get_length()) {
        errors_detection(Error::INVALID_INDEX);
        throw Error(Error::INVALID_INDEX);
    }
    return (*list)[index]; 
}