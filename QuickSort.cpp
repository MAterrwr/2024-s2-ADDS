#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list) {
    quicksort(list, 0, list.size() - 1);
    return list;
}

void QuickSort::quicksort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(list, low, high);
        quicksort(list, low, pivotIndex - 1);
        quicksort(list, pivotIndex + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    int pivotIndex = low + 2; 
    if (pivotIndex > high) {
        pivotIndex = high;
    }
    int pivot = list[pivotIndex];
    std::swap(list[pivotIndex], list[high]); 
    int i = low;
    for (int j = low; j < high; ++j) {
        if (list[j] < pivot) {
            std::swap(list[i], list[j]);
            ++i;
        }
    }
    std::swap(list[i], list[high]);
    return i;
}
