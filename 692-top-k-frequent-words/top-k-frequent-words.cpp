class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
         unordered_map<string, int> freq;

        // Step 1: Count frequency
        for (string word : words) {
            freq[word]++;
        }

        // Step 2: Store unique words
        vector<string> result;

        for (auto it : freq) {
            result.push_back(it.first);
        }

        // Step 3: Sort words
        sort(result.begin(), result.end(),
             [&](string a, string b) {

            if (freq[a] == freq[b]) {
                return a < b;
            }

            return freq[a] > freq[b];
        });

        // Step 4: Keep only top k words
        result.resize(k);

        return result;
    }
};