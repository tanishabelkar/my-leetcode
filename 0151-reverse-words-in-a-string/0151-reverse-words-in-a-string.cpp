class Solution 
{
public:
    string reverseWords(string s) 
    {
        //vector<string> v;
        string res="";
        for(int i=0;i<s.size();++i)
        {
            string word="";
            while(i<s.size() && isalnum(s[i]))
                word+=s[i++];
            if(!word.empty())
                res=word+" "+res;
        }
        /*string res=v.back();
        for(int i=v.size()-2;i>=0;--i)
        {
            res+=" ";
            res+=v[i];
        }*/
        res.pop_back();
        return res;
    }
};