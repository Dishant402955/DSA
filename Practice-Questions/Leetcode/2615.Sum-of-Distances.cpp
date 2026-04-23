class Solution {
public:
	 vector<long long> distance(vector<int>& nums) {
		  unordered_map<long long, vector<long long>> Map;

		  for (long long i = 0; i < nums.size(); i++) {
				Map[nums[i]].push_back(i);
		  }

		  vector<long long> Ans(nums.size(), 0);

		  // From Left Side
		  for (auto& v : Map) {
				long long T = 0;
				for (long long i = 1; i < v.second.size(); i++) {
					 long long diff = v.second[i] - v.second[i - 1];
					 Ans[v.second[i]] += i * diff + T;
					 T += i * diff;
				}
		  }

		  // From Right Side
		  for (auto& v : Map) {
				long long T = 0;
				long long c = 1;
				for (long long i = (long long)v.second.size() - 2; i >= 0; i--) {
					 long long diff = v.second[i + 1] - v.second[i];
					 Ans[v.second[i]] += c * diff + T;
					 T += c * diff;
					 c++;
				}
		  }

		  return Ans;
	 }
};
