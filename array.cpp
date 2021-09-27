#include "array.h"

template <typename T>
int Array<T>::size() {
    return current_size;
}

template <typename T>
int Array<T>::find(T toFind) {
    for(int i=0; i<current_size; i++) {
        if(arr[i] == toFind) {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool Array<T>::contains(T toFind) {
    if(find(toFind) == -1) return false;
    return true;
}

template <typename T>
void Array<T>::insert(T toInsert) {
    if(current_size+1 >= capacity) {
        resize();
    }
    arr[current_size] = toInsert;
    current_size++;
}

template <typename T>
bool Array<T>::remove(T toRemove) {
    int index = find(toRemove);
    if(index<0) return false;
    
    for(;index<current_size; index++) {
        arr[index] = arr[index+1];
    }
    current_size--;
    return true;
}

template <typename T>
void Array<T>::resize() {
    if(capacity==0) {
        capacity = 2;
    } else capacity *= 2;
    T* newarr = new T(capacity);
    for(size_t i=0; i<current_size; i++) {
        newarr[i] = arr[i];
    }
    delete[] arr;
    arr = newarr;
}