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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int a[N];
int main() {
  cin>>n>>k>>m;
  ll tot = (ll)n * (ll)m;
  ll res = 0LL;
  vector<pair<int,int>> v;
  v.clear();
  deque<int> dq;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (v.empty() || v.back().first != a[i]) {
      v.push_back(make_pair(a[i], 1));
    } else {
      v.back().second++;
      if (v.back().second >= k) {
        res += v.back().second / k  * k;
        v.back().second %= k;
        if (v.back().second == 0) {
          v.pop_back();
        }
      }
    }
  }
  if (m == 1) {
    printf("%lld\n", tot-res);
    return 0;
  }
  res *= (ll)m;
  if (v.size() == 1) {
    ll det = (ll)v.front().second * (ll)m;
    res += det/(ll)k*(ll)k;
    printf("%lld\n", tot-res);
    return 0;
  }
  // if (n==1000 && k==2) {
  //   for (int i = 0; i < v.size(); ++i) {
  //     printf("%d ", v[i].first);
  //   }
  //   cout<<endl;
  // }
  for (int i = 0; i < v.size(); ++i) {
    dq.push_back(i);
  }
  while(dq.size() > 1) {
    int id1 = dq.front();
    int id2 = dq.back();
    if (v[id1].first == v[id2].first) {
      int cur = v[id1].second + v[id2].second;
      if (cur % k == 0) {
        dq.pop_front();
        dq.pop_back();
        res += (ll)cur * (ll)(m-1);
      } else {
        res += (ll)cur/k*(ll)k * (ll)(m-1);
        break;
      }
    } else {
      break;
    }
  }
  if (dq.size() == 1) {
    // if (n==1000 && k==2) {
    //   cout<<"!!"<<endl;
    // }
    ll cur = (ll)m*(v[dq.front()].second);
    if (cur % k == 0) {
      res += cur;
      // if (n == 1000 && k == 2) {
      //   cout<<"res="<<res<<" "<<cur<<endl;
      // }
      vector<pair<int,int>> v2;
      v2.clear();
      int id = dq.front();
      for (int i = 0; i < id; ++i) {
        if (v2.empty() || v2.back().first != v[i].first) {
          v2.push_back(v[i]);
        } else {
          v2.back().second += v[i].second;
          if (v2.back().second >= k) {
            res += (ll)v2.back().second/k * (ll)k;
            v2.back().second %= k;
            if (v2.back().second == 0) {
              v2.pop_back();
            }
          }
        }
      }
      for (int i = id+1; i < v.size(); ++i) {
        if (v2.empty() || v2.back().first != v[i].first) {
          v2.push_back(v[i]);
        } else {
          v2.back().second += v[i].second;
          if (v2.back().second >= k) {
            res += (ll)v2.back().second/k * (ll)k;
            v2.back().second %= k;
            if (v2.back().second == 0) {
              v2.pop_back();
            }
          }
        }
      }
    } else {
      res += (ll)cur/k * (ll)k;
    }
  }
  printf("%lld\n", tot-res);
  return 0;
}
