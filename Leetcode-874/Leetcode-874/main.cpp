//
//  main.cpp
//  Leetcode-874
//
//  Created by Jing Luo on 9/28/20.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int result = 0;
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int current = 0;
    int x = 0, y = 0;
    set<pair<int, int>> exist;
    for (int i = 0; i < obstacles.size(); i ++) {
        exist.insert(make_pair(obstacles[i][0], obstacles[i][1]));
    }
    for (int i = 0; i < commands.size(); i ++) {
        if (commands[i] == -1) {
            current ++;
        } else if (commands[i] == -2) {
            current --;
        } else {
            for (int j = 0; j < commands[i]; j ++) {
                x += dir[current][0];
                y += dir[current][1];
                pair<int, int> temp = make_pair(x, y);
                if (exist.find(temp) != exist.end()) {
                    x -= dir[current][0];
                    y -= dir[current][1];
                    break;
                }
            }
            result = max(result, x * x + y * y);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    std::cout << robotSim(commands, obstacles) << "\n";
    return 0;
}
