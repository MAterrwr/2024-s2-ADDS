#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort {
public:
    virtual std::vector<int> sort(std::vector<int> list) = 0; // Pure virtual function
    virtual ~Sort() = default; // Virtual destructor for proper cleanup of derived objects
};

#endif // SORT_H
