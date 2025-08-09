#include<bits/stdc++.h>
using namespace std;
int main() {
    int n , m;
    cin >> n >> m;

    queue<int> q;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1 , 0);
    vector<int> parent(n + 1);
    vector<int> ans;

    for(int i = 0 ;i < m ; ++i){
        int u ,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    q.push(1);
    vis[1] = 1;
    parent[1] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){
           if(!vis[it]){
              vis[it] = 1;
              parent[it] = node;
              q.push(it);
           }
        }
    }

    int des = n;
    while(parent[des] != des){
        ans.push_back(des);
        des = parent[des];
    }

    reverse(begin(ans) , end(ans));

    if(parent[ans[0]] != 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << ans.size() + 1 << endl;
    cout << 1 << " ";
    for(auto it : ans)cout << it << " ";
    cout << endl;

    return 0;
}


