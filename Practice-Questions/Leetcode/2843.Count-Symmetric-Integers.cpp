class Solution {
public:
    // Function to count the number of digits in a number.
    int countDigits(int num) {
        int count = 0;
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }
    
    // Function to calculate the sum of all digits in a number.
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    // Function to count symmetric integers within the range [low, high].
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        
        // Loop over all numbers in the given range.
        for (int i = low; i <= high; i++) {
            // Check if the number has an even number of digits.
            if (countDigits(i) % 2 == 0) {
                // Total sum of the digits.
                int totalSum = sumOfDigits(i);
                
                // Number of digits in one half.
                int halfDigits = countDigits(i) / 2;
                int halfSum = 0;
                
                // Extract the lower half of the number's digits.
                int temp = i;
                for (int j = 0; j < halfDigits; j++) {
                    halfSum += temp % 10;
                    temp /= 10;
                }
                
                // Check if the lower half sum is equal to the sum of the higher half.
                // Since totalSum = (higher half sum) + (lower half sum), 
                // the symmetry condition is: totalSum == 2 * (lower half sum)
                if (totalSum == 2 * halfSum) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};