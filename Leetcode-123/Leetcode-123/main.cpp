//
//  main.cpp
//  Leetcode-123
//
//  Created by Jing Luo on 8/17/20.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int sell1 = 0, sell2 = 0;
    for (int i = 0; i < prices.size(); i ++) {
        buy1 = min(buy1, prices[i]);
        sell1 = max(sell1, prices[i] - buy1);
        buy2 = min(buy2, prices[i] - sell1);
        sell2 = max(sell2, prices[i] - buy2);
    }
    
    return sell2;
}


int main(int argc, const char * argv[]) {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    std::cout << maxProfit(prices) << "\n";
    return 0;
}


// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
