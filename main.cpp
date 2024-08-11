#include <iostream>
#include "Truckloads.h"
#include "Reverser.h"
#include "EfficientTruckloads.h"

void testTruckloads() {
    Truckloads t;
    std::cout << "Truckloads Test Cases:" << std::endl;
    std::cout << "14 crates, load size 3: " << t.numTrucks(14, 3) << " (Expected: 6)" << std::endl;
    std::cout << "15 crates, load size 1: " << t.numTrucks(15, 1) << " (Expected: 15)" << std::endl;
    std::cout << "1024 crates, load size 5: " << t.numTrucks(1024, 5) << " (Expected: 256)" << std::endl;
}

void testReverser() {
    Reverser r;
    std::cout << "\nReverser Test Cases:" << std::endl;
    std::cout << "Reverse digit 12345: " << r.reverseDigit(12345) << " (Expected: 54321)" << std::endl;
    std::cout << "Reverse digit -12345: " << r.reverseDigit(-12345) << " (Expected: -1)" << std::endl;
    std::cout << "Reverse string 'hello': " << r.reverseString("hello") << " (Expected: 'olleh')" << std::endl;
    std::cout << "Reverse string '': " << r.reverseString("") << " (Expected: 'ERROR')" << std::endl;
}

void testEfficientTruckloads() {
    EfficientTruckloads et;
    std::cout << "\nEfficientTruckloads Test Cases:" << std::endl;
    std::cout << "14 crates, load size 3: " << et.numTrucks(14, 3) << " (Expected: 6)" << std::endl;
    std::cout << "15 crates, load size 1: " << et.numTrucks(15, 1) << " (Expected: 15)" << std::endl;
    std::cout << "1024 crates, load size 5: " << et.numTrucks(1024, 5) << " (Expected: 256)" << std::endl;
}

int main() {
    testTruckloads();
    testReverser();
    testEfficientTruckloads();
    return 0;
}