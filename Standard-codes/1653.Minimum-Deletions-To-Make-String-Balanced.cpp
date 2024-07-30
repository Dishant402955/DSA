int minimumDeletions(string s) {
        // OP's solution
        int ans = 0;
        int countB = 0;
        for (auto c : s) {
            if (c == 'b') {
                countB++;
            } else {
                // is 'a'
                // if countB is zero, 
                //     then ans will be 0, because we do not need to remove anything
                // in the case where countB is no longer 0
                //     then we just need to remove the min(countB, ans + 1) 
                //     [this +1 represents the 'a' we encounter in this iteration + ans (those to be removed in previous iteration)]
                ans = min(ans + 1, countB);
            }
        }
    }