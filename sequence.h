#pragma once

template <class T>
class Sequence {
public:
virtual ~Sequence() = default;

virtual T get_first() const = 0;
virtual T get_last() const = 0;
virtual T get_index(int index) const = 0;
virtual int get_length() const = 0;
virtual Sequence<T>* get_sub_sequence(int start_index, int end_index) const = 0;

virtual Sequence<T>* remove(int index) = 0;

virtual Sequence<T>* append(T item) = 0;
virtual Sequence<T>* prepend(T item) = 0;
virtual Sequence<T>* insert_at(T item, int index) = 0;
virtual Sequence<T>* concat(const Sequence<T>* list) const = 0;

virtual void print_seq() const= 0;

virtual Sequence<T>* instance() = 0;
virtual Sequence<T>* clone() const = 0;
virtual bool operator==(const Sequence<T>& other) const = 0;
virtual Sequence<T>& operator=(const Sequence<T>& other) = 0; 

};
