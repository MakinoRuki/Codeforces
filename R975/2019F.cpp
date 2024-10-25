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
#define N 500005
#define M 1100
#define eps 1e-7
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int par[N];
int cnt[N][2];
int mxv[N][2];
bool vis[N];
int tot;
int num;
int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}
void solve(int x, int y) {
  int px = find(x);
  int py = find(y);
  if (px == py) return;
  tot -= max(cnt[px][0], cnt[px][1]);
  if (cnt[px][0] >= cnt[px][1] && mxv[px][0]) {
    num--;
  } else if (cnt[px][1] >= cnt[px][0] && mxv[px][1]) {
    num--;
  }
  if (px > py) {
    swap(px, py);
  }
  cnt[px][0] += cnt[py][0];
  cnt[px][1] += cnt[py][1];
  mxv[px][0] |= mxv[py][0];
  mxv[px][1] |= mxv[py][1];
  par[py] = px;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    int mx=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mx=max(mx, a[i]);
      rk.push_back(make_pair(a[i], i));
      par[i] = i;
      cnt[i][0] = cnt[i][1] = 0;
      mxv[i][0] = mxv[i][1] = 0;
      if (i%2) cnt[i][1] = 1;
      else cnt[i][0] = 1;
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] == mx) {
        if (i%2) mxv[i][1] = 1;
        else mxv[i][0]= 1;
      }
    }
    num=0;
    tot=0;
    sort(rk.begin(), rk.end());
    ll ans = 0LL;
    int i = rk.size()-1;
    int mn = rk.back().first;
    while(i >= 0) {
      int j;
      for (j = i; j >= 0; --j) {
        if (rk[j].first == rk[i].first) {
          int id = rk[j].second;
          if (id > 1 && vis[id-1]) {
            solve(id-1, id);
          }
          if (id < n && vis[id+1]) {
            solve(id+1, id);
          }
          int pp = find(id);
          tot += max(cnt[pp][0], cnt[pp][1]);
          if (cnt[pp][0] >= cnt[pp][1] && mxv[pp][0]) {
            num++;
          } else if (cnt[pp][1] >= cnt[pp][0] && mxv[pp][1]) {
            num++;
          }
          vis[id]=true;
         // cout<<"id="<<id<<" "<<a[id]<<" "<<num<<" "<<cnt[pp][0]<<" "<<cnt[pp][1]<<" "<<mxv[pp][0]<<" "<<mxv[pp][1]<<endl;
        } else {
          break;
        }
      }
     // cout<<"i="<<i<<" "<<mx<<" "<<mn<<" "<<tot<<" "<<num<<endl;
      mn = rk[i].first;
      ll tmp = mx + mn + tot;
      if (num==0) tmp--;
      ans = max(ans, tmp);
      i = j;
    }
    // if (t == 10000 && cas==22) {
    //   string s= to_string(n);
    //   for (int i = 1; i <= n; ++i) {
    //     s += "#";
    //     s +=  to_string(a[i]);
    //   }
    //   cout<<s<<endl;
    // }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

