class Solution 
{
public:
    string reverseWords(string s) 
    {
        string res="";
        int i=0;
        while(i<s.size())
        {
            int len=0, j=i;
            while(j<s.size() && s[j]!=' ')++j,++len;
            string word=s.substr(i,len);
            reverse(word.begin(), word.end());
            res+=(word+" ");
            i=j+1;
        }
        res.pop_back();
        return res;
    }
};