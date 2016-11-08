#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //int maxProfit(vector<int>& prices) {    // Time Limit Exceeded
    //    int max = 0;
    //    for (int i = 0; i < prices.size(); i++) {   // 卖出价格
    //        for (int j = 0; j < i; j++) {           // 买入价格
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
    //    // 找出最小买入价格
    //    for (int i = 0; i < size; i++) {
    //        if (prices[i] < minBuyPrice) {
    //            minBuyIndex = i;
    //            minBuyPrice = prices[i];
    //        }
    //    }
    //
    //    // 找出最大卖出价格
    //    for (int i = minBuyIndex + 1; i < size; i++) {
    //        if (prices[i] > maxSellPrice) {
    //            maxSellPrice = prices[i];
    //        }
    //    }
    //    
    //    // 计算利润
    //    int max_profit = maxSellPrice - minBuyPrice;
    //    return (max_profit > 0 ? max_profit : 0);
    //}

    int maxProfit3(vector<int>& prices) {   // Accepted
        int minBuyPrice = LONG_MAX;         // int 的最大值，保证所有元素都不大于 minBuyPrice
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            int currPrice = prices[i];
            // 更新 minBuyPrice
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