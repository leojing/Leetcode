//
//  main.cpp
//  Leetcode-542
//
//  Created by Jing Luo on 3/25/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = (int)mat.size();
    int m = (int)mat[0].size();
    
    vector<vector<int>> result(n, vector<int>(m));

    queue<pair<int, int>> q;
    unordered_set<int> visited;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mat[i][j] == 0) {
                q.push(make_pair(i, j));
                result[i][j] = 0;
            }
        }
    }
    
    int steps = 0;
    while (!q.empty()) {
        steps ++;
        int size = (int)q.size();
        while (size --) {
            pair curr = q.front();
            q.pop();
            int dir[8] = {0,1,1,0,0,-1,-1,0};
            for (int i = 0; i < 8; i += 2) {
                int newX = curr.first + dir[i];
                int newY = curr.second + dir[i+1];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m) {
                    continue;
                }
                int newPos = newX*m + newY;
                if (visited.find(newPos) != visited.end() || mat[newX][newY] == 0) {
                    continue;
                }
                visited.insert(newPos);
                q.push(make_pair(newX, newY));
                result[newX][newY] = steps;
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 TLE了2次，一次忘记标记已被visited；一次是数据太大，如果从每个元素出发去找0，，需要n*m次BFS，会超时，需要反向思考，从0出发去到每个1，这样也就是1→0的距离，一次BFS就可以找到所有元素与0的距离，关键点是要将所有0都在一开始都加入queue，作为第一层
 
 time: O(n*m), space: O(min(n,m))
 */
