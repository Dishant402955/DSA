class Solution {
	public:
		string clearStars(string s){
			vector<int> buckets[26];
			int mask = 0;
			res.reserve(s.size());
			for(char ch : s){
				if(ch != '*'){
					int i = ch -'a';
					buckets[i].push_back(res.size());
					mask |= 1 << i;
					res.push_back(ch);
				}else{
					int lowbit= mask & -mask;
					int i = __builtin_ctz(lowbit);
					int pos = buckets[i].pop_back();
					if(buckets[i].empty())	mask ^= lowbit;
					res[pos] = 0;
				}
			}
			string ans;
			ans.reserve(res.size());
			for(char c: res){
				if(c){
					ans.push_back(c);
				}
			}

			return ans;
		}
}