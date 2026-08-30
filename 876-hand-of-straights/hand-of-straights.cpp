class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> count;

        for(int card : hand) {
            count[card]++;
        }

        for(auto [card, freq] : count) {

            if(freq == 0) {
                continue;
            }

            for(int i = 0; i < groupSize; i++) {

                int current = card + i;

                if(count[current] < freq) {
                    return false;
                }

                count[current] -= freq;
            }
        }

        return true;
    }
};