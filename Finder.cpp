#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    size_t index = 0;  
    for (size_t i = 1; i <= s2.size(); ++i) {
        index = s1.find(s2.substr(0, i), index);
        if (index != string::npos) {
            result.push_back(index);
        } else {
            result.push_back(-1);
            break; 
        }
    }
    for (size_t j = result.size(); j < s2.size(); ++j) {
        result.push_back(-1);
    }
    return result;
}
