/* 模拟。找寻环节。 */

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
#define N 1000005
#define M 1500
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int cnt[2][N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);

  // }
  int x;
  cin>>n>>k>>x;
  map<vector<pair<int,int>>, int> mp;
  mp.clear();
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[0][a[i]]++;
  }
  vector<pair<int,int>> v;
  v.clear();
  for (int i = 1; i < M; ++i) {
    if (cnt[0][i]) {
      v.push_back(make_pair(i, cnt[0][i]));
    }
  }
  mp[v] = 0;
  int cycle = -1;
  int stepb = -1;
  int stepl = -1;
  for (int i = 1; i <= k; ++i) {
    int now = i&1;
    for (int j = 0; j < M; ++j) {
      cnt[now][j] = 0;
    }
    int cur = 1;
    for (int j = 0; j < M; ++j) {
      if (cnt[now^1][j]) {
        int dt = cnt[now^1][j];
        if (dt % 2) {
          if (cur) {
            cnt[now][j^x] += (dt+1)/2;
            cnt[now][j] += dt- (dt+1)/2;
          } else {
            cnt[now][j^x] += dt/2;
            cnt[now][j] += dt-dt/2;
          }
          cur = !cur;
        } else {
          cnt[now][j^x] += dt/2;
          cnt[now][j] += dt- dt/2;
        }
      }
    }
    vector<pair<int,int>> vv;
    vv.clear();
    for (int j = 0; j < M; ++j) {
      if (cnt[now][j]) {
        vv.push_back(make_pair(j, cnt[now][j]));
      }
    }
    if (mp.find(vv) != mp.end()) {
      stepb = mp[vv];
      stepl = i-mp[vv];
      break;
    }
    mp[vv] = i;
  }
  int nn = k;
//  cout<<"step="<<stepb<<" "<<stepl<<endl;
  if (stepb >= 0) {
    int r = (k-stepb) % stepl;
    r += stepb;
    nn = r;
    for (int i = 0; i < M; ++i) {
      cnt[0][i] = 0;
      cnt[1][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      cnt[0][a[i]]++;
    }
    for (int i = 1; i <= r; ++i) {
      int now = i&1;
      for (int j = 0; j < M; ++j) {
        cnt[now][j] = 0;
      }
      int cur=1;
      for (int j = 0; j < M; ++j) {
        if (cnt[now^1][j]) {
          int dt = cnt[now^1][j];
          if (dt % 2) {
            if (cur) {
              cnt[now][j^x] += (dt+1)/2;
              cnt[now][j] += dt- (dt+1)/2;
            } else {
              cnt[now][j^x] += dt/2;
              cnt[now][j] += dt-dt/2;
            }
            cur = !cur;
          } else {
            cnt[now][j^x] += dt/2;
            cnt[now][j] += dt- dt/2;
          }
        }
      }
    }
  }
  int mn = inf, mx = -1;
  for (int i = 0; i < M; ++i) {
    if (cnt[nn&1][i]) {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  cout<<mx<<" "<<mn<<endl;
// dedup??
  return 0;
}


 
