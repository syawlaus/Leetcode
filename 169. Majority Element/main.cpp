#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mapp;

        // 遍历数组，添加到 mapp
        for (int i : nums) {
            addToMap(i, mapp);
        }

        // 遍历 mapp，找出 majority element
        int majorityEle;
        int max = 0;
        for (map<int, int>::iterator iter = mapp.begin(); iter != mapp.end(); iter++) {
            int key = iter->first;
            int val = iter->second;

            if (val > max) {
                max = val;
                majorityEle = key;
            }
        }

        return majorityEle;
    }

    void addToMap(int key, map<int, int>& mapp) {
        map<int, int>::iterator iter = mapp.find(key);

        // 找到 key
        if (iter != mapp.end()) {
            (iter->second)++;
        }
        // 找不到 key
        else {
            mapp[key] = 1;
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(4);

    Solution sol;
    cout << sol.majorityElement(nums) << endl;
}