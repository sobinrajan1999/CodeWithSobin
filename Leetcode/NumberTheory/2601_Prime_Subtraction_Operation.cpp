//question : https://leetcode.com/problems/prime-subtraction-operation/description

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Vector to store prime numbers up to a certain limit
    vector<int> primes;

    // Function to generate all prime numbers up to 'n' using the Sieve of Eratosthenes algorithm
    void seiveoferothesthenes(int n) {
        vector<bool> isprime(n + 1, true); // Initialize a boolean array to mark primes
        for (int i = 2; i < sqrt(n); i++) { // Loop from 2 up to the square root of n
            if (isprime[i] == true) { // If i is a prime
                // Mark multiples of i as non-prime
                for (int j = i * i; j <= n; j += i) {
                    isprime[j] = false;
                }
            }
        }
        // Collect all numbers marked as prime into the primes vector
        for (int i = 2; i <= n; i++) {
            if (isprime[i]) {
                primes.push_back(i);
            }
        }
    }

    // Function to determine if it's possible to make each element in 'nums' smaller than the next
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size(); // Get the size of the nums array
        // Find the maximum element in nums and generate primes up to that value
        seiveoferothesthenes(*max_element(nums.begin(), nums.end()));

        // Loop from the second-to-last element to the first element
        for (int i = n - 2; i >= 0; i--) {
            // If the current element is already less than the next, continue
            if (nums[i + 1] > nums[i]) {
                continue;
            }
            // Find the smallest prime that, when subtracted, makes nums[i] less than nums[i + 1]
            auto p = std::upper_bound(primes.begin(), primes.end(), nums[i] - nums[i + 1]);
            if (p == primes.end()) { // If no such prime exists, return false
                return false;
            }
            nums[i] -= *p; // Subtract the found prime from nums[i]
            if (nums[i] <= 0) { // If nums[i] becomes non-positive, return false
                return false;
            }
        }
        // If the loop completes without issues, return true
        return true;
    }
};
