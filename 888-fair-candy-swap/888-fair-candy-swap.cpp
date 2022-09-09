class Solution
{
    public:

        vector<int> help(vector<int> small, vector<int> big, int S, int B)
        {
            int req = (S + B) / 2;
            vector<int> ans(2, 0);
            map<int, int> m;
            for (auto b: big)
                m[b]++;
            for (auto s: small)
            {
                if (m.find(req - S + s) != m.end())
                {
                    ans[0] = s;
                    ans[1] = req - S + s;
                    break;
                }
            }
            return ans;
        }

    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        int A, B, S;
        A = B = 0;
        for (auto a: aliceSizes) A += a;
        for (auto b: bobSizes) B += b;
        S = (A + B) / 2;

        if (A < B)
            return help(aliceSizes, bobSizes, A, B);

        else
        {
            vector<int> ans = help(bobSizes, aliceSizes, B, A);
            swap(ans[0], ans[1]);
            return ans;
        }
    }
};