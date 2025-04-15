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
#define N 600005
#define M 750
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
ll a[N];
bool np[N];
bool vis[N];
vector<int> ps;
int main() {
  ps.clear();
  memset(np, false, sizeof(np));
  for (int i = 2; i < N; ++i) {
    if (!np[i]) {
        ps.push_back(i);
        for (int j = 2*i; j < N; j += i) {
            np[j] = true;
        }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int x=n/3;
    int id = lower_bound(ps.begin(), ps.end(), x)-ps.begin();
    int pp=ps[id];
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        vis[i] = false;
    }
    ans.push_back(pp);
    vis[pp]=true;
    for (int i = 1; i <= n; ++i) {
        if (pp-i>=1 && pp-i<=n && pp+i>=1 && pp+i<=n) {
            ans.push_back(pp-i);
            vis[pp-i]=true;
            ans.push_back(pp+i);
            vis[pp+i]=true;
        } else {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) ans.push_back(i);
    }
    for (auto x : ans) {
        printf("%d ", x);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
