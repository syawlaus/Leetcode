#include <frequently-used-code-snippets.h>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mapp;

        // 遍历数组，添加到 mapp
        for (int i : nums) {
            incrementKeyCountInMap(mapp, nums[i]);
        }

        // 遍历 mapp，找出 majority element
        int majorityEle;
        int max = 0;
        for (map<int, int>::iterator iter = mapp.begin(); iter != mapp.end(); iter++) {
            int key = iter->first;
            int val = iter->second;

            if (val > max) {
                max = val;
                majorityEle = key;
            }
        }
        return majorityEle;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(4);

    Solution sol;
    cout << sol.majorityElement(nums) << endl;
}