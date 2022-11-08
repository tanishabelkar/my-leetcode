class Solution
{
    bool isOperator(string & s)
    {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    long int evaluate(long int &a, long int &b, string &s)
    {
        if (s == "+")
            return a + b;
        if (s == "-")
            return b - a;
        if (s == "*")
            return a * b;
        if (s == "/")
            return b / a;
        
        return 0;
    }
    
    long int toInt(string &s)
    {
        long int res = 0;
        bool neg = (s[0] == '-');
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
                res += (s[i] - '0')*pow(10, s.size() - 1 - i);
        }
        if (neg)
            res *= (-1);
        return res;
    }
    public:
        int evalRPN(vector<string> &tokens)
        {
            stack<long int> s;
            for (auto t: tokens)
            {
                if (isOperator(t))
                {
                    long int a = s.top();
                    s.pop();
                    long int b = s.top();
                    s.pop();

                    s.push(evaluate(a, b, t));
                }
                else
                    s.push(toInt(t));
            }

            return s.top();
        }
};