#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#define N 3000005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int idx1[N];
int idx2[N];
vector<int> edges[N];
int deg[N];
int ans[N];
int pre[N];
void bfs() {
  queue<int> q;
  for (int i = 1; i <= n+m; ++i) {
    pre[i]=0;
    if (deg[i] == 0) {
      ans[i]=1;
      q.push(i);
    }
  }
  while(!q.empty()) {
    auto u = q.front();
    q.pop();
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      deg[v]--;
      if (ans[u]==0) pre[v]++;
      if (deg[v]==0) {
        if (pre[v]>0) ans[v]=1;
        else ans[v]=0;
        q.push(v);
      }
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;
    v1.clear();
    v2.clear();
    int x;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      v1.push_back(make_pair(a[i], -1));
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      v1[i-1].second = b[i];
    }
    scanf("%d", &m);
    for (int i =1 ; i <= m; ++i) {
      scanf("%d", &a[i+n]);
      v2.push_back(make_pair(a[i+n], -1));
    }
    for (int i =1 ; i <= m; ++i) {
      scanf("%d", &b[i+n]);
      v2[i-1].second = b[i+n];
    }
    for (int i = 1; i <= n+m; ++i) {
      edges[i].clear();
      deg[i]=0;
      ans[i]=-1;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = v1.size()-1; i >= 0; --i) {
      idx1[i] = i;
      if (i+1<v1.size() && v1[idx1[i+1]].second > v1[i].second) {
        idx1[i] = idx1[i+1];
      }
    }
    for (int i = v2.size()-1; i >= 0; --i) {
      idx2[i] = i;
      if (i+1<v2.size() && v2[idx2[i+1]].second > v2[i].second) {
        idx2[i] = idx2[i+1];
      }
    }
    for (int i = 1; i <= n; ++i) {
      auto itr = lower_bound(v2.begin(), v2.end(), make_pair(v1[i-1].second+1, 0))-v2.begin();
      if (itr < v2.size()) {
        int id = idx2[itr]+1;
        edges[id+n].push_back(i);
       // cout<<id+n<<" "<<i<<endl;
        deg[i]++;
      }
    }
    for (int i = 1; i <= m; ++i) {
      auto itr = lower_bound(v1.begin(), v1.end(), make_pair(v2[i-1].second+1, 0))-v1.begin();
      if (itr < v1.size()) {
        int id = idx1[itr]+1;
        edges[id].push_back(i+n);
       //cout<<id<<" "<<i+n<<endl;
        deg[i+n]++;
      }
    }
    bfs();
    int w=0,l=0,d=0;
    for (int i = 1; i<= n; ++i) {
      if (ans[i]==1) w++;
      else if (ans[i]==0) l++;
      else d++;
    }
    printf("%d %d %d\n", w, d, l);
  } 
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

