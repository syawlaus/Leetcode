#include <frequently-used-code-snippets.h>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> backup1 = copyInitVector(nums1, m);
        nums1.clear();

        int i1 = 0;
        int i2 = 0;
        while (i1 < backup1.size() && i2 < n) {
            if (backup1[i1] < nums2[i2]) {
                nums1.push_back(backup1[i1]);
                i1++;
            }
            else {
                nums1.push_back(nums2[i2]);
                i2++;
            }
        }
        if (i1 >= backup1.size()) {     // backup1 先遍历完，把 nums2 剩下的元素添加到 nums1
            for (; i2 < n; i2++) {
                nums1.push_back(nums2[i2]);
            }
        }
        if (i2 >= n) {       // nums2 先遍历完，把 backup1 剩下的元素添加到 nums1
            for (; i1 < backup1.size(); i1++) {
                nums1.push_back(backup1[i1]);
            }
        }
    }

private:
    vector<int> copyInitVector(vector<int>& v, int initNum) {
        vector<int> copyV;
        for (int i = 0; i < initNum; i++) {
            copyV.push_back(v[i]);
        }
        return copyV;
    }
};

int main() {
    int arr1[] = { 0 };
    vector<int> nums1 = convertArrayToVector(arr1, ARRAY_LENGTH(arr1));

    int arr2[] = { 1 };
    vector<int> nums2 = convertArrayToVector(arr2, ARRAY_LENGTH(arr2));

    Solution sol;
    sol.merge(nums1, 0, nums2, 1);
    printVector(nums1);
}