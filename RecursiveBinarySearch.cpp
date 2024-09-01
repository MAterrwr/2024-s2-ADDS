#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> list, int target) {
    return binarySearchRecursive(list, target, 0, list.size() - 1);
}

bool RecursiveBinarySearch::binarySearchRecursive(const std::vector<int>& list, int target, int start, int end) {
    if (start > end) {
        return false;
    }
    int mid = start + (end - start) / 2;
    if (list[mid] == target) {
        return true;
    } else if (list[mid] > target) {
        return binarySearchRecursive(list, target, start, mid - 1);
    } else {
        return binarySearchRecursive(list, target, mid + 1, end);
    }
}
