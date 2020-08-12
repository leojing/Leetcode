//
//  main.cpp
//  Leetcode-171
//
//  Created by Jing Luo on 8/11/20.
//

#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string s) {
    int len = int(s.size());
    int sum = 0;
    for (int i = 0; i < len; i ++) {
        int num = s[i] - 'A' + 1;
        sum += pow(26, len-i-1) * num;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    std::cout << titleToNumber("ZY") << "\n";
    return 0;
}
