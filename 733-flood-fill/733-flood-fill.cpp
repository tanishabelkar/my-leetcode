class Solution 
{
public:
    
    vector<vector<int>> ans;
    
    void help(int sr, int sc, int newColor, int oldColor)
    {
        if(sr>=ans.size() || sr<0)
            return;
        if(sc>=ans[0].size() || sc<0)
            return;
        if(ans[sr][sc] != oldColor)
            return;
        if(newColor==oldColor)
            return;
        
        ans[sr][sc] = newColor;
        help(sr-1, sc, newColor, oldColor);
        help(sr+1, sc, newColor, oldColor);
        help(sr, sc-1, newColor, oldColor);
        help(sr, sc+1, newColor, oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        ans=image;
        help(sr, sc, newColor, image[sr][sc]);
        return ans;
    }
};