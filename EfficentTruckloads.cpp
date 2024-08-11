#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1;
    }
    if (memo.find(numCrates) != memo.end()) {
        return memo[numCrates];
    }
    int half1 = numCrates / 2;
    int half2 = numCrates - half1;
    memo[numCrates] = numTrucks(half1, loadSize) + numTrucks(half2, loadSize);
    return memo[numCrates];
}