class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
         unordered_map<string, int> freq;
        int n = s.length();
        int ans = 0;

        // Character frequency in the current window
        int count[26] = {0};
        int distinct = 0;

        for (int i = 0; i < n; i++) {

            // Add current character
            if (count[s[i] - 'a'] == 0) {
                distinct++;
            }

            count[s[i] - 'a']++;

            // Remove character outside the window
            if (i >= minSize) {
                char removed = s[i - minSize];

                count[removed - 'a']--;

                if (count[removed - 'a'] == 0) {
                    distinct--;
                }
            }

            // Process only windows of minSize
            if (i >= minSize - 1) {

                if (distinct <= maxLetters) {

                    string sub = s.substr(i - minSize + 1, minSize);

                    freq[sub]++;

                    ans = max(ans, freq[sub]);
                }
            }
        }

        return ans;
    }
};