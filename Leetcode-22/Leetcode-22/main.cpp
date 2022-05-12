//
//  main.cpp
//  Leetcode-22
//
//  Created by Jing Luo on 5/12/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Solution 1
/*
void helper(int n, int k, stack<char> st, string curr, vector<string>& result) {
    if (curr.size() == n * 2) {
        result.emplace_back(curr);
        return;
    }
    vector<char> valid;
    if (k < n) {
        valid.emplace_back('(');
    }
    valid.emplace_back(')');
    for (auto c: valid) {
        if (c == '(') {
            st.push(c);
            helper(n, k + 1, st, curr + c, result);
            st.pop();
        } else {
            if (st.empty()) {
                continue;
            }
            if (st.top() == '(') {
                st.pop();
                helper(n, k, st, curr + c, result);
                st.push('(');
            } else {
                st.push(c);
                helper(n, k, st, curr + c, result);
                st.pop();
            }
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    stack<char> st;
    st.push('(');
    helper(n, 1, st, "(", result);
    return result;
}*/

// Solution 2: 利用任何位置的右括号，肯定满足左括号数量>右括号数量
void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    backtrack(result, current, 0, 0, n);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
