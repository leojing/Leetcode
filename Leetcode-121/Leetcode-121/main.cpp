//
//  main.cpp
//  Leetcode-121
//
//  Created by Jing Luo on 9/8/20.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = INT_MAX;
    int sell = 0;
    for (int i = 0; i < prices.size(); i ++) {
        buy = min(buy, prices[i]);
        sell = max(sell, prices[i]-buy);
    }
    return sell;
}

int main(int argc, const char * argv[]) {
    vector<int> prices = {7,6,4,3,1};//{7,1,5,3,6,4};
    std::cout << maxProfit(prices) << "\n";
    return 0;
}
