class Solution {
public:
    string multiply(string num1, string num2) {
        if((num1.size()==1&&num1[0]=='0')|| (num2.size()==1 && num2[0]=='0')){
            return "0";
        }
        int n=num1.size();
        int m=num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string s1;
        string s2;
        if(n>m){
            s1=num2;
            s2=num1;
        }else{
            s1=num1;
            s2=num2;
        }

        vector<vector<int>> nums(s1.size(),vector<int>(s1.size() + s2.size(),0));
        for(int i=0;i<s1.size();i++){
            int k1=s1[i]-'0';
            int carry=0;
            for(int j=0;j<s2.size();j++){
                int k2=s2[j]-'0';
                int prod=k1*k2+carry;
                nums[i][i+j]=prod%10;
                carry=prod/10;
            }
            nums[i][i + s2.size()] = carry;
        }
        vector<int> ans(s2.size()+s1.size(),-1);
        int carry=0;
        for(int i=0;i<ans.size();i++){
            int sum=carry;
            for(int j=0;j<s1.size();j++){
                sum+=nums[j][i];
            }
            ans[i]=sum%10;
            carry=sum/10;
        }
        if (carry)
            ans.push_back(carry);
        while(ans.size()>0 && ans.back()==0){
            ans.pop_back();
        }
        string result; 
        for(int i = ans.size() - 1; i >= 0; i--) { 
            result += (ans[i] + '0'); 
        }

        return result;
    }
};