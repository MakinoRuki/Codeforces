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
#define M 52
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, h;
int k;
int q, p;
int a[N];
vector<int> ids[N];
int bit[N];
int lowbit(int x) {
  return x&(-x);
}
void update(int ps) {
  while(ps <= n) {
    bit[ps]++;
    ps += lowbit(ps);
  }
}
int query(int ps) {
  int res=0;
  while(ps) {
    res += bit[ps];
    ps -= lowbit(ps);
  }
  return res;
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ids[a[i]].push_back(i);
  }
  memset(bit, 0, sizeof(bit));
  int st = 0;
  ll tot=0LL;
  for (int i = 1; i < N; ++i) {
    if (ids[i].size() > 0) {
      int det = 0;
      int id2 = st;
      for (int j = 0; j < ids[i].size(); ++j) {
        int id = ids[i][j];
        if (id >= st) {
          int det2 = query(id) - query(st);
          if (id-st-det2 > det) {
            det = id-st-det2;
            id2 = id;
          }
        } else {
          int det2 = query(n)-query(st) + query(id);
          if (n-st +id -det2 > det) {
            det = max(det, n-st + id - det2);
            id2 = id;
          }
        }
      }
      for (int j = 0; j < ids[i].size(); ++j) {
        update(ids[i][j]);
      }
      tot += (ll)det;
      st = id2;
    }
  }
  cout<<tot<<endl;
  return 0;
}
