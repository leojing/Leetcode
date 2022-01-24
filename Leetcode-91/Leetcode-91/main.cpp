//
//  main.cpp
//  Leetcode-91
//
//  Created by Jing Luo on 1/25/22.
//

#include <iostream>

using namespace std;

int numDecodings(string s) {
    if (s[0] == '0') {
        return 0;
    }
    if (s.length() == 1) {
        return 1;
    }
    int first = 1, second = 1, result = 0; // second初始化也得为1，因为如果前2个字母符合条件，那么需要+1（即+second）
    for (int i = 1; i < s.length(); i ++) {
        if (s[i] != '0') {
            result = first;
        } else {
            result = 0;
        }
        string c = s.substr(i-1,2);
        int t = stoi(c);
        if (s[i-1] != '0' && t <= 26 && t > 0) {
            result += second;
        }
        second = first;
        first = result;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << numDecodings("1") << "\n"; // 1
    std::cout << numDecodings("10") << "\n"; // 1
    std::cout << numDecodings("01") << "\n"; // 0
    std::cout << numDecodings("29") << "\n"; // 1
    std::cout << numDecodings("126") << "\n"; // 3
    std::cout << numDecodings("12827260043425620026") << "\n"; // 0
    return 0;
}


// 经典DP，状态压缩可以简化成一维的，因为只需要当前位置result的前一个结果first和前前一个结果second
// time: O(n), space: O(1)
