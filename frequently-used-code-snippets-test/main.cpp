#include <iostream>
#include <vector>
#include <frequently-used-code-snippets.h>
using namespace std;

int main() {
    // ≤‚ ‘
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout << containsElementInVector(v, 4) << endl;
    printVector(v);
    cout << "------------------" << endl;

    // ≤‚ ‘
    addToVectorUnique(v, 1);
    addToVectorUnique(v, 2);
    addToVectorUnique(v, 5);
    addToVectorUnique(v, 6);
    printVector(v);
    cout << "------------------" << endl;

    // ≤‚ ‘
    map<int, int> mapp;
    addToMap(mapp, 1, 0);
    addToMap(mapp, 1, 1);
    addToMap(mapp, 2, 2);
    addToMap(mapp, 3, 3);
    addToMap(mapp, 4, 4);
    cout << "------------------" << endl;

    // ≤‚ ‘
    cout << containsKeyInMap(mapp, 1) << endl;
    cout << containsKeyInMap(mapp, 5) << endl;
    cout << "------------------" << endl;
}