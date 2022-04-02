//
//  main.cpp
//  Leetcode-284
//
//  Created by Jing Luo on 4/2/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Iterator {
      struct Data;
       Data* data;
public:
       Iterator(const vector<int>& nums);
       Iterator(const Iterator& iter);
       // Returns the next element in the iteration.
      int next();
      // Returns true if the iteration has more elements.
      bool hasNext() const;
    };
 

int nextNum;
bool exist;

class PeekingIterator : public Iterator {
    int nextNum;
    bool exist;
public:
PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    exist = Iterator::hasNext();
    if (exist) {
        nextNum = Iterator::next();
    }
}

// Returns the next element in the iteration without advancing the iterator.
int peek() {
    return nextNum;
}

// hasNext() and next() should behave the same as in the Iterator interface.
// Override them if needed.
int next() {
    int curr = nextNum;
    exist = Iterator::hasNext();
    if (hasNext()) {
        nextNum = Iterator::next();
    }
    return curr;
}

bool hasNext() const {
    return exist;
}
};

int main(int argc, const char * argv[]) {
    PeekingIterator* peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
    peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
    peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
    peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
    peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
    peekingIterator.hasNext(); // return False
    return 0;
}
