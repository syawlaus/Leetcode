#include <frequently-used-code-snippets.h>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        bool* marks = markNumsArr(nums1);
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

    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        vector<MarkedNum> markedNums1 = markNumsVec(nums1);
        vector<int> intersec;
        for (int ele2 : nums2) {
            // 方式一
            //for (MarkedNum mn1 : markedNums1) {             // 有问题，改为 MarkedNum& mn1 就好
            //    if (! mn1.isMarked && mn1.num == ele2) {
            //        mn1.isMarked = true;
            //        intersec.push_back(mn1.num);
            //        break;
            //    }
            //}

            // 方式二
            //for (int i1 = 0; i1 < markedNums1.size(); i1++) {
            //    MarkedNum mn1 = markedNums1[i1];            // 有问题，改为 MarkedNum& mn1 就好
            //    if (! mn1.isMarked && mn1.num == ele2) {
            //        mn1.isMarked = true;
            //        intersec.push_back(mn1.num);
            //        cout << "            mn1 地址：" << &mn1 << endl;
            //        cout << "markedNums1[i1] 地址：" << &markedNums1[i1] << endl << endl;
            //        break;
            //    }
            //}

            // 方式三
            for (int i1 = 0; i1 < markedNums1.size(); i1++) {
                if (! markedNums1[i1].isMarked && markedNums1[i1].num == ele2) {
                    markedNums1[i1].isMarked = true;        // 正确
                    intersec.push_back(markedNums1[i1].num);
                    cout << "markedNums1[i1] 地址：" << &markedNums1[i1] << endl;
                    break;
                }
            }
        }
        return intersec;
    }

private:
    // intersect 使用
    bool* markNumsArr(vector<int>& nums) {
        // new
        int size = nums.size();
        bool* marks = new bool[size];

        // init
        for (int i = 0; i < size; i++) {
            marks[i] = false;
        }
        return marks;
    }

    // intersect2 使用
    struct MarkedNum {
        int num;
        bool isMarked;
    };

    vector<MarkedNum> markNumsVec(vector<int>& nums) {
        int size = nums.size();
        vector<MarkedNum> markedNums(size);
        for (int i = 0; i < nums.size(); i++) {
            markedNums[i].num = nums[i];
            markedNums[i].isMarked = false;
        }
        return markedNums;
    }
};

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
    nums2.push_back(2);
    nums2.push_back(3);

    // 计算 nums1, num2 交集
    Solution sol;
    vector<int> intersec = sol.intersect2(nums1, nums2);
    printVector(intersec);
}