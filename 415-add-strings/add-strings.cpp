class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string ans="";
        while(i>=0 && j>=0){
            int l1=num1[i]-'0';
            int l2=num2[j]-'0';
            int sum = l1 + l2 + carry;
            carry = sum / 10;
            ans += (sum % 10) + '0';
            i--;
            j--;
        }
        while(i>=0){
            int l1=num1[i]-'0';
            int sum = l1 + carry;
            carry = sum / 10;
            ans += (sum % 10) + '0';
            i--;
        }
        while(j>=0){
            int l1=num2[j]-'0';
            int sum = l1 + carry;
            carry = sum / 10;
            ans += (sum % 10) + '0';
            j--;
        }
        if(carry){
            ans+=carry+'0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};