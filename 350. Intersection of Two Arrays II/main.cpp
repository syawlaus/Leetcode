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
            // ��ʽһ
            //for (MarkedNum mn1 : markedNums1) {             // �����⣬��Ϊ MarkedNum& mn1 �ͺ�
            //    if (! mn1.isMarked && mn1.num == ele2) {
            //        mn1.isMarked = true;
            //        intersec.push_back(mn1.num);
            //        break;
            //    }
            //}

            // ��ʽ��
            //for (int i1 = 0; i1 < markedNums1.size(); i1++) {
            //    MarkedNum mn1 = markedNums1[i1];            // �����⣬��Ϊ MarkedNum& mn1 �ͺ�
            //    if (! mn1.isMarked && mn1.num == ele2) {
            //        mn1.isMarked = true;
            //        intersec.push_back(mn1.num);
            //        cout << "            mn1 ��ַ��" << &mn1 << endl;
            //        cout << "markedNums1[i1] ��ַ��" << &markedNums1[i1] << endl << endl;
            //        break;
            //    }
            //}

            // ��ʽ��
            for (int i1 = 0; i1 < markedNums1.size(); i1++) {
                if (! markedNums1[i1].isMarked && markedNums1[i1].num == ele2) {
                    markedNums1[i1].isMarked = true;        // ��ȷ
                    intersec.push_back(markedNums1[i1].num);
                    cout << "markedNums1[i1] ��ַ��" << &markedNums1[i1] << endl;
                    break;
                }
            }
        }
        return intersec;
    }

private:
    // intersect ʹ��
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

    // intersect2 ʹ��
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
    // ��ʼ�� nums1
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(1);
    nums1.push_back(3);
    
    // ��ʼ�� nums2
    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(3);

    // ���� nums1, num2 ����
    Solution sol;
    vector<int> intersec = sol.intersect2(nums1, nums2);
    printVector(intersec);
}