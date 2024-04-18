class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<int>>& vis,vector<vector<int>>& grid,int &cnt){
        vis[i][j]=1;
         int dx[]={0,-1,0,+1};
         int dy[]={+1,0,-1,0};
         for(int dir=0;dir<4;dir++){
            int newi=i+dx[dir];
            int newj=j+dy[dir];
            if(newi<0 || newi>=n || newj<0 || newj>=m || grid[newi][newj]==0 ){
                cnt++;
            }
            else if(vis[newi][newj]==0 && grid[newi][newj]==1){
                dfs(newi,newj,n,m,vis,grid,cnt);
            }
         }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    dfs(i,j,n,m,vis,grid,cnt);
                }
            }
        }
        return cnt;
    }
};