#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //int maxProfit(vector<int>& prices) {    // Time Limit Exceeded
    //    int max = 0;
    //    for (int i = 0; i < prices.size(); i++) {   // �����۸�
    //        for (int j = 0; j < i; j++) {           // ����۸�
    //            int profit = prices[i] - prices[j];
    //            if (profit > max) {
    //                max = profit;
    //            }
    //        }
    //    }
    //    return max;
    //}

    //int maxProfit2(vector<int>& prices) {   // Wrong Answer
    //    int size = prices.size();
    //    int minBuyIndex = -1;
    //    int minBuyPrice = LONG_MAX;
    //    int maxSellPrice = 0;
    //
    //    // �ҳ���С����۸�
    //    for (int i = 0; i < size; i++) {
    //        if (prices[i] < minBuyPrice) {
    //            minBuyIndex = i;
    //            minBuyPrice = prices[i];
    //        }
    //    }
    //
    //    // �ҳ���������۸�
    //    for (int i = minBuyIndex + 1; i < size; i++) {
    //        if (prices[i] > maxSellPrice) {
    //            maxSellPrice = prices[i];
    //        }
    //    }
    //    
    //    // ��������
    //    int max_profit = maxSellPrice - minBuyPrice;
    //    return (max_profit > 0 ? max_profit : 0);
    //}

    int maxProfit3(vector<int>& prices) {   // Accepted
        int minBuyPrice = LONG_MAX;         // int �����ֵ����֤����Ԫ�ض������� minBuyPrice
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            int currPrice = prices[i];
            // ���� minBuyPrice
            if (currPrice < minBuyPrice) {
                minBuyPrice = currPrice;
            }
            int profit = currPrice - minBuyPrice;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
        return max_profit;
    }
};

int main() {
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(100);
    prices.push_back(200);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    vector<int> prices2;
    prices2.push_back(7);
    prices2.push_back(6);
    prices2.push_back(4);
    prices2.push_back(3);
    prices2.push_back(1);

    Solution sol;
    cout << sol.maxProfit3(prices) << endl;
    cout << sol.maxProfit3(prices2) << endl;
}