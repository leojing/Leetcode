//
//  main.cpp
//  Leetcode-146
//
//  Created by Jing Luo on 6/14/22.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    list<int> recent;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> pos;
    int cap;
    
    void used(int key) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else if (recent.size() >= cap) {
            int last = recent.back();
            pos.erase(last);
            cache.erase(last);
            recent.pop_back();
        }
        recent.push_front(key);
        pos[key] = recent.begin();
    }
        
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            used(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        cache[key] = value;
        used(key);
    }
};

int main(int argc, const char * argv[]) {
    LRUCache* obj = new LRUCache(5);
    int param_1 = obj->get(3);
    obj->put(2,4);
    return 0;
}


/*
 
 要让 put 和 get 方法的时间复杂度为 O(1)，我们可以 总结出 cache 这个数据结构必要的条件:查找快，插入快，删除快，有顺序 之分。
 因为显然 cache 必须有顺序之分，以区分最近使用的和久未使用的数据;而 且我们要在 cache 中查找键是否已存在;如果容量满了要删除最后一个数 据;每次访问还要把数据插入到队头。

 那么，什么数据结构同时符合上述条件呢?哈希表查找快，但是数据无固定顺序;链表有顺序之分，插入删除快，但是查找慢。所以结合一下，形成一种新的数据结构:哈希链表。

 LRU 缓存算法的核心数据结构就是哈希链表，双向链表和哈希表的结合体。
 
 */
