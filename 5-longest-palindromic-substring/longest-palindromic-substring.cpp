class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        pair<int,int> p={0,0};
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                int left=i;
                int right=j;
                bool check=false;
                while(left>right){
                    if(s[left]==s[right]){
                        left--;
                        right++;
                    }else{
                        check=true;
                        break;
                    }
                }
                if(!check && (i - j) > (p.second - p.first)){
                    p.first=j;
                    p.second=i;
                }
            }
        }
        int length=p.second-p.first+1;
        string ans=s.substr(p.first,length);
        return ans;
    }
};