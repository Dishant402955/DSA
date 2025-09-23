class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int i = 0, j = 0;

        while (i < m || j < n) {
            string s1 = "0", s2 = "0";

            // extract revision from version1
            while (i < m && version1[i] != '.') {
                s1 += version1[i];
                i++;
            }

            // extract revision from version2
            while (j < n && version2[j] != '.') {
                s2 += version2[j];
                j++;
            }

            int num1 = stoi(s1);
            int num2 = stoi(s2);

            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;

            i++; j++; // skip the '.'
        }

        return 0;
    }
};
