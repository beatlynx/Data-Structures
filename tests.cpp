#include "array.h"
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

    return 0;
}