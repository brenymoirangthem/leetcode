class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> maxHeap;

        for (auto pair : freq) {
            maxHeap.push(pair.second);
        }

        int time = 0;

        while (!maxHeap.empty()) {
            vector<int> used;

            for (int i = 0; i <= n; i++) {

                if (!maxHeap.empty()) {
                    int count = maxHeap.top();
                    maxHeap.pop();

                    count--;

                    if (count > 0) {
                        used.push_back(count);
                    }
                }

                time++;

                if (maxHeap.empty() && used.empty()) {
                    break;
                }
            }

            for (int count : used) {
                maxHeap.push(count);
            }
        }

        return time;
    }
};