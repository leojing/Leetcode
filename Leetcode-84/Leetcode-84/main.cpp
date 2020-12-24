//
//  main.cpp
//  Leetcode-84
//
//  Created by Jing Luo on 12/24/20.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = (int)heights.size(), result = 0;
    stack<int> s;
    for (int i = 0; i < n; i ++) {
        while (!s.empty() && heights[i] <= heights[s.top()]) {
            int h = heights[s.top()];
            s.pop();
            result = max(result, (i - 1 - (s.empty()?-1:s.top())) * h);
        }
        s.push(i);
    }
    // 假设最后面还有一块高度为0的板
    while (!s.empty()) {
        int h = heights[s.top()];
        s.pop();
        result = max(result, (n - 1 - (s.empty()?-1:s.top())) * h);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> heights = {2,1,5,6,2,3};
    std::cout << largestRectangleArea(heights) << "\n";
    return 0;
}

/*
 - 用堆栈计算每一块板能延伸到的左右边界
 - 对每一块板：
    堆栈顶比当前板矮，则这一块左边界确定，入栈
    堆栈顶比当前板高，则这一块右边界确定，出栈，计算面积
    入栈时左边界确定
    出栈时右边界确定
    堆栈里存的是index，所以元素是递增的
 time：O(n),别看有2个循环，但是每个元素只出入栈一次，所以是O(n), space: O(n)
 */
