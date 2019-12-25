#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int t,n;
int deg[N];
map<pair<int, int>, int> cnt;
vector<int> p1, p2;
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    cin>>n;
    vector<pair<pair<int, int>, int>> edges;
    edges.clear();
    unordered_map<int, vector<int>> ids;
    ids.clear();
    memset(deg, 0, sizeof(deg));
    cnt.clear();
    for (int i= 0; i < n-2; ++i) {
      int u,v,w;
      cin>>u>>v>>w;
      vector<int> tmp = {u,v,w};
      sort(tmp.begin(), tmp.end());
      u=tmp[0], v= tmp[1], w=tmp[2];
      deg[u]++;
      deg[v]++;
      deg[w]++;
      cnt[make_pair(u,v)]++;
      cnt[make_pair(u,w)]++;
      cnt[make_pair(v,w)]++;
      edges.push_back(make_pair(make_pair(u, v), w));
      ids[u].push_back(i);
      ids[v].push_back(i);
      ids[w].push_back(i);
    }
    bool vis[N];
    memset(vis, false, sizeof(vis));
    queue<int> q;
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i].first.first;
      int v = edges[i].first.second;
      int w= edges[i].second;
      if (deg[u] == 1 || deg[v] ==1 || deg[w]==1) {
        if (!vis[i]) {
          vis[i]=true;
          q.push(i);
          //cout<<"i="
        }
      }
    }
    p1.clear();
    p2.clear();
    while(!q.empty()) {
      int cur=q.front();
      q.pop();
      p2.push_back(cur+1);
      int u = edges[cur].first.first;
      int v = edges[cur].first.second;
      int w = edges[cur].second;
      deg[u]--;
      if (deg[u] == 1) {
        for (int i = 0; i < ids[u].size(); ++i) {
          if (!vis[ids[u][i]]) {
            vis[ids[u][i]] = true;
            q.push(ids[u][i]);
          }
        }
      }
      deg[v]--;
      if (deg[v] == 1) {
        for (int i = 0; i < ids[v].size(); ++i) {
          if (!vis[ids[v][i]]) {
            vis[ids[v][i]] = true;
            q.push(ids[v][i]);
          }
        }
      }
      deg[w]--;
      if (deg[w] == 1) {
        for (int i = 0; i < ids[w].size(); ++i) {
          if (!vis[ids[w][i]]) {
            vis[ids[w][i]] = true;
            q.push(ids[w][i]);
          }
        }
      }
    }
    int lr[N][2];
    memset(lr, -1, sizeof(lr));
    for (auto c : cnt) {
      if (c.second > 1) continue;
      int u = c.first.first;
      int v = c.first.second;
  //    cout<<"u="<<u<<" "<<"v="<<v<<endl;
      if (lr[u][0] < 0) lr[u][0]=v;
      else lr[u][1] = v;
      if (lr[v][0] < 0) lr[v][0] = u;
      else lr[v][1] = u;
    }
    // for (int i = 1; i <= n; ++i) {
    //   cout<<"i="<<i<<endl;
    //   cout<<lr[i][0]<<" "<<lr[i][1]<<endl;
    // }
    p1.push_back(1);
    int cur=lr[1][1];
    int pre=1;
    for (int i = 1; i < n; ++i) {
      p1.push_back(cur);
     // cout<<"cur="<<cur<<endl;
      if (lr[cur][1] == pre) {
        pre= cur;
        cur = lr[cur][0];
      } else {
        pre= cur;
        cur = lr[cur][1];
      }
     // cout<<cur<<" "<<pre<<endl;
    }
    for (int i = 0;i < p1.size(); ++i) {
      cout<<p1[i];
      if (i < p1.size()-1) cout<<" ";
      else cout<<endl;
    }
    for (int i = 0; i < p2.size(); ++i) {
      cout<<p2[i];
      if (i < p2.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
