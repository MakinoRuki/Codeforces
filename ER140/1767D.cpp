#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 400005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
vector<int> edges[N];
vector<int> edges2[N];
bool vis[N];
void dfs1(int u, int& cnt) {
  vis[u] = true;
 // cout<<"u="<<u<<endl;
  if (u != 1) cnt++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (!vis[v]) dfs1(v, cnt);
  }
}
void dfs2(int u, int& cnt) {
  vis[u] = true;
 // cout<<"u2="<<u<<endl;
  if (u != 1) cnt++;
  for (int i = 0; i < edges2[u].size(); ++i) {
    int v = edges2[u][i];
    if (!vis[v]) dfs2(v, cnt);
  }
}
int main() {
  cin>>n;
  string s;
  cin>>s;
  vector<int> v;
  v.clear();
  for (int i = 1; i <= (1<<n); ++i) {
    v.push_back(i);
  }
  for (int i = 0; i < s.size(); ++i) {
    vector<int> v2;
    v2.clear();
    if (s[i] == '1') {
      for (int j = 0; j < v.size(); j += 2) {
        int x = v[j];
        int y = v[j+1];
        edges[x].push_back(y);
       // cout<<"xy="<<x<<" "<<y<<endl;
        edges2[y].push_back(x);
        v2.push_back(x);
      }
    } else {
      for (int j = 0; j < v.size(); j += 2) {
        int x = v[j];
        int y = v[j+1];
        edges[y].push_back(x);
      //  cout<<"xy="<<y<<" "<<x<<endl;
        edges2[x].push_back(y);
        v2.push_back(x);
      }
    }
    v = v2;
  }
  memset(vis, false, sizeof(vis));
  int cnt1=0,cnt2=0;
  dfs1(1, cnt1);
  memset(vis, false, sizeof(vis));
  dfs2(1, cnt2);
  //cout<<"cnt1="<<cnt1<<" "<<cnt2<<endl;
  int l = cnt1+1;
  int r = (1<<n) - cnt2;
  if (l <= r) {
    for (int i = l; i <= r; ++i) {
      printf("%d", i);
      if (i < r) cout<<" ";
      else cout<<endl;
    }
  } else {
    puts("0");
  }
  return 0;
}
