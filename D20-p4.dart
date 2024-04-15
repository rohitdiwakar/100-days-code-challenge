  #define ppi pair<int,pair<int,int>>
class Solution {
public:
       int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
     vector<int>dist(n,1e9);
       pq.push({0,{src,0}});
           dist[src]=0;
        int ans=1e9;
        while(!pq.empty()){
            auto f=pq.top(); pq.pop();
            int stop=f.first;
            int node=f.second.first;
            int cost=f.second.second;
             cout<<cost<<node<<stop<<endl;
            // if(node==dst){
            //     ans=min(ans,cost);
            //     continue;
            // }
            for(auto it:adj[node]){
                if( cost+it.second<dist[it.first] && stop<=k){
                    dist[it.first]=cost+it.second;
                    pq.push({stop+1,{it.first,dist[it.first]}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }

};