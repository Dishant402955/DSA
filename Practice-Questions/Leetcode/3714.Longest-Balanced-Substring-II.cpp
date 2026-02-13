class Solution {
public:

    // window of 1
    int w1(string s , char x){
        int n =s.length();
        int res =0,c=0;
        for(int i =0 ; i< n; i++ ){
            if(s[i]==x)c++;
            else{
                res=max(res,c);
                c=0;
            }
        }
        res=max(res,c);
        c=0;
        return res;
    };

    // window of 2
    int w2(string s , char x, char y){
        int n = s.length();

        unordered_map<int,int> m;
        int res =0 ,sum =0,l=0;
        for(int i =0 ;i <n ; i++ ){
            if(s[i]==x)sum++;
            else if(s[i]==y)sum--;
            else{
                m.clear();
                l = i+1;
                sum=0;
                continue;
            }

            if(sum==0){
                res = max(res,i-l+1);
            }
            else if(m.find(sum)!=m.end()){
                res=max(res,i-m[sum]);
            }
            
            if(m.find(sum)==m.end())m[sum] = i;
        }
        return res;
    };

    // window of 3 

    int w3(string s){
        int n =s.length();

        map<pair<int,int>,int>m;

        int a=0,b=0,c=0,res=0;
        for(int i =0 ;i < n; i++ ){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;

            if(a==b && b==c)res =max(res,3*a);

            auto it = m.find({a-b,a-c}); 
            if(it !=m.end()){
                res=max(res,i- (it->second));
            }

            if(m.find({a-b,a-c})==m.end()){
                m[{a-b,a-c}] = i;
            }
        }
        return res;
    };


    int longestBalanced(string s) {
        int n = s.length();
        
        set<pair<int,pair<int,int>>> se;

        int a=0,b=0,c=0,res=1;

        res=max(res,w1(s,'a'));
    
        res=max(res,w1(s,'b'));
        res=max(res,w1(s,'c'));

        res=max(res,w2(s,'a','b'));
        res=max(res,w2(s,'c','b'));
        res=max(res,w2(s,'a','c'));


        res=max(res,w3(s));

        return res;
        
    }
};
