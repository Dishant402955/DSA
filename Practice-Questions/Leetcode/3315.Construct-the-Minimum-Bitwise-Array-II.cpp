#include <vector>
using namespace std;

class Solution {
public:
  vector<int> minBitwiseArray(vector<int>& values) {
      int n = values.size();
      vector<int> result(n);

      for (int i = 0; i < n; i++) {
          int cur = values[i];

          if (cur == 2) {
              result[i] = -1;
              continue;
          }

          int temp = cur;
          int cnt = 0;

          while ((temp & 1) == 1) {
              cnt++;
              temp >>= 1;
          }

          result[i] = cur - (1 << (cnt - 1));
      }

      return result;
  }
};
