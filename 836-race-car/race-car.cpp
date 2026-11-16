class Solution {
public:
    int racecar(int target) {
         queue<tuple<int, int, int>> q;

    set<pair<int, int>> visited;

    q.push({0, 1, 0});
    visited.insert({0, 1});

    while (!q.empty()) {

        auto [position, speed, steps] = q.front();
        q.pop();

        // Target reached
        if (position == target) {
            return steps;
        }

        // Option 1: Accelerate
        int newPosition = position + speed;
        int newSpeed = speed * 2;

        if (newPosition >= 0 &&
            newPosition <= 2 * target &&
            !visited.count({newPosition, newSpeed})) {

            q.push({newPosition, newSpeed, steps + 1});
            visited.insert({newPosition, newSpeed});
        }

        // Option 2: Reverse
        int reverseSpeed;

        if (speed > 0) {
            reverseSpeed = -1;
        }
        else {
            reverseSpeed = 1;
        }

        if (!visited.count({position, reverseSpeed})) {

            q.push({position, reverseSpeed, steps + 1});
            visited.insert({position, reverseSpeed});
        }
    }

    return -1;

    }
};