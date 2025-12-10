#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<string>> dictionary = {
        {2, {"a", "b", "c"}},
        {3, {"d", "e", "f"}},
        {4, {"g", "h", "i"}},
        {5, {"j", "k", "l"}},
        {6, {"m", "n", "o"}},
        {7, {"p", "q", "r", "s"}},
        {8, {"t", "u", "v"}},
        {9, {"w", "x", "y", "z"}}
    };

    vector<string> result;
    void backtrack(const string &digits, int index, string current) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';  // convert char to int

        for (const string &letter : dictionary[digit]) {
            backtrack(digits, index + 1, current + letter);
        }
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        result.clear();
        backtrack(digits, 0, "");
        return result;
    };
};