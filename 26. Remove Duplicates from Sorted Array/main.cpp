#include <frequently-used-code-snippets.h>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        for (vector<int>::iterator iter = nums.begin() + 1; iter != nums.end(); ) {
            if (*iter == *(iter - 1)) {
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
    int array[] = { 1, 1, 2, 2, 3, 3, 4, 5, 6 };
    vector<int> nums = convertArrayToVector(array, ARRAY_LENGTH(array));

    Solution sol;
    int newLength = sol.removeDuplicates(nums);
    printVector(nums);
    cout << "new length: " << newLength << endl;
}