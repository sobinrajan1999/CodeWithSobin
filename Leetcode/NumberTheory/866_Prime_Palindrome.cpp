//question : https://leetcode.com/problems/prime-palindrome/description

#include <cmath>
#include <string>
#include <iostream>

class Solution {
public:

    // Function to check if a number is prime
    bool isPrime(int n) {
        if (n < 2) return false; // Numbers less than 2 are not prime
        if (n % 2 == 0) return n == 2; // Check divisibility by 2
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                return false; // Divisible by another number, hence not prime
            }
        }
        return true; // n is prime
    }

    // Function to check if a number is a palindrome
    bool isPalindrome(int n) {
        std::string s = std::to_string(n); // Convert the number to a string
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false; // Check characters from both ends
            i++; j--;
        }
        return true; // Number is a palindrome
    }

    // Main function to find the smallest prime palindrome greater than or equal to n
    int primePalindrome(int n) {
        // Handle small cases directly
        if (n <= 2) return 2;
        if (n == 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;

        // Start from the next odd number if n is even
        int candidate = (n % 2 == 0) ? n + 1 : n;

        // Main loop to find the prime palindrome
        while (true) {
            if (isPalindrome(candidate) && isPrime(candidate)) {
                return candidate; // Found the smallest prime palindrome
            }

            candidate += 2; // Move to the next odd number (palindromic primes are odd)

            // Skip certain ranges where no prime palindromes exist
            if (candidate > 1e3 && candidate < 1e4) candidate = 1e4 + 1;
            if (candidate > 1e5 && candidate < 1e6) candidate = 1e6 + 1;
            if (candidate > 1e7 && candidate < 1e8) candidate = 1e8 + 1;
        }

        return -1; // This will never be reached, as a prime palindrome is always found
    }
};
