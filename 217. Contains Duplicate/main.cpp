#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mapp;
        for (int i : nums) {
            if (containsKey(mapp, i)) {
                return true;
            }
            else {
                mapp[i] = 1;
            }
        }
        return false;
    }

    bool containsKey(map<int, int>& mapp, int key) {
        map<int, int>::iterator iter = mapp.find(key);
        return iter != mapp.end();
    }
};

int main() {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 7};
    int len = sizeof(a) / sizeof(a[0]);
    vector<int> v(a, a + len);

    Solution sol;
    bool b = sol.containsDuplicate(v);
    cout << ((b == true) ? "true" : "false");
}