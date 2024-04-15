class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        int ans=INT_MIN;
        while(!pq.empty()){
            auto f=pq.top();pq.pop();
            int node=f[1];
            int time=f[0];
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjtime=it.second;
                if(time+adjtime<dist[adjnode]){
                    dist[adjnode]=time+adjtime;
                    pq.push({time+adjtime,adjnode});
                    // ans=max(ans,time+adjtime);
                }
        }
        }
        for(int i=1;i<=n;i++){
            if(i!=k && dist[i]==1e9)
            return -1;
            else{
                ans=max(ans,dist[i]);
            }
        }
        // cout<<endl;
        return ans;
    }
};