#include <iostream>
#include "KAVector.h"
#include "KAVector.cpp"
using namespace std;

int main() {
    KAVector<int> v(10), v2;
    for (int i = 0; i < v.size(); ++i) {
        v[i] = i + 1;
    }
    try
    {
        v2 = v;
        v2.insert(v2.begin() + 10, 5);
        cout << v2;
    }
    catch (const char* s)
    {
        cout << "Exception : " << s << endl;
    }

    return 0;
}
