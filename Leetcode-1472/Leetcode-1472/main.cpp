//
//  main.cpp
//  Leetcode-1472
//
//  Created by Jing Luo on 3/27/22.
//

#include <iostream>
#include <stack>

using namespace std;

class BrowserHistory {
    stack<string> historyStack;
    stack<string> forwardStack;
public:
    
BrowserHistory(string homepage) {
    historyStack.emplace(homepage);
}

void visit(string url) {
    historyStack.emplace(url);
    while (!forwardStack.empty()) {
        forwardStack.pop();
    }
}

string back(int steps) {
    while (steps-- && historyStack.size() > 1) {
        forwardStack.emplace( historyStack.top());
        historyStack.pop();
    }
    return historyStack.top();
}

string forward(int steps) {
    while (steps-- && !forwardStack.empty()) {
        historyStack.emplace(forwardStack.top());
        forwardStack.pop();
    }
    return historyStack.top();
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}


// 所有操作都是time: O(n), space: O(n)
// 使用数组会更简单
