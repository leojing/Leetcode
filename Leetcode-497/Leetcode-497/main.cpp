//
//  main.cpp
//  Leetcode-497
//
//  Created by Jing Luo on 8/27/20.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rect;
    vector<int> r_area;
    int total_area;
    Solution(vector<vector<int>> rects) {
        rect = rects;
        int total = 0;
        for (int i = 0; i < rects.size(); i++) {
            total += (rects[i][2] - rects[i][0]+1)*(rects[i][3] - rects[i][1]+1);
            r_area.push_back(total);
        }
        total_area = total;
    }
    
    vector<int> pick() {
        int random_area = rand()%total_area+1;
        int i = 0;
        for (; i < r_area.size(); i++) {
            if (random_area <= r_area[i]) break;
        }
        int dis_x = rand()%(rect[i][2] - rect[i][0]+1);
        int dis_y = rand()%(rect[i][3] - rect[i][1]+1);
        return {rect[i][0] + dis_x, rect[i][1] + dis_y};
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> rects = {{-2,-2,-1,-1},{1,0,3,0}};
    Solution *obj = new Solution(rects);
    vector<int> param_1 = obj->pick();
    std::cout << param_1[0] << "\n";
    std::cout << param_1[1] << "\n";
    return 0;
}
