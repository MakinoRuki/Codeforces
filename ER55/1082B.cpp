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
#define M 21
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
int x,y,d;
string s;
int main() {
  cin>>n;
  cin>>s;
  int id = -1;
  int cnt=0;
  vector<pair<int,int>> segs;
  segs.clear();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'G') {
      cnt++;
      if (id < 0) id = i;
    } else {
      if (cnt>0) {
        segs.push_back(make_pair(id, cnt));
      }
      id = -1;
      cnt=0;
    }
  }
  if (cnt>0) {
    segs.push_back(make_pair(id, cnt));
  }
  if (segs.size() == 0) {
    printf("%d\n", 0);
  } else if (segs.size() == 1) {
    printf("%d\n", segs[0].second);
  } else if (segs.size() == 2) {
    int res=max(segs[0].second+1, segs[1].second+1);
    if (segs[0].first+segs[0].second+1 == segs[1].first) {
      res = max(res, segs[0].second+segs[1].second);
    }
    printf("%d\n", res);
  } else {
    int res=0;
    for (int i = 0; i < segs.size(); ++i) {
      res = max(res, segs[i].second+1);
    }
    for (int i = 0; i < segs.size()-1; ++i) {
      if (segs[i].first+segs[i].second+1 == segs[i+1].first) {
        res = max(res, segs[i].second+segs[i+1].second+1);
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
