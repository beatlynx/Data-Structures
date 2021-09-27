//Samuel Elmer

#include <iostream>

using std::cout, std::endl;
template <typename T>
class Array {
    public:
        Array() : arr(nullptr), capacity(0), current_size(0) {}
        Array(int n) : arr(new T[n]), capacity(n), current_size(0) {}
        ~Array() {
            if(arr!=nullptr) delete[] arr;
        }
        Array(const Array<T>& b) {
            capacity = b.capacity;
            current_size = b.size;
            arr = new T(capacity);
            for(size_t i=0; i<current_size; i++) {
                arr[i] = b.arr[i];
            }
        }
        Array* operator=(const Array<int>& b) {
            return this;
        }
        T& operator[](int index) {
            if(index>=(int)current_size || index<0) {
                throw std::invalid_argument("Out of bounds.");
            }
            return arr[index];
        }
        int size() {
            return (int)current_size;
        };
        bool contains(T toFind) {
            if(find(toFind) == -1) return false;
            return true;
        };
        int find(T toFind) {
            for(size_t i=0; i<current_size; i++) {
                if(arr[i] == toFind) {
                    return i;
                }
            }
            return -1;
        };
        void insert(T toInsert) {
            if(current_size+1 >= capacity) {
                resize();
            }
            arr[current_size] = toInsert;
            current_size++;
        };
        bool remove(T toRemove) {
            int index = find(toRemove);
            if(index<0) return false;
                
            for(;index<(int)current_size; index++) {
                arr[index] = arr[index+1];
            }
            current_size--;
            return true;
        };
        bool empty() {
            if(current_size<1) return true;
            return false;
        }
        void print() {
            cout << "[";
            for(size_t i=0; i<current_size-1; i++) {
                cout << arr[i] << ", ";
            }
            cout << arr[current_size-1] << "]" << endl;
        }
    private:
        T* arr;
        size_t capacity;
        size_t current_size;
        void resize() {
            if(capacity==0) {
            capacity = 2;
            } else capacity *= 2;
            T* newarr = new T[capacity];
            for(size_t i=0; i<current_size; i++) {
                newarr[i] = arr[i];
            }
            if(arr!=nullptr) delete[] arr;
            arr = newarr;
        };
};