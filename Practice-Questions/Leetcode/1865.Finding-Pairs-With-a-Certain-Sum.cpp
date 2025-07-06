#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> hm; // Frequency map for nums2

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        // Build frequency map for nums2
        for (int num : nums2) {
            hm[num]++;
        }
    }

    void add(int index, int val) {
        // Update frequency map before changing nums2[index]
        int oldVal = nums2[index];
        hm[oldVal]--;

        if (hm[oldVal] == 0) {
            hm.erase(oldVal);
        }

        // Update nums2 value
        nums2[index] += val;
        int newVal = nums2[index];

        // Add new value to the frequency map
        hm[newVal]++;
    }

    int count(int tot) {
        int count = 0;

        // For each element in nums1, check for complements in nums2
        for (int num : nums1) {
            int complement = tot - num;
            if (hm.count(complement)) {
                count += hm[complement];
            }
        }
        return count;
    }
};
