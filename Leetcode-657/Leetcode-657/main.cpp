//
//  main.cpp
//  Leetcode-657
//
//  Created by Jing Luo on 9/22/20.
//

#include <iostream>
#include <string>

using namespace std;

bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (auto i: moves) {
        if (i == 'U') {
            y += 1;
        } else if (i == 'R') {
            x -= 1;
        } else if (i == 'L') {
            x += 1;
        } else {
            y -= 1;
        }
    }
    if (x == 0 && y == 0) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::cout << judgeCircle("RRDD") << "\n";
    return 0;
}
