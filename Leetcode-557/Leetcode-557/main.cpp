//
//  main.cpp
//  Leetcode-557
//
//  Created by Jing Luo on 2/28/22.
//

#include <iostream>
#include <string>

using namespace std;

void reverseString(string& s, int start, int end) {
    while (start < end) {
       char temp = s[start];
       s[start] = s[end];
       s[end] = temp;
       start ++;
       end --;
    }
}

string reverseWords(string s) {
    int n = (int)s.length();
    int start = -1; int end = 0;
    while (end < n) {
        if (s[end] == ' ' && start != -1) {
            reverseString(s, start, end - 1);
            start = -1;
        } else if (s[end] != ' ' && start == -1) {
            start = end;
        }
        end ++;
    }
    if (start != -1) {
        reverseString(s, start, n - 1);
    }
    return s;
}

int main(int argc, const char * argv[]) {
    string s = "123 456 7 89 0";
    std::cout << reverseWords(s) << "\n";
    return 0;
}
