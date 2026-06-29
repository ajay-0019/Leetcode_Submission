class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        if(arr.size()==0 || arr.size()==1){
            return false;
        }
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0 && arr[i+1]==0) return true;
            if(find(arr.begin(), arr.end(), 2*arr[i]) != arr.end() && arr[i]!=0){
                return true;
            }
        }
        return false;
    }
};