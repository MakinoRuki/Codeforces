#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 200005
using namespace std;
typedef long long ll;
int t, n;
vector<int> aa;
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    cin>>n;
    ll tot=0;
    vector<ll> ans;
    ans.clear();
    aa.clear();
 
    ll z = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin>>a;
      aa.push_back(a);
      tot ^= a;
    }
    if (tot & 1) {
      aa.push_back(1);
      z = 1;
    }
    vector<int> ds1(70, 0);
    vector<int> ds2(70, 0);
    for (int i = 0; i < 33; ++i) {
      int cnt=0;
      for (int j = 0; j < aa.size(); ++j) {
        if ((1LL<<i) & (ll)(aa[j])) {
          cnt++;
        }
      }
      ds2[i] = cnt % 2;
      if (cnt / 2 > 0) {
        cnt /= 2;
        int j = i+1;
        while(cnt) {
          ds1[j] += cnt%2;
          cnt /= 2;
          j++;
        }
      }
    }
    for (int i = 0; i < 64; ++i) {
      int cnt=ds1[i] / 2;
      int j = i+1;
      while(cnt) {
        ds1[j] += cnt%2;
        cnt /= 2;
        j++;
      }
      ds1[i] %= 2;
    }
    ll x = 0;
    ll y = 0;
    for (int i = 0; i < 64; ++i) {
      if (ds1[i] && !ds2[i]) {
        z |= 1LL<<i;
      } else if (!ds1[i] && ds2[i]) {
        x |= 1LL<<(i-1);
        y |= 1LL<<(i-1);
      }
    }
    if (x) ans.push_back(x);
    if (y) ans.push_back(y);
    if (z) ans.push_back(z);
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); ++i) {
      cout<<ans[i];
      if (i < ans.size()-1) cout<<" ";
    }
    cout<<endl;
  }
  return 0;
}
