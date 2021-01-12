#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 31
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, tt;
vector<pair<int, int>> at;
int main() {
  cin>>n>>tt;
  at.clear();
  for (int i = 1; i <= n; ++i) {
    int a,t;
    scanf("%d%d", &a, &t);
    at.push_back(make_pair(a,t));
  }
  int l = 0, r = n;
  while(l < r) {
    int mid= (l+r+1)/2;
    vector<int> ts;
    ts.clear();
    for (int i = 0; i < n; ++i) {
      if (at[i].first >= mid) {
        ts.push_back(at[i].second);
      }
    }
    if (ts.size() < mid) {
      r = mid-1;
    } else {
      sort(ts.begin(), ts.end());
      ll tot=0LL;
      for (int i = 0; i < mid; ++i ){
        tot += ts[i];
      }
      if (tot <= tt) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
  }
  cout<<r<<endl;
  vector<pair<int,int>> ts;
  ts.clear();
  for (int i = 0; i < n; ++i) {
    if (at[i].first >= r) {
      ts.push_back(make_pair(at[i].second, i+1));
    }
  }
  cout<<r<<endl;
  sort(ts.begin(), ts.end());
  for (int i = 0; i < r; ++i) {
    printf("%d", ts[i].second);
    if (i<r-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
