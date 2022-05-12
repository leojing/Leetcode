//
//  main.cpp
//  Leetcode-20
//
//  Created by Jing Luo on 5/12/22.
//

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> brackets;
    for (auto c: s) {
        if (c == '(' || c == '{' || c == '[') {
            brackets.push(c);
        } else {
            if (brackets.empty()) { // 注意"]"的情况，以右括号为开头
                return false;
            }
            char top = brackets.top();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
            brackets.pop();
        }
    }
    return brackets.empty(); // 需保证所有括号都被匹配完成，即brackets stack为空，注意"["的情况
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

// time: O(n), space: O(n)

/* test case:
[[]]{}()
 [ // edge case
 ] // edge case
 (){[[()}
*/
