#include <frequently-used-code-snippets.h>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (; k > 0; k--) {
            for (int i = 0, j = k; j < nums.size(); i++, j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            int val = i;
            map<int, int>::iterator iter = m.find(key);     // O(logN)
            if (iter != m.end()) {   // 找到重复元素
                if (val - iter->second <= k) {
                    return true;
                }
                else {
                    iter->second = val;
                }
            }
            else {      // 没找到重复元素
                m[key] = val;
            }
        }
        return false;
    }
};

int main() {
    int array[] = { 1, 2, 1 };
    vector<int> nums = convertArrayToVector(array, ARRAY_LENGTH(array));

    Solution sol;
    cout << sol.containsNearbyDuplicate2(nums, 0);
}