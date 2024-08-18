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
#define N 500005
#define M 505
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
int par[N];
int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      par[i] = i;
    }
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = n-1; i >= 1; --i) {
      vector<vector<int>> v;
      v.clear();
      for (int j = 0; j < i; ++j) {
        v.push_back({});
      }
      for (int j = 1; j <= n; ++j) {
        int r = a[j]%i;
        v[r].push_back(j);
      }
      bool found=false;
      for (int r = 0; r < i; ++r) {
        if (v[r].size() > 1) {
          for (int j = 1; j < v[r].size(); ++j) {
            int px = find(v[r][j]);
            int py = find(v[r][0]);
            if (px != py) {
              par[px] = py;
              ans.push_back(make_pair(v[r][j], v[r][0]));
              found=true;
              break;
            }
          }
          if (found) break;
        }
      }
      if (!found) {
        ans.clear();
        break;
      }
    }
    if (n == 1) {
      puts("Yes");
    } else {
      // if (ans.empty()) {
      //   puts("No");
      // } else {
        puts("Yes");
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i) {
          printf("%d %d\n", ans[i].first, ans[i].second);
        }
      //}
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
