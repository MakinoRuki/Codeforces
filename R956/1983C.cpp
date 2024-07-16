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
const int base=337;
int n, m, k, q;
int t;
int a[3][N];
ll tot;
void getans(int i, int j, int k, vector<pair<int,int>>& ans) {
  ll sum=0;
  for (int i = 0; i < 3; ++i) {
    ans.push_back(make_pair(0, 0));
  }
  int p = 1;
  while(p <= n && sum < (tot+2)/3) {
    sum += a[i][p];
    p++;
  }
  if (p > n) {
    ans.clear();
    return;
  }
  ans[i] = make_pair(1, p-1);
  sum = 0;
  while(p <= n && sum < (tot+2)/3) {
    sum += a[j][p];
    p++;
  }
  if (p > n) {
    ans.clear();
    return;
  }
  ans[j] = make_pair(ans[i].second+1, p-1);
  sum=0;
  while(p <= n) {
    sum += a[k][p];
    p++;
  }
  if (sum < (tot+2)/3) {
    ans.clear();
    return;
  }
  ans[k] = make_pair(ans[j].second+1, n);
  return;
}
int main() {
  cin>>t;
  int cnt=0;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    tot = 0LL;
    for (int i = 0; i < 3; ++i) {
      for (int j =1 ; j <= n; ++j) {
        scanf("%d", &a[i][j]);
        if (i == 0) tot += a[i][j];
      }
    }
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if ((i != j) && (i != k) && (j != k)) {
            getans(i, j, k, ans);
            if (!ans.empty()) {
              break;
            }
          }
        }
        if (!ans.empty()) break;
      }
      if (!ans.empty()) break;
    }
    if (ans.empty()) puts("-1");
    else {
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d ", ans[i].first, ans[i].second);
      }
      cout<<endl;
    }
  }
  return 0;
}
