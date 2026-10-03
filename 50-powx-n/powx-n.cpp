class Solution {
public:
    double fastPower(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }

        double half = fastPower(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        }

        return half * half * x;
    }

    double myPow(double x, int n) {
        long long power = n;

        if (power < 0) {
            return 1.0 / fastPower(x, -power);
        }

        return fastPower(x, power);
    }
};