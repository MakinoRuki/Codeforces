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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int ln[N], rn[N];
ll ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      ans[i]=0LL;
      ln[i]=cnt;
      if (s[i] == '>') {
        cnt++;
      }
    }
    cnt=0;
    for (int i = n-1; i >= 0; --i) {
      rn[i] = cnt;
      if (s[i] == '<') {
        cnt++;
      }
    }
    // for (int i = 0; i < n; ++i) {
    //   cout<<"i="<<i<<" "<<ln[i]<<" "<<rn[i]<<endl;
    // }
    vector<ll> sum;
    sum.clear();
    for (int i = 0; i < n; ++i) {
      int sz=(int)sum.size();
      if (sz > 0) {
        int mn = min(ln[i], rn[i]);
        if (ln[i] > rn[i] && s[i]=='<') {
          mn++;
        }
        ans[i] += 2LL*(ll)mn*(ll)i;
        if (sz-mn-1>=0) {
          ans[i] -= 2LL*(sum[sz-1]-sum[sz-mn-1]);
        } else {
          ans[i] -= 2LL*sum[sz-1];
        }
      }
      if (s[i] == '>') {
        if (sum.empty()) {
          sum.push_back(i);
        } else {
          sum.push_back(sum.back()+i);
        }
      }
      //cout<<"i="<<i<<" "<<ans[i]<<endl;
    }
    sum.clear();
    for (int i = n-1; i >= 0; --i) {
      int sz=(int)sum.size();
      if (sz > 0) {
        int mn=min(ln[i], rn[i]);
        if (rn[i]>ln[i] && s[i]=='>') {
          mn++;
        }
        ans[i] -= 2LL*(ll)mn*(ll)i;
        if (sz-mn-1>=0) {
          ans[i] += 2LL*(sum[sz-1]-sum[sz-mn-1]);
        } else {
          ans[i] += 2LL*sum[sz-1];
        }
      }
      if (s[i] == '<') {
        if (sum.empty()) {
          sum.push_back(i);
        } else {
          sum.push_back(sum.back()+i);
        }
      }
      if ((ln[i]==rn[i] && s[i]=='<') || (ln[i]<rn[i])) {
        ans[i]+=i+1;
      } else {
        ans[i]+=n-i;
      }
     // cout<<"i="<<i<<" "<<ans[i]<<endl;
    }
    for (int i = 0; i < n; ++i) {
      printf("%lld ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
