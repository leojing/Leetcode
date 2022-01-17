//
//  main.cpp
//  Leetcode-310
//
//  Created by Jing Luo on 1/17/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
        return {0};
    }
    vector<int> result;
    vector<int> degree(n); // 出度表
    map<int, vector<int>> connections; // 相邻结点表
    for (int i = 0; i < (int)edges.size(); i ++) {
        int u = edges[i][0];
        int v = edges[i][1];
        degree[u] ++;
        degree[v] ++;
        connections[u].push_back(v);
        connections[v].push_back(u);
    }

    queue<int> q;
    // 把叶子节点入栈
    for (int i = 0; i < n; i ++) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }
    
    // 从外向内一层一层剥，每次加入的都是一层的叶子结点
    while (!q.empty()) {
        int count = (int)q.size();
        result.clear();
        for (int i = 0; i < count; i ++) {
            int node = q.front();
            q.pop();
            degree[node] --;
            // 叶子全部加入结果并且在下一层开始前清出去，有下一层意味着并没有到最后的父节点；
            // 一层一层剔除叶子结点意味着等到父节点时，它也会是叶子结点，那么自然会放入result中，并且不存在下一层，不需要清除，所以即为结果
            result.push_back(node);
            for (auto v: connections[node]) {
                degree[v] --; // 相邻结点由于叶子被剔除，需要-1
                if (degree[v] == 1) { // 如果又变成叶子结点，则意味着是下一层的叶子结点了
                    q.push(v);
                }
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};//{{1,0},{1,2},{1,3}};
    vector<int> result = findMinHeightTrees(6, edges);//4
    std::cout << result.size() << "\n";
    return 0;
}
