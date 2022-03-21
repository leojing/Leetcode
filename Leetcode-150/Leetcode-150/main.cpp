//
//  main.cpp
//  Leetcode-150
//
//  Created by Jing Luo on 3/21/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isOperation(string s) {
       return s == "+" || s == "-" || s == "*" || s == "/";
   }
   
int evalRPN(vector<string>& tokens) {
   stack<int> operators;
   for (auto s: tokens) {
       if (isOperation(s)) {
           int second = operators.top();
           operators.pop();
           int first = operators.top();
           operators.pop();
           int temp = 0;
           if (s == "+") {
               temp = first + second;
           } else if (s == "-") {
               temp = first - second;
           } else if (s == "*") {
               temp = first * second;
           } else if (s == "/") {
               temp = first / second;
           }
           operators.push(temp);
       } else {
           operators.push(stoi(s));
       }
   }
   return operators.top();
}

int main(int argc, const char * argv[]) {
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << evalRPN(tokens) << "\n";
    return 0;
}
