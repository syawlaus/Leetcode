#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            // ��¼��ǰ�� 0 Ԫ����Ҫ��ǰ���ǵ�λ��
            if (nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }

        // �� index ��ʼ������ĩβ��ȫ���� 0 ����
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