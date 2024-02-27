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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int mx1=0;
    int mx0=0;
    int cnt0=0;
    int cnt1=0;
    int id0=-1;
    int id1=-1;
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] < 0) {
        if (abs(a[i])>abs(mx0)) {
          mx0=a[i];
          id0=i;
        }
        cnt0++;
      } else if (a[i] > 0) {
        if (abs(a[i])>abs(mx1)) {
          mx1=a[i];
          id1=i;
        }
        cnt1++;
      }
    }
    if (cnt0 > 0 && cnt1>0) {
      int cur0=abs(mx0);
      int n0=0;
      int cur1=abs(mx1);
      int n1=0;
      while(cur0 < max(abs(mx0), abs(mx1))) {
        n0++;
        cur0*=2;
      }
      while(cur1< max(abs(mx0), abs(mx1))) {
        n1++;
        cur1*=2;
      }
      if (n0+cnt1 < n1+cnt0) {
        for (int i =1; i <= n0; ++i) {
          ans.push_back(make_pair(id0, id0));
        }
        for (int i = 1; i <= n; ++i) {
          if (a[i] > 0) {
            ans.push_back(make_pair(i, id0));
          }
        }
        for (int i = n-1; i >= 1; --i) {
          ans.push_back(make_pair(i, i+1));
        }
      } else {
        for (int i =1; i <= n1; ++i) {
          ans.push_back(make_pair(id1, id1));
        }
        for (int i = 1; i <= n; ++i) {
          if (a[i] < 0) {
            ans.push_back(make_pair(i, id1));
          }
        }
        for (int i = 2; i <= n; ++i) {
          ans.push_back(make_pair(i, i-1));
        }
      }
    } else if (cnt0 <= 0) {
      for (int i = 2; i <= n; ++i) {
          ans.push_back(make_pair(i, i-1));
        }
    } else {
      for (int i = n-1; i >= 1; --i) {
          ans.push_back(make_pair(i, i+1));
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
