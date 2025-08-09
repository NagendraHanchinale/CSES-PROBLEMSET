#include<bits/stdc++.h>
using namespace std;
class DisJointSet {
   public:
    vector<int> parent , size;
   DisJointSet(int n){
      parent.resize(n + 1);
      size.resize(n + 1);
      for(int i = 0 ; i <= n ; ++i){
         parent[i] = i;
         size[i] = 1;
      }
   }
   
   int find(int node){
      if(parent[node] == node)return node;
      return parent[node] = find(parent[node]);
   }

   void unionSize(int u , int v){
      int ul_u = find(u);
      int ul_v = find(v);
      if(ul_u == ul_v)return;
      if(size[ul_u] > size[ul_v]){
         parent[ul_v] = ul_u;
         size[ul_u] += size[ul_v];
      }else{
         parent[ul_u] = ul_v;
         size[ul_v] += size[ul_u];
      }
   }
};
int main() {
    int n , m;
    cin >> n >> m;
    DisJointSet ds(n);
    while(m--){
        int a , b;
        cin >> a >> b;
        if(ds.find(a) != ds.find(b)){
            ds.unionSize(a , b);
        }
    }
    int cnt = 0;
    vector<int> ans;
    for(int i = 1 ;i <= n ; ++i){
        if(ds.parent[i] == i){
          cnt++;
          ans.push_back(i);
        }
    }

    cout << cnt - 1 << endl;
    for(int i = 0 ; i < ans.size() - 1 ; ++i){
        cout << ans[i] << " " << ans[i + 1] << endl;
    }

    return 0;
}