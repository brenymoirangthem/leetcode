class Solution {
public:
    string reorganizeString(string s) {
           vector<int> freq(26, 0);

    for (char ch : s) {
        freq[ch - 'a']++;
    }

    // Step 2: Create Max Heap
    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < 26; i++) {

        if (freq[i] > 0) {
            pq.push({freq[i], char(i + 'a')});
        }
    }

    string ans = "";

    // Step 3: Process two characters at a time
    while (pq.size() >= 2) {

        auto first = pq.top();
        pq.pop();

        auto second = pq.top();
        pq.pop();

        ans += first.second;
        ans += second.second;

        first.first--;
        second.first--;

        if (first.first > 0) {
            pq.push(first);
        }

        if (second.first > 0) {
            pq.push(second);
        }
    }

    // Step 4: Handle remaining character
    if (!pq.empty()) {

        auto last = pq.top();
        pq.pop();

        if (last.first > 1) {
            return "";
        }

        ans += last.second;
    }

    return ans;
    }
};