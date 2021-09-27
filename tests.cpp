#include "array.h"
#include "linkedlist.h"
#include <iostream>
#include <vector>

using std::cout, std::endl;

int main() {

    cout << "Test" << endl;

    Array<int> a;

    cout << a.size() << endl;

    cout << a.empty() << endl;

    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);

    cout << a.size() << endl;

    a.print();

    a.remove(3);

    cout << a.size() << endl;

    a.print();

    cout << a[0] << endl;

    a[0] = 100;

    a.print();

    LinkedList<int> l;

    for(int i=0; i<15; i++) {
        l.insert(i);
    }

    l.print();

    cout << l.size() << endl;

    l.remove(8);

    l.remove(12);

    l.print();

    return 0;
}