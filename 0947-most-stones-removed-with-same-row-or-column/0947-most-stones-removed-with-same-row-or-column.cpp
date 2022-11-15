class Solution
{
    public:
        int removeStones(vector<vector < int>> &stones)
        {
            int ans = 0;
            map<vector < int>, int> vis;
            unordered_map<int, vector<vector< int>>> row, col;
            for (auto i: stones)
            {
            	// save spots of each stone so we don't have to do 10kx10k iterations
                row[i[0]].push_back(i);
                col[i[1]].push_back(i);
            }
            queue<vector < int>> q;	// bfs queue
            for (auto i: stones)
            {
                if (vis[i]) continue;	// component already finished
                q.push(i);	// start bfs for this component
                int cur = 0;
                while (!q.empty())
                {
                    auto temp = q.front();
                    q.pop();
                    if (vis[temp]) continue;	// component already finished
                    vis[temp]++;
                    cur++;
                    for (auto j: row[temp[0]]) q.push(j);	// explore all horizontal neighbors
                    for (auto j: col[temp[1]]) q.push(j);	// explore all vertical neighbros
                }
                ans += max(0, cur - 1);	// add component-1 to answer
            }
            return ans;
        }
};