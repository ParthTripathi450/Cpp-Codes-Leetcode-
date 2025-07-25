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
        int low=0;
        int high=n;
        int mid;
        while(high>=low){
            mid=low+(high-low)/2;
            int pick = guess(mid);
            if(pick==-1){
                high=mid-1;
            }else if(pick==1){
                low=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};