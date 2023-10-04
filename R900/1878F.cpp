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
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int pr[N];
vector<int> ps;
vector<pair<int,int>> calc(ll x) {
  vector<pair<int,int>> res;
  res.clear();
  for (int i = 0; i < ps.size() && ps[i]*ps[i] <= x; ++i) {
    if (x % ps[i] == 0) {
      int num=0;
      while(x % ps[i] == 0) {
        num++;
        x/=ps[i];
      }
      res.push_back(make_pair(ps[i], num));
    }
  }
  if (x > 1) res.push_back(make_pair(x, 1));
  return res;
}
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
bool check(map<ll, int>& cnt) {
  ll tot = 1LL;
  for (auto itr : cnt) {
    tot *= (ll)(itr.second + 1);
  }
  for (auto itr : cnt) {
  //  cout<<"tot="<<tot<<" "<<itr.first<<" "<<itr.second<<endl;
    int num=0;
    while((tot % itr.first) == 0) {
      tot /= itr.first;
      num++;
    }
    if (num > itr.second) {
      return false;
    }
  }
  if (tot > 1) {
    return false;
  }
  return true;
}
int main() {
  memset(pr, true, sizeof(pr));
  for (int i = 2; i <= 1000; ++i) {
    if (pr[i]) {
      for (int j = 2*i; j <= 1000; j += i) {
        pr[j] = false;
      }
    }
  }
  ps.clear();
  for (int i = 2; i <= 1000; ++i) {
    if (pr[i]) {
      ps.push_back(i);
    }
  }
  cin>>t;
  ll n;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld%d", &n, &q);
    map<ll, int> cnt;
    ll tot = 1LL;
    vector<pair<int,int>> v = calc(n);
    for (auto xx : v) {
      tot *= (ll)(xx.second + 1LL);
      cnt[xx.first] = xx.second;
    }
    map<ll, int> cnt2 = cnt;
    ll n2 = n;
    // if (cnt.find(1) != cnt.end()) {
    //   cout<<"fffff"<<endl;
    // }
    while(q-->0) {
      int x;
      int tp;
      scanf("%d", &tp);
      if (tp == 1) {
        scanf("%d", &x);
        ll tmpx = x;
      //  cout<<"???"<<endl;
        for (auto& itr : cnt) {
          int numx=0;
          while(tmpx % itr.first == 0) {
            numx++;
            tmpx /= itr.first;
          }
          if (numx > 0) {
            tot /= (ll)(itr.second + 1);
            itr.second += numx;
            tot *= (ll)(itr.second + 1);
          }
        }
    //     cout<<"!!!"<<endl;
    //     if (cnt.find(1) != cnt.end()) {
    //   cout<<"fffff2"<<endl;
    // }
        v = calc(tmpx);
        for (int i = 0; i < v.size(); ++i) {
       //   cout<<"i="<<i<<" "<<v[i].first<<endl;
          tot *= (ll)(v[i].second + 1LL);
          cnt[v[i].first] = v[i].second;
        }
    //     cout<<"!!!"<<endl;
    //     if (cnt.find(1) != cnt.end()) {
    //   cout<<"fffff3"<<endl;
    // }
        //cout<<"n="<<n2<<" "<<"cnt="<<cnt2<<endl;
        // for (auto itr : cnt) {
        //   cout<<"xy="<<itr.first<<" "<<itr.second<<endl;
        // }
        if (check(cnt)) {
          puts("YES");
        } else {
          puts("NO");
        }
      } else {
        cnt = cnt2;
        tot = 1LL;
        for (auto itr : cnt) {
          tot *= (ll)(itr.second+1);
        }
      }
    }
  }
  return 0;
}
