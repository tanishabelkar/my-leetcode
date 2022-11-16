/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution 
{
public:
    int guessNumber(int n) 
    {
        int beg = 1, end = n, mid = beg + (end - beg)/2;
        while(beg <= end)
        {
            mid = beg + (end - beg)/2;
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == 1)
                beg = mid + 1;
            else end = mid - 1;
        }
        return mid;
    }
};