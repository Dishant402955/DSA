class Solution {
    public int minSumOfLengths(int[] arr, int target) {

        int n = arr.length;

        // minLen[i] = shortest valid subarray
        // ending at or before index i
        int[] minLen = new int[n];

        int l = 0;
        int sum = 0;

        int ans = Integer.MAX_VALUE;
        int best = Integer.MAX_VALUE;

        for (int r = 0; r < n; r++) {

            sum += arr[r];

            // Shrink window if sum becomes too large
            while (sum > target) {
                sum -= arr[l++];
            }

            // Found a subarray with sum = target
            if (sum == target) {

                int currLen = r - l + 1;

                // Find the best non-overlapping subarray
                // completely to the left of l
                if (l > 0 &&
                    minLen[l - 1] != Integer.MAX_VALUE) {

                    ans = Math.min(
                        ans,
                        currLen + minLen[l - 1]
                    );
                }

                // Keep the shortest valid subarray seen so far
                best = Math.min(best, currLen);
            }

            // Carry the best value forward
            minLen[r] = best;
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
