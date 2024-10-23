#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

template <typename T>
class SimpleVector {
    private:
        T* array;
        int capacity;
        int size;
        void resize();

    public:
        // constructor and destrructor
        SimpleVector(int initialCapacity);
        SimpleVector(initializer_list<T> elements);
        ~SimpleVector();
        // operation overloading
        T& operator[](int index);
        // SimpleVector<T> operator+(SimpleVector<T>& rhs);
        SimpleVector<T>& operator+=(SimpleVector<T>& rhs);
        SimpleVector<T>& operator++();
        SimpleVector<T> operator++(int);
        SimpleVector<T>& operator<<(const T& element);
        bool operator==(SimpleVector<T>& rhs);
        bool operator<(SimpleVector<T>& rhs);
        operator bool() const;
        // range-based loops
        T* begin();
        T* end();
        // other functions
        void addElement(T element);
        int getSize() const;
};

template <typename T>
SimpleVector<T> operator+(SimpleVector<T>& lhs, SimpleVector<T>& rhs);
