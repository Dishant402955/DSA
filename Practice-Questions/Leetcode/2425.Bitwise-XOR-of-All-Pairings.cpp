class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int len1 = nums1.size();
        int len2 = nums2.size();

        int answer = 0;
        // If nums1 or nums2 has an even length then the xored operation becomes 0
        // So check for the odd length

        if(len1 % 2 ==1)
        {
            for(int i=0;i<len2;i++) answer ^=nums2[i];
        }

        if(len2 % 2 ==1)
        {
            for(int i=0;i<len1;i++) answer ^=nums1[i];
        }

        return answer;
    }
};