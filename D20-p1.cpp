class Solution {
public:
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int>in(n,0);
//         vector<int>adj[n];
        
//         for(int i=0;i<n;i++){
//             for(auto it:graph[i]){
//                 adj[it].push_back(i);
//                 in[i++];
//             }
//         }
//         queue<int>q;
//         vector<int>ans;
//         for(int i=0;i<n;i++){
//             if(in[i]==0){
//                 q.push(i);
//                 // ans.push_back(i);
//             }
//         }
//        for(int i=0;i<n;i++){
//            cout<<i<<" ";
//    for(auto it = adj[i].begin(); 
//        it!=adj[i].end(); it++) {
//       cout<<(*it)<<" ";
//     }
//            cout<<endl;
// }
        
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             ans.push_back(node);
//             for(auto it:adj[node]){
//                 in[it]--;
//                 if(in[it]==0){
//                 q.push(it);
//                 }
//             }
            
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>in(n,0);
        
       
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                in[i]++;
            }
        }
        queue<int>q;
        vector<int>res;
        
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
                
            }
            
        }

        // for(auto it: res){
        //     cout<<it<<" ";
        // }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto it: adj[node]){
                in[it]--;
            if(in[it]==0){
                q.push(it);
            }     
             
            }
            
        }
        // for(auto it: res){
        //     cout<<it<<" ";
        // }
        
        sort(res.begin(),res.end());
        return res;
    }
};