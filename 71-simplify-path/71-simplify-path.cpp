class Solution
{
    public:
        string simplifyPath(string path)
        {
            stack<string> s;
            string res = "";
            int i = 0;
            while (i < path.size())
            {
                if (path[i] == '/')
                {
                    ++i;
                    string curr = "";
                    while (i < path.size() && path[i] != '/')
                    {
                        curr.push_back(path[i]);
                        ++i;
                    }
                    if (curr.size() > 0)
                    {
                        if (curr == ".");
                        else if (curr == "..")
                        {
                            if (!s.empty()) s.pop();
                        }
                        else s.push(curr);
                    }
                }
                else ++i;
            }

            if (s.empty()) res = "/";
            while (!s.empty())
            {
                res = ("/" + s.top() + res);
                s.pop();
            }
            return res;
        }
};