/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i=0;
        int j=n;
        int mid=j-(j-i)/2;
        while(j>=i){
            if(guess(mid)==0){
                return mid;
            }else if(guess(mid)==-1){
                j=mid-1;
            }else{
                i=mid+1;
            }
            mid=j-(j-i)/2;
        }
        return 0;
    }
};