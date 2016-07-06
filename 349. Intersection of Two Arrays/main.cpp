#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersec;
        for (int ele1 : nums1) {
            for (int ele2 : nums2) {
                if (ele2 == ele1) {
                    addToIntersec(ele2, intersec);
                }
            }
        }

        return intersec;
    }

    void addToIntersec(int addEle, vector<int>& intersec) {
        // ���ǰҪ���ж�û�и�����Ԫ���ظ�
        bool exist = false;
        for (int ele: intersec) {
            if (addEle == ele) {
                exist = true;
                break;
            }
        }

        // ��ӵ� intersec
        if (! exist) {
            intersec.push_back(addEle);
        }
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
    vector<int> intersec = sol.intersection(nums1, nums2);
    for (int ele : intersec) {
        cout << ele << ' ';
    }
}