#include "BigNumCalc.h"
#include <iostream>
#include <algorithm>

std::list<int> bigNumCalc::buildBigNum(std::string numString) {
    std::list<int> result;
    for (char digit : numString) {
        result.push_back(digit - '0');
    }
    return result;
}

std::list<int> bigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || it2 != num2.rend() || carry != 0) {
        int digit1 = (it1 != num1.rend()) ? *it1++ : 0;
        int digit2 = (it2 != num2.rend()) ? *it2++ : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_front(sum % 10);
    }
    return result;
}

std::list<int> bigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    int borrow = 0;

    while (it1 != num1.rend() || it2 != num2.rend()) {
        int digit1 = (it1 != num1.rend()) ? *it1++ : 0;
        int digit2 = (it2 != num2.rend()) ? *it2++ : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
    }

    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }
    return result;
}

std::list<int> bigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    int multiplier = num2.back();  // Assuming num2 has only one digit
    std::list<int> result;
    auto it1 = num1.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || carry != 0) {
        int digit1 = (it1 != num1.rend()) ? *it1++ : 0;
        int product = digit1 * multiplier + carry;
        carry = product / 10;
        result.push_front(product % 10);
    }

    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }
    return result;
}
