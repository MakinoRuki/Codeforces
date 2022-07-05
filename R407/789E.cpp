#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 5002
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
bool b[N];
int dis[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>n>>k;
  memset(b, false, sizeof(b));
  set<int> ss;
  ss.clear();
  for (int i =1; i <= k; ++i) {
    scanf("%d", &a[i]);
    //b[a[i]-n+2000] = true;
    ss.insert(a[i]-n);
  }
  for (int i = 0; i <= 5000; ++i) {
    dis[i] = inf;
  }
  queue<int> q;
  vector<int> v(ss.begin(), ss.end());
  for (int i = 0; i < v.size(); ++i) {
    dis[v[i]+2000] = 1;
    q.push(v[i]+2000);
  }
  while(!q.empty()) {
    auto u = q.front();
    q.pop();
   // cout<<"u="<<u<<endl;
    if (u == 2000) {
      printf("%d\n", dis[u]);
      return 0;
    }
    for (int i = 0; i < v.size(); ++i) {
      if (u + v[i] >= 0 && u + v[i] <= 4000 && dis[u] + 1 < dis[u+v[i]]) {
        dis[u+v[i]] = dis[u]+1;
        q.push(u + v[i]);
      }
    }
  }
  puts("-1");
  return 0;
}
