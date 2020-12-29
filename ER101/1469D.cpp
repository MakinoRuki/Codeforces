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
int t, n;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<ll,ll>> ps;
    ps.clear();
    if (n == 3) {
      cout<<2<<endl;
      cout<<3<<" "<<2<<endl;
      cout<<3<<" "<<2<<endl;
      continue;
    }
    if (n == 4) {
      cout<<3<<endl;
      cout<<3<<" "<<4<<endl;
      cout<<4<<" "<<2<<endl;
      cout<<4<<" "<<2<<endl;
      continue;
    }
    vector<pair<int,int>> ans;
    ans.clear();
    int pw=0;
    while((1<<pw) <= n) {
      pw++;
    }
    pw--;
    for (int i = (1<<pw)+1; i < n; ++i) {
      ans.push_back(make_pair(i, n));
    }
    if (n > (1<<pw)) {
      ans.push_back(make_pair(n, (1<<pw)));
      ans.push_back(make_pair(n, 2));
    }
    n = (1<<pw);
    int tn = n;
    while(n > 2) {
      int pw2 = pw/2;
      int m = n/(1<<pw2);
      for (int i = m+1; i <= min(n, tn-1); ++i) {
        ans.push_back(make_pair(i, tn));
      }
      ans.push_back(make_pair(tn, (1<<pw2)));
      n = m;
      pw = (pw+1)/2;
    }
    ans.push_back(make_pair(tn, 2));
    // for (ll i = 2; i*i <= m; ++i) {
    //   if (m%i==0) {
    //     ll res=1;
    //     while(m%i==0) {
    //       res*=i;
    //       m/=i;
    //     }
    //     ps.push_back(make_pair(i, res));
    //   }
    // }
    // if (m>1) ps.push_back(make_pair(m, m));
    // vector<pair<int,int>> ans;
    // ans.clear();
    // if (ps.size() == 1 && ps[0].first == n) {
    //   ans.push_back(make_pair(n, n-1));
    //   ans.push_back(make_pair(n, 2));
    //   ps.clear();
    //   n--;
    //   m = n;
    //   for (ll i = 2; i*i <= m; ++i) {
    //     if (m%i==0) {
    //       ll res=1;
    //       while(m%i==0) {
    //         res*=i;
    //         m/=i;
    //       }
    //       ps.push_back(make_pair(i,res));
    //     }
    //   }
    //   if (m>1) ps.push_back(make_pair(m,m));
    // }
    // sort(ps.begin(), ps.end());
    // if (ps.size() == 1) {
    //   ll p = ps[0].first;
    //   ps.clear();
    //   ps.push_back(make_pair(p, p));
    //   ps.push_back(make_pair(p, n/p));
    // }
    // m = n;
    // for (int i = 0; i < ps.size(); ++i) {
    //   ll cur=m/ps[i].second;
    //   for (int j = max(3LL, cur); j < m; ++j) {
    //     ans.push_back(make_pair(j, n));
    //   }
    //   ans.push_back(make_pair(n, ps[i].second));
    //   m /= ps[i].second;
    // }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
