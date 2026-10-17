class Solution {
public:
    vector<string> result;

    vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index, string& current) {
        // Base case: all digits are processed
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters corresponding to the current digit
        string possible = letters[digits[index] - '0'];

        for (char ch : possible) {
            current.push_back(ch);

            // Move to the next digit
            backtrack(digits, index + 1, current);

            // Backtrack: remove the last character
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        string current;
        backtrack(digits, 0, current);

        return result;
    }
};

