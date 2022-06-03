class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        vector<string> mat(numRows, "");
        int cy=0, k=0;
        while(k<s.size())
        {
            if(cy&1)
            {
                for(int j=numRows-2;j>0;--j) 
                {
                    mat[j]+=s[k++];
                    if(k>=s.size())
                        break;
                }
                cy+=1;
            }
            else
            {
                for(int j=0;j<numRows;++j) 
                {
                    mat[j]+=s[k++];
                    if(k>=s.size())
                        break;
                }
                cy+=1;
            }
        }
        string res="";
        for(auto r:mat)
            res+=r;
        return res;
    }
};