//
//  main.cpp
//  Leetcode-394
//
//  Created by Jing Luo on 3/22/22.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string multiString(int mutil, string s) {
    string result = "";
    while (mutil --) {
        result += s;
    }
    return result;
}


// time: O(n), space: O(n)
string decodeString(string s) {
    string result = "";
    stack<int> countStack;
    stack<string> strStack;
    string tempCount = "";
    string tempStr = "";
    string temp = "";
    
    for (int i = 0; i < s.length(); i ++) {
        if (isalpha(s[i])) {
            while (isalpha(s[i])) {
                tempStr += s[i];
                i ++;
            }
            i --;
            if (countStack.size() == 0) {
                result += tempStr;
            } else {
                string t = strStack.top();
                t += tempStr;
                strStack.pop();
                strStack.push(t);
            }
            tempStr = "";
        } else if (isdigit(s[i])) {
            while (isdigit(s[i])) {
                tempCount += s[i];
                i ++;
            }
            i --;
           countStack.push(stoi(tempCount));
           tempCount = "";
        } else if (s[i] == '[') {
            while (isalpha(s[i])) {
                tempStr += s[i+1];
                i ++;
            }
            strStack.push(tempStr);
            tempStr = "";
        } else if (s[i] == ']') {
            int count = countStack.top();
            countStack.pop();
            string str = strStack.top();
            strStack.pop();
            temp = multiString(count, str);
            if (countStack.size() == 0) {
                result += temp;
            } else {
                string t = strStack.top();
                t += temp;
                strStack.pop();
                strStack.push(t);
            }
        }
    }
    if (tempStr.length() > 0) {
        result += tempStr;
    }
    return result;
}

int main(int argc, const char * argv[]) {
//    string s = "abc3[cd]xyz";
//    string s = "2[abc]3[cd]ef";
//    string s = "3[a]2[bc3[ed4[sf]]]";
    string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    std::cout << decodeString(s) << "\n";
    return 0;
}
