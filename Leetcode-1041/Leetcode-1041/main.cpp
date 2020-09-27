//
//  main.cpp
//  Leetcode-1041
//
//  Created by Jing Luo on 9/22/20.
//

#include <iostream>
#include <string>

using namespace std;

bool isRobotBounded(string instructions) {
    int steps[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int x = 0, y = 0;
    int dir = 0;
    for (int i = 0; i < instructions.size(); i ++) {
        if (instructions[i] == 'R') {
            dir = (dir + 1) % 4;
        } else if (instructions[i] == 'L') {
            dir = (dir + 3) % 4;
        } else {
            x += steps[dir][0];
            y += steps[dir][1];
        }
    }
    return (x == 0 && y == 0) || dir != 0;
}
    
int main(int argc, const char * argv[]) {
    std::cout << isRobotBounded("GL") << "\n";
    return 0;
}

// 看题解的，还是不太明白为什么
// http://www.noteanddata.com/leetcode-1041-Robot-Bounded-In-Circle-java-solution-note.html
