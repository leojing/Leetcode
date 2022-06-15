//
//  main.cpp
//  Leetcode-735
//
//  Created by Jing Luo on 6/16/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* Solution 1: 不管如何，每次都将i入栈，之后再取stk的头部2个数进行比较，看谁需要保留
 vector<int> asteroidCollision(vector<int>& asteroids) {
     stack<int> stk;
     for (auto i: asteroids) {
         stk.push(i);
         while (!stk.empty()) {
             int right = stk.top();
             stk.pop();
             if (stk.empty()) {
                 stk.push(right);
                 break;
             }
             int left = stk.top();
             
             if ((left > 0 && right > 0) || left < 0) {
                 stk.push(right);
                 break;
             }
             
             int absRight = abs(right);
             if (left == absRight) {
                 stk.pop();
                 break;
             } else if (left > absRight) {
                 break;
             } else {
                 stk.pop();
                 stk.push(right);
             }
         }
     }
     vector<int> res;
     while (!stk.empty()) {
         res.emplace_back(stk.top());
         stk.pop();
     }
     reverse(res.begin(), res.end());
     return res;
 }
 */
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> stk;
    bool explode;
    for (auto i: asteroids) {
        if (i > 0 || stk.empty() || (!stk.empty() && stk.top() < 0)) { // 将三种可以直接入栈的情况先处理
            stk.push(i);
            continue;
        }
        
        explode = false; // 记录当前i是否要被销毁，销毁的条件是stk中存在大于等于abs(i)的正数
        while (!stk.empty() && stk.top() > 0 && stk.top() < abs(i)) {
            stk.pop(); // 将所有比abs(i)小的销毁
        }
        while (!stk.empty() && stk.top() == abs(i)) {
            stk.pop();
            explode = true; // 如果等于，则必须销毁
            break;
        }
        if (!explode && (stk.empty() || (!stk.empty() && stk.top() < 0))) { // 如果i不需要销毁，并且stk里面没有值或者top不是正数，则说明stk已经没有比i大的数了，可以直接入栈
            stk.push(i);
        }
    }
    vector<int> res;
    while (!stk.empty()) {
        res.emplace_back(stk.top());
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> asteroids = {-2,1,1,-1};//{5,10,-5,-3,-28,3,-39,7,282,37,-37}; // {-2,-2,1,-1};
    std::cout << asteroidCollision(asteroids).size() << "\n";
    return 0;
}


// time: O(n), space: o(n)
