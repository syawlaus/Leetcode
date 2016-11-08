#include <frequently-used-code-snippets.h>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersec;
        for (int ele1 : nums1) {
            for (int ele2 : nums2) {
                if (ele2 == ele1) {
                    addToVectorUnique(intersec, ele2);
                }
            }
        }
        return intersec;
    }
};

int main() {
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);

    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(2);

    Solution sol;
    printVector(sol.intersection(nums1, nums2));
}