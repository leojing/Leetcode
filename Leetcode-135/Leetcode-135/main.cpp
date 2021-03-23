//
//  main.cpp
//  Leetcode-135
//
//  Created by Jing Luo on 3/23/21.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int candy(vector<int>& ratings) {
    int size = int(ratings.size());
    if (size < 2) {
        return size;
    }

    vector<int> candy(size, 1);
    // 从左往右，依次判断右边是否比左边高，如果是，更新右边糖果数+1，不能反过来更新左边，因为这样后面的更新会影响前面的结果导致不正确
    for (int i = 1; i < size; i ++) {
        if (ratings[i] > ratings[i-1]) {
            candy[i] = candy[i-1] + 1;
        }
    }
    // 从右往左，依次判断左边是否比右边高，如果是，更新左边
    for (int i = size - 1; i > 0; i --) {
        if (ratings[i] < ratings[i-1]) {
            candy[i-1] = max(candy[i-1], candy[i] + 1);
        }
    }
    
    return accumulate(candy.begin(), candy.end(), 0);
}

int main(int argc, const char * argv[]) {
    vector<int> ratings = {1,0,2,3,2,1,4,2,5,1,0,5};
    std::cout << candy(ratings) << "\n";
    return 0;
}
