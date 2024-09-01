#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    bool swapped;
    int n = list.size();
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (list[i - 1] > list[i]) {
                std::swap(list[i - 1], list[i]);
                swapped = true;
            }
        }
        --n; // Decrease n because the last element is already in place
    } while (swapped);
    return list;
}
