#include <vector>
#include <frequently-used-code-snippets.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        return robRecur(nums, nums.size(), 0);
    }

    int rob2(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return MAX_TWO(nums[0], nums[1]);
        }

        // 新建数组保存 R(n)
        int *R = new int[len];
        R[0] = nums[0];
        R[1] = MAX_TWO(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            R[i] = MAX_TWO(nums[i] + R[i - 2], R[i - 1]);
        }

        return R[len - 1];
    }

private:
    int robRecur(vector<int>& nums,
                 int numsSize,
                 int index) {
        int size = numsSize - index;

        // 没有元素
        if (size <= 0) {
            return 0;
        }

        // 一个元素
        if (size == 1) {
            return nums[index];
        }

        // 两个元素
        int a = nums[index];
        int b = nums[index + 1];
        if (size == 2) {
            return MAX_TWO(a, b);
        }

        // 多个元素
        int sum1 = a + robRecur(nums, numsSize, index + 2);
        int sum2 = b + robRecur(nums, numsSize, index + 3);
        return MAX_TWO(sum1, sum2);
    }
};

int main() {
    int array[] = {
        226, 174, 214, 16, 218, 48, 153, 131, 128, 17, 157, 142,
        88, 43, 37, 157, 43, 221, 191, 68, 206, 23, 225, 82, 54,
        118, 111, 46, 80, 49, 245, 63, 25, 194, 72, 80, 143, 55,
        209, 18, 55, 122, 65, 66, 177, 101, 63, 201, 172, 130,
        103, 225, 142, 46, 86, 185, 62, 138, 212, 192, 125, 77,
        223, 188, 99, 228, 90, 25, 193, 211, 84, 239, 119, 234,
        85, 83, 123, 120, 131, 203, 219, 10, 82, 35, 120, 180,
        249, 106, 37, 169, 225, 54, 103, 55, 166, 124
    };

    vector<int> v = convertArrayToVector(array, ARRAY_LENGTH(array));

    Solution sol;
    //cout << sol.rob(v) << endl;
    cout << sol.rob2(v) << endl;
}