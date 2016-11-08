#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mapp;
        for (int i : nums) {
            if (containsKeyInMap(mapp, i)) {
                return true;
            }
            else {
                mapp[i] = 1;
            }
        }
        return false;
    }
};

int main() {
    int a[] = { 1, 2, 3, 4, 5, 6, 7};
    int len = ARRAY_LENGTH(a);
    vector<int> v(a, a + len);

    Solution sol;
    bool b = sol.containsDuplicate(v);
    cout << ((b == true) ? "true" : "false") << endl;
}