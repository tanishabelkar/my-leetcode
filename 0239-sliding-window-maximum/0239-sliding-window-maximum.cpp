class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            priority_queue<pair<int, int>> pq;
            vector<int> res(nums.size() - k + 1);
            int j = 0;
            for (int i = 0; i < k; ++i)
                pq.push(make_pair(nums[i], i));

            res[j++] = (pq.top().first);

            for (int i = k; i < nums.size(); ++i)
            {
                pq.push(make_pair(nums[i], i));
                while (pq.top().second < i - k + 1)
                    pq.pop();
                res[j++] = (pq.top().first);
            }

            return res;
        }
};