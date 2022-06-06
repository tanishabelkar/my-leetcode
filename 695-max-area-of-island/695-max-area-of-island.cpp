class Solution 
{
public:
    
    vector<vector<int>> visit;
    
    int getArea(vector<vector<int>> grid, int r, int c)
    {
        if(r>=grid.size() || r<0)
            return 0;
        if(c>=grid[0].size() || c<0)
            return 0;
        if(visit[r][c]==1)
            return 0;
        
        visit[r][c]=1;
        if(grid[r][c]==0)
            return 0;
        else return 1+getArea(grid, r+1, c)+getArea(grid, r-1, c)+getArea(grid, r, c+1)+getArea(grid, r, c-1);
        
    }  
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        visit.resize(grid.size(), vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]==1 && visit[i][j]==0)
                    ans=max(ans, getArea(grid,i,j));
            }
        }
        
        return ans;
    }
};