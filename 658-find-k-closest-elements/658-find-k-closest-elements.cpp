class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
            int beg = 0, end = arr.size() - 1, mid;
            while (beg <= end)
            {
                mid = (beg + end) / 2;
                if (arr[mid] > x)
                    end = mid - 1;
                else beg = mid + 1;
            }
            // cout << beg << " " << end;
            int left = end, right = end+1;
            vector<int> res;
            while (res.size() != k)
            {
                if (left < 0 || right >= arr.size())
                    break;
                if (abs(arr[left] - x) <= abs(arr[right] - x))
                {
                    res.push_back(arr[left]);
                    left -= 1;
                }
                else
                {
                    res.push_back(arr[right]);
                    right += 1;
                }
            }
            if (left >= 0)
            {
                while (res.size() != k)
                {
                    res.push_back(arr[left]);
                    left -= 1;
                }
            }
            if (right < arr.size())
            {
                while (res.size() != k)
                {
                    res.push_back(arr[right]);
                    right += 1;
                }
            }
            sort(res.begin(), res.end());
            return res;
        }
};