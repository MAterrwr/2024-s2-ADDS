#include <iostream>
#include <vector>
#include <sstream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> list;
    int number;
    while (iss >> number) {
        list.push_back(number);
    }

    QuickSort quickSort;
    list = quickSort.sort(list);

    RecursiveBinarySearch binarySearch;
    bool found = binarySearch.search(list, 1);

    std::cout << (found ? "true" : "false");
    for (const auto& num : list) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
