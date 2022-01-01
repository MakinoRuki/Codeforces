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
#define N 500000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q, k;
int a[N];
int bit[N];
vector<int> ids[26];
int lowbit(int x) {
  return x&(-x);
}
int query(int id) {
  int tot=0;
  while(id > 0) {
    tot += bit[id];
    id -= lowbit(id);
  }
  return tot;
}
void update(int id) {
  while(id <= n) {
    bit[id] += 1;
    id += lowbit(id);
  }
}
int main() {
  cin>>q;
  for (int cas=1; cas<=q; ++cas) {
    scanf("%d", &n);
    string s, t;
    cin>>s>>t;
    for (int i = 0; i < 26; ++i) {
      ids[i].clear();
    }
    for (int i = n-1; i >= 0; --i) {
      ids[s[i]-'a'].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      bit[i] = 0;
    }
    ll ans=-1;
    ll tot=0;
    for (int i = 0; i < n; ++i) {
      int j;
      int x = n;
      int y = 26;
      for (j = t[i]-'a'-1; j >= 0; --j) {
        if (!ids[j].empty()) {
          if (ids[j].back() < x) {
            x = ids[j].back();
            y = j;
          }
        }
      }
      if (x < n) {
        ll cnt = query(x);
       // cout<<"i="<<i<<" "<<tot<<" "<<x-cnt<<" "<<tot+x-cnt<<endl;
        ans = (ans < 0 ? tot+ x - cnt : min(ans, tot+ x-cnt));
      }
     // cout<<i<<" "<<ans<<endl;
      if (ids[t[i]-'a'].empty()) {
        break;
      }
      int id = ids[t[i]-'a'].back();
      ll cnt=query(id);
      tot += id - cnt;
      ids[t[i]-'a'].pop_back();
      update(id+1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
