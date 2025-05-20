#pragma once

#include "errors.h"
#include <stdio.h>
#include <stdexcept>


template <class T>
class Dynamic_array {
private:
    T* data;
    int size;

public:
    Dynamic_array(T* items, int count);
    Dynamic_array(int size);
    Dynamic_array(const Dynamic_array<T>& other);
    ~Dynamic_array();

    T get(int index) const;
    int get_size() const;

    void remove(int index);
    void set(int index, T value);
    void resize(int new_size, const T& value = T());
    Dynamic_array<T>* get_sub_array(int start_index, int end_index) const;
    void print_array(int n);
    T& operator[](int index);
    const T& operator[](int index) const;

};

template <class T>
Dynamic_array<T>::Dynamic_array(T* items, int count) {
    if (count < 0) {
        errors_detection(Error::INVALID_ARGUMENT);
        throw Error(Error::INVALID_ARGUMENT);
    }

    size = count;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = items[i];
}

template <class T>
Dynamic_array<T>::Dynamic_array(int size) {
    if (size < 0) {
        errors_detection(Error::INVALID_ARGUMENT); 
        throw Error(Error::INVALID_ARGUMENT);
    }

    this->size = size;
    data = new T[size];
}


template <class T>
Dynamic_array<T>::Dynamic_array(const Dynamic_array<T>& other) {
    size = other.size;
    data = new T[size];
    for (int i = 0; i < size; i++){
        data[i] = other.data[i];
        }
}

template <class T>
Dynamic_array<T>::~Dynamic_array() {
    delete[] data;
}

template <class T>
T Dynamic_array<T>::get(int index) const {
    if (index < 0 || index >= size) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }

    return data[index];
}

template <class T>
int Dynamic_array<T>::get_size() const {
    return size;
}

template <class T>
void Dynamic_array<T>::remove(int index) {
    if (size == 0) {
        errors_detection(Error::EMPTY_CONTAINER);
        throw Error(Error::EMPTY_CONTAINER);
    }
    if (index < 0 || index >= size && size != 0) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }
    if (index != size - 1) {
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
    }
    size--;  
}

template <class T>
void Dynamic_array<T>::set(int index, T value) {
    if (index < 0 || index >= size) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }
    data[index] = value;
}

template <class T>
void Dynamic_array<T>::resize(int new_size, const T& value) {
    if (new_size < 0) {
        errors_detection(Error::INVALID_ARGUMENT);
        throw Error(Error::INVALID_ARGUMENT);
    }
    if (new_size == 0) {
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }
    if (new_size < size) {
        size = new_size;  
        return;
    }

    if (new_size > size*2){
        new_size = size*2;
    }

    T* new_data = new T[new_size];

    int elements_to_copy = (new_size < size) ? new_size : size;
    for (int i = 0; i < elements_to_copy; i++) {
        new_data[i] = data[i];
    }
    for (int i = elements_to_copy; i < new_size; i++) {
        new_data[i] = value;
    }
    delete[] data;
    data = new_data;
    size = new_size;
}

template <class T>
Dynamic_array<T>* Dynamic_array<T>::get_sub_array(int start_index, int end_index) const {
    if (start_index < 0 || end_index >= size || start_index > end_index) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }

    int count = end_index - start_index + 1;
    T* sub_data = new T[count];

    for (int i = 0; i < count; i++) {
        sub_data[i] = data[start_index + i];
    }

    return new Dynamic_array<T>(sub_data, count);
}

template <class T>
void Dynamic_array<T>::print_array(int n) {
    std::cout << "[ ";
    for(int i = 0; i < n; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << "]";
}

template <class T>
T& Dynamic_array<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        errors_detection(Error::INVALID_INDEX); 
        throw Error(Error::INVALID_INDEX);
    }
    return data[index];
}

template <class T>
const T& Dynamic_array<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        errors_detection(Error::INVALID_INDEX);
        throw Error(Error::INVALID_INDEX);
    }
    return data[index];
}