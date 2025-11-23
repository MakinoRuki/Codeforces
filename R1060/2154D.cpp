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
#include <chrono>
#define N 300005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int deg[N];
vector<int> edges[N];
int par[N];
bool mk[N];
int dep[N];
void dfs(int u, int p, int d) {
    dep[u] = d;
    par[u] = p;
    for (auto v : edges[u]) {
        if (v == p) continue;
        dfs(v, u, d+1);
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        deg[i]=0;
        edges[i].clear();
        mk[i]=false;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
  //  cout<<"!!!"<<endl;
    dfs(1, 0, 1);
    //cout<<"??"<<endl;
    int cur=n;
    vector<int> vv;
    vv.clear();
    while(true) {
        mk[cur]=true;
        vv.push_back(cur);
        if (cur == 1) break;
        cur=par[cur];
    }
  //  cout<<"??2"<<endl;
    set<int> s0, s1;
    s0.clear();
    s1.clear();
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1 && !mk[i]) {
            if (dep[i]&1) s1.insert(i);
            else s0.insert(i);
        }
    }
  //  cout<<"??3"<<endl;
    vector<pair<int,int>> ans;
    ans.clear();
    cur=1;
    while(!s0.empty() || !s1.empty()) {
        if (cur&1) {
            if (!s0.empty()) {
                int u = *s0.begin();
                ans.push_back(make_pair(2, u));
                s0.erase(u);
                for (auto v : edges[u]) {
                    deg[v]--;
                    if (deg[v] == 1 && !mk[v]) {
                        if (dep[v]&1) s1.insert(v);
                        else s0.insert(v);
                    }
                }
            }
            ans.push_back(make_pair(1, -1));
            cur = !cur;
        } else {
            if (!s1.empty()) {
                int u = *s1.begin();
                ans.push_back(make_pair(2, u));
                s1.erase(u);
                for (auto v : edges[u]) {
                    deg[v]--;
                    if (deg[v] == 1 && !mk[v]) {
                        if (dep[v]&1) s1.insert(v);
                        else s0.insert(v);
                    }
                }
            }
            ans.push_back(make_pair(1, -1));
            cur = !cur;
        }
    }
    if (cur&1) {
        ans.push_back(make_pair(1,-1));
        cur = !cur;
    }
    reverse(vv.begin(), vv.end());
    for (int i = 0; i < (int)vv.size()-1; ++i) {
        ans.push_back(make_pair(2, vv[i]));
        ans.push_back(make_pair(1, -1));
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i].first == 1) puts("1");
        else printf("%d %d\n", 2, ans[i].second);
    }
    puts("");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
