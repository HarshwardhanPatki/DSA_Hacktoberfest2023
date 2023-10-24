
// Multi Source BFS

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    bool isSafe(int x,int y,int n,int m,vector<vector<int>>& grid)
    {
        if(x<0 or x>=n or y<0 or y>=m or grid[x][y]==0) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<pair<int,int>,int>> q;
        int cnt=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1) cnt++;
            }
        }
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        int count=0;
        int ans=0;
        while(!q.empty())
        {
            auto node = q.front();
            int t = q.front().second;
            ans=max(ans,t);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = node.first.first + dx[i];
                int ny = node.first.second + dy[i];
                if(isSafe(nx,ny,n,m,grid) and grid[nx][ny]==1 and !vis[nx][ny])
                {
                    q.push({{nx,ny},t+1});
                    vis[nx][ny]=1;
                    count++;
                }
            }
            
        }
        
        if(count!=cnt) return -1;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
