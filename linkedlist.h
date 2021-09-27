#include <iostream>

using std::cout, std::endl;

template <typename T>
struct Node {
    Node* next;
    T val;
    Node() : next(nullptr), val(T()) {}
    Node(T a) : next(nullptr), val(a) {}
    Node(Node* n, T a) : next(n), val(a) {}
};

template <typename T>
class LinkedList {
    public:
        LinkedList() : head(nullptr), current_size(0) {}
        ~LinkedList() {
            clear(head);
        }
        LinkedList(const LinkedList& l) : head(copy_node(l->head)), current_size(l.current_size) {}
        int size() {
            return current_size;
        }
        void insert(T toInsert) {
            Node<T>* n = new Node<T>(toInsert);
            n->next = head;
            head = n;
            current_size++;
        }
        bool remove(T toRemove) {
            if(!contains(toRemove)) return false;
            if(empty()) return false;
            Node<T>* curr = head->next;
            Node<T>* prev = head;
            while(curr) {
                if(curr->val == toRemove) {
                    prev->next = curr->next;
                    delete curr;
                    current_size--;
                    return true;
                }
                prev = curr;
                curr = curr->next;
            }
            return false;
        }
        bool contains(T toFind) {
            Node<T>* curr = head;
            while(curr) {
                if(curr->val==toFind) return true;
                curr = curr->next;
            }
            return false;
        }
        LinkedList* operator=(const LinkedList& l) {
            return this;
        }
        bool empty() {
            if(!head) return true;
            return false;
        }
        void print() {
            if(empty()) cout << "Empty" << endl;
            Node<T>* curr = head;
            while(curr->next) {
                cout << "(" << curr->val << ")->";
                curr = curr->next;
            }
            cout << "(" << curr->val << ")" << endl;
        }
    private:
        Node<T>* head;
        size_t current_size;
        Node<T>* copy_node(Node<T>* n) {
            if(n==nullptr) return nullptr;
            else return new Node(copy_node(n->next), n->val);
        }
        bool clear(Node<T>* n) {
            if(!n) return true;
            else {
                Node<T>* temp = n->next;
                delete n;
                return clear(temp);
            }
        }
};