//
//  main.cpp
//  Leetcode-155
//
//  Created by Jing Luo on 3/21/22.
//

#include <iostream>
#include <stack>

using namespace std;

stack<int> x_stack;
stack<int> min_stack;

MinStack() {
    min_stack.push(INT_MAX);
}

void push(int val) {
    x_stack.push(val);
    min_stack.push(min(min_stack.top(), val));
}

void pop() {
    x_stack.pop();
    min_stack.pop();
}

int top() {
    return x_stack.top();
}

int getMin() {
    return min_stack.top();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 time: O(1) push, pop, top, getMin
 space: O(n)
 
 min_stack的push非常smart，即不单纯保存min，而是每次输入新的val时，
 保存目前为止x_stack里对应的min，所以等pop时，可以同时pop x_stack和min_stack，
 因为剩下的数里，会有自己对应的min在min_stack里
 */
