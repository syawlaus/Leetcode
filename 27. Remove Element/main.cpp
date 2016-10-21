#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ) {
            if (*iter == val) {
                iter = nums.erase(iter);
            }
            else {
                iter++;
            }
        }
        return nums.size();
    }
};

int main() {
    vector<int> nums = { 3, 2, 2, 3 };
    int val = 3;

    Solution sol;
    cout << sol.removeElement(nums, val) << endl;
}