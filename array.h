//Samuel Elmer

#include <iostream>

template <typename T>
class Array {
    Array<T>() {
        arr = nullptr;
        capacity = 0;
        current_size = 0;
    }
    Array<T>(int n) {
        arr = new T(n);
        capacity = n;
        current_size = 0;
    }
    ~Array<T>() {
        delete[] arr;
    }
    Array<T>(const Array<T>& b) {
        capacity = b.capacity;
        current_size = b.size;
        arr = new T(capacity);
        for(size_t i=0; i<current_size; i++) {
            arr[i] = b.arr[i];
        }
    }
    private:
        T* arr;
        size_t capacity;
        size_t current_size;
        void resize();
    public:
        int size();
        bool contains(T toFind);
        int find(T toFind);
        void insert(T toInsert);
        bool remove(T toRemove);
};