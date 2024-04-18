class Disjointset{
    public:
    vector<int>size,par;

    Disjointset(int n){
        size.resize(n+1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            size[i]=1;
        }
    }

    int findpar(int node){
        if(node == par[node])return node;
        return par[node]= findpar(par[node]);
    }

    void unionbysize(int u,int v){
        int pu=findpar(u);
        int pv=findpar(v);
        if(pu==pv)return;

        if(size[pu]<size[pv]){
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else if(size[pv]<=size[pu]){
            par[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    // Write your code here.
    // vector<int>ans;
    // int ele=queries.size();
    Disjointset ds(n*m);
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt=0;
    vector<int>ans;

    for(auto it:queries){
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1)ans.push_back(cnt);
        else{
            vis[row][col]=1;
            cnt++;
            int dx[]={0,-1,0,+1};
            int dy[]={+1,0,-1,0};
            for(int i=0;i<4;i++){
                int adjr=row+dx[i];
                int adjc=col+dy[i];
                if(adjr>=0 && adjr<n && adjc>=0 && adjc<m && vis[adjr][adjc]==1)
                {
                    int node=(row*m)+col;
                    int adjnode=(adjr*m)+adjc;
                    
                    if(ds.findpar(node)!=ds.findpar(adjnode)){
                        ds.unionbysize(node,adjnode);
                        cnt--;
                    }
                }
            }
            ans.push_back(cnt);
        }

    }
    return ans;
    

}
