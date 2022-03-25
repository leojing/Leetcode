//
//  main.cpp
//  Leetcode-232
//
//  Created by Jing Luo on 3/25/22.
//

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    
    stack<int> pushStack;
    stack<int> peekStack;
    
public:
    
    MyQueue() {
    }
    
    void push(int x) {
        while (!peekStack.empty()) {
            pushStack.push(peekStack.top());
            peekStack.pop();
        }
        pushStack.push(x);
    }
    
    int pop() {
        while (!pushStack.empty()) {
            peekStack.push(pushStack.top());
            pushStack.pop();
        }
        int top = peekStack.top();
        peekStack.pop();
        return top;
    }
    
    int peek() {
        while (!pushStack.empty()) {
            peekStack.push(pushStack.top());
            pushStack.pop();
        }
        return peekStack.top();
    }
    
    bool empty() {
        return pushStack.empty() && peekStack.empty();
    }
};

int main(int argc, const char * argv[]) {
    MyQueue* obj = new MyQueue();
    obj->push(8);
    obj->push(2);
    obj->push(1);
    obj->push(6);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    return 0;
}

// time: push，peek，pop，都是O(n)
// space: O(2n) = O(n)
