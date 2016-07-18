#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        bool* marks = markNums(nums1);
        vector<int> intersec;
        for (int ele2 : nums2) {
            for (int i1 = 0; i1 < nums1.size(); i1++) {
                int ele1 = nums1[i1];
                if (! marks[i1] && ele1 == ele2) {
                    marks[i1] = true;
                    intersec.push_back(ele1);
                    break;
                }
            }
        }
        return intersec;
    }

private:
    bool* markNums(vector<int>& nums) {
        // new
        int size = nums.size();
        bool* marks = new bool[size];

        // init
        for (int i = 0; i < size; i++) {
            marks[i] = false;
        }
        return marks;
    }
};

void printVector(vector<int>& v) {
    for (int ele : v) {
        cout << ele << ' ';
    }
    cout << endl;
}

int main() {
    // 初始化 nums1
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(1);
    nums1.push_back(3);

    // 初始化 nums2
    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(3);

    // 计算 nums1, num2 交集
    Solution sol;
    vector<int> intersec = sol.intersect(nums1, nums2);
    printVector(intersec);
}