#include <vector>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        return robRecur(nums, nums.size(), 0);
    }

private:
    int robRecur(vector<int>& nums,
                 int numsSize,
                 int index) {
        int size = numsSize - index;

        // û��Ԫ��
        if (size <= 0) {
            return 0;
        }

        // һ��Ԫ��
        if (size == 1) {
            return nums[index];
        }

        // ����Ԫ��
        int a = nums[index];
        int b = nums[index + 1];
        if (size == 2) {
            return MAX_TWO(a, b);
        }

        // ���Ԫ��
        int sum1 = a + robRecur(nums, numsSize, index + 2);
        int sum2 = b + robRecur(nums, numsSize, index + 3);
        return MAX_TWO(sum1, sum2);
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    Solution sol;
    cout << sol.rob(v) << endl;
}