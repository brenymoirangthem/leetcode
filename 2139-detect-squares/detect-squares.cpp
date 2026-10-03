class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;

    DetectSquares() {
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        cnt[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int answer = 0;

        for (auto &entry : cnt) {
            int x2 = entry.first;

            // Same x cannot make a square
            if (x2 == x) {
                continue;
            }

            // We need the horizontal partner (x2, y)
            if (!cnt[x2].count(y)) {
                continue;
            }

            int side = abs(x2 - x);

            // Square above
            int y2 = y + side;

            if (cnt[x].count(y2) && cnt[x2].count(y2)) {
                answer += cnt[x2][y] *
                          cnt[x][y2] *
                          cnt[x2][y2];
            }

            // Square below
            y2 = y - side;

            if (cnt[x].count(y2) && cnt[x2].count(y2)) {
                answer += cnt[x2][y] *
                          cnt[x][y2] *
                          cnt[x2][y2];
            }
        }

        return answer;
    }
};