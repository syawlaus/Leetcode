#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            // 记录当前非 0 元素需要往前覆盖的位置
            if (nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }

        // 从 index 开始到数据末尾，全部用 0 覆盖
        for (int j = index; j < size; j++) {
            nums[j] = 0;
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);

    Solution sol;
    sol.moveZeroes(nums);
    
    for (int ele : nums) {
        cout << ele << ' ';
    }
}