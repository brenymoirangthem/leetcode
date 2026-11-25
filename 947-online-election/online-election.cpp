class TopVotedCandidate {
private:
    vector<int> times;
    vector<int> leaders;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& t) {
       
           times = t;

        unordered_map<int, int> count;
        int leader = -1;

        for (int person : persons) {

            count[person]++;

            if (leader == -1 ||
                count[person] >= count[leader]) {
                leader = person;
            }

            leaders.push_back(leader);
        }
    }

    
    int q(int t) {
                int left = 0;
        int right = times.size() - 1;

        int ans = 0;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (times[mid] <= t) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
     return leaders[ans];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */