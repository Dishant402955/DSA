class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (left > right) return {-1, -1};

        // Step 1: Sieve of Eratosthenes
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Collect primes in the range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) primes.push_back(i);
        }

        // Step 3: If fewer than 2 primes exist, return [-1, -1]
        if (primes.size() < 2) return {-1, -1};

        // Step 4: Find the closest prime pair
        int minDiff = INT_MAX, num1 = -1, num2 = -1;
        for (size_t i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                num1 = primes[i - 1];
                num2 = primes[i];
            }
        }

        return {num1, num2};
    }
};