#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<ll>dist(n+1,1e18);
        vector<ll>vis(n,-1);
        int mod=1e9+7;
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
        pq.push({0,0});
        vector<ll>ways(n,0);
        vis[0]=1;
        dist[0]=0;
        ways[0]=1;
         while(!pq.empty()){
            auto f=pq.top();pq.pop();
            ll node=f[1];
            ll time=f[0];
            
            for(auto it:adj[node]){
                ll adjnode=it.first;
                ll adjtime=it.second;
                if(time+adjtime<dist[adjnode] ){
                    dist[adjnode]=time+adjtime;
                    pq.push({time+adjtime,adjnode});
                    ways[adjnode]=ways[node];
                    // vis[adjnode]=1;
                    // ans=max(ans,time+adjtime);
                }
                else if(time+adjtime==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
         }
        return ways[n-1];
    }
};