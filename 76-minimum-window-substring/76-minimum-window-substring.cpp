class Solution
{
    public:
        bool eq(unordered_map<char, int> &ms, unordered_map<char, int> &mt)
        {
            for (auto t: mt)
            {
                if (ms.find(t.first) == ms.end() || ms[t.first] < t.second)
                    return false;
            }
            return true;
        }

    string minWindow(string s, string t)
    {
        unordered_map<char, int> smap, tmap;
        for (auto c: t) tmap[c] += 1;
        int i = 0, j;
        for (j = 0; j < s.size(); ++j)
        {
            ++smap[s[j]];
            if (eq(smap, tmap))
                break;
        }

        if (j >= s.size() && !eq(smap, tmap))
            return "";

        string res = s.substr(i, j - i + 1);
        while (j < s.size())
        {
            while (i <= j)
            {
                --smap[s[i]];
                if (!eq(smap, tmap))
                {
                    ++smap[s[i]];
                    break;
                }
                ++i;
            }
            // cout << i << " " << j << "\n";
            if (j - i + 1 < res.size() && j - i + 1 >= 1)
                res = s.substr(i, j - i + 1);
            ++j;
            ++smap[s[j]];
        }

        return res;
    }
};