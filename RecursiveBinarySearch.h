#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch {
public:
    bool search(std::vector<int> list, int target);
private:
    bool binarySearchRecursive(const std::vector<int>& list, int target, int start, int end);
};

#endif 