#include "study.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

using namespace std;

// initializer 
template<typename T>
SimpleVector<T>::SimpleVector(int initialCapacity):
size(0), capacity(initialCapacity) {
    array = new T[capacity];
}

template<typename T>
SimpleVector<T>::SimpleVector(initializer_list<T> elements):
size(0), capacity(elements.size()) {
    array = new T[capacity];
    for (auto element : elements) {
        addElement(element);
    }
}

// destructor
template <typename T>
SimpleVector<T>::~SimpleVector() {};

// operator overloading
template <typename T>
T& SimpleVector<T>::operator[](int index) {
    if (index <= size) {
        return array[index];
    } else {
        throw new out_of_range("out of range");
    }
}

// template <typename T>
// SimpleVector<T> SimpleVector<T>::operator+(SimpleVector& rhs) {
//     if (size != rhs.getSize()) {
//         throw runtime_error("simple vector size is not equal");
//     } else {
//         SimpleVector<T> result(size);
//         for (int i = 0; i<size; i++) {
//             result.addElement(array[i] + rhs[i]);
//         }
//         return result;
//     }
// }

template <typename  T>
SimpleVector<T> operator+(SimpleVector<T>& lhs, SimpleVector<T>& rhs) {
    if (lhs.getSize() != rhs.getSize()) {
        throw runtime_error("simple vector size is not equal");
    } else {
        SimpleVector<T> result(lhs.getSize());
        for (int i = 0; i < lhs.getSize(); i++) {
            result.addElement(lhs[i] + rhs[i]);
        }
        return result;
    }
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator+=(SimpleVector<T>& rhs) {
    if (size != rhs.getSize()) {
        throw runtime_error("simple vector size is not equal");
    } else {
        for (int i = 0; i < size; i++) {
            array[i] = array[i] + rhs[i];
        }
        return *this;
    }
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator++() {
    for (int i=0; i < size; i ++) {
        array[i] = array[i] + 1;
    }
    return *this;
}

template <typename T>
SimpleVector<T> SimpleVector<T>::operator++(int) {
    SimpleVector<T> temp(size);
    for (int i = 0; i < size; i++) {
        temp.addElement(array[i]);
        array[i] = array[i] + 1;
    }
    return temp;
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator<<(const T& element) {
    addElement(element);
    return *this;
}

template <typename T>
bool SimpleVector<T>::operator==(SimpleVector<T>& rhs) {
    if (size != rhs.getSize()) {
        return false;
    } else {
        for (int i = 0; i < size; i++) {
            if (array[i] != rhs[i]) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool SimpleVector<T>::operator<(SimpleVector<T>& rhs) {
    return size < rhs.getSize();
}

template <typename T>
SimpleVector<T>::operator bool() const {
    return size > 0;
}

// range-based loops
template <typename T>
T* SimpleVector<T>::begin() {
    return array;
}

template <typename T>
T* SimpleVector<T>::end() {
    return array + size;
}

// other functions
template<typename T>
void SimpleVector<T>::addElement(T element) {
    if (size == capacity) {
        resize();
    } 
    array[size] = element;
    size++;
}

template<typename T>
int SimpleVector<T>::getSize() const {
    return size;
}

template<typename T>
void SimpleVector<T>::resize() {
    capacity = capacity * 2;
    T* newArray = new T[capacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

int main(void) {
    SimpleVector<int> vec1 = {5, 6, 7, 8};
    SimpleVector<int> vec2 = {1, 2, 3, 4};

    SimpleVector<int> addVec = vec1+ vec2;

    for (auto av : addVec) {
        cout << av << endl;
    }

    return 0;
}
