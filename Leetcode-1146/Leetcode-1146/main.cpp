//
//  main.cpp
//  Leetcode-1146
//
//  Created by Jing Luo on 4/27/22.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<map<int, int>> snapshot; // 没必要存整个array，只需要存对应index上每次（snap_id）改动的val，讲snap_id和val进行map保存
int snap_id = 0;

void SnapshotArray(int length) {
    for (int i = 0; i < length; i ++) {
        map<int, int> mapping = {{0,0}};
        snapshot.emplace_back(mapping);
    }
}

void set(int index, int val) {
    snapshot[index][snap_id] = val;
}

int snap() {
    return snap_id ++;
}

int get(int index, int snap_id) {
    auto iter = snapshot[index].upper_bound(snap_id); // 取出第一个比snap_id大的数，如果不存在，则同样取iter--
    iter--;
    return iter->second;
}

int main(int argc, const char * argv[]) {
    SnapshotArray(3);
    set(0, 5);
    snap();
    set(0, 6);
    set(1, 2);
    snap();
    set(2, 4);
    snap();
    set(0, 2);
    snap();
    set(0, 3);
    snap();
    get(0,2);
    std::cout << "\n";
    return 0;
}
