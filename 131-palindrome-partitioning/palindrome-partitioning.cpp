class Solution {
public:
vector<vector<string>> result;

    // Check whether a substring is a palindrome
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(string& s, int start, vector<string>& current) {
        // All characters have been partitioned
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            // Only choose palindromic substrings
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));

                // Explore the remaining string
                backtrack(s, end + 1, current);

                // Backtrack: remove the last substring
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtrack(s, 0, current);
        return result;
    }
};
