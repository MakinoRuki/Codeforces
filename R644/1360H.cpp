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
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
vector<ll> ns;
int main() {
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    ns.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      ll res=0LL;
      for (int j = 0; j < m; ++j) {
        res = res*2LL+s[j]-'0';
      }
      ns.push_back(res);
    }
    ll k = (1LL<<m)-n;
    sort(ns.begin(), ns.end());
    string anss="";
    for (int i = 0; i < ns.size(); ++i) {
      if (ns[i]-i >= (k+1)/2) {
        ll ans=0LL;
        for (int j = 0; j < m; ++j) {
          ll tmp=ans*2LL;
          int det=m-1-j;
          if ((tmp<<det)+(1LL<<det)-i >= (k+1)/2) {
            ans = tmp;
          } else {
            ans = tmp+1;
          }
        }
        for (int j = 0; j < m; ++j) {
          if ((1LL<<(m-1-j))&ans) {
            anss.push_back('1');
          } else {
            anss.push_back('0');
          }
        }
        break;
      }
    }
    if (anss.empty()) {
      ll ans=0LL;
      for (int j = 0; j < m; ++j) {
        ll tmp=ans*2LL;
        int det=m-1-j;
        if ((tmp<<det)+(1LL<<det)-n >= (k+1)/2) {
          ans = tmp;
        } else {
          ans = tmp+1;
        }
      }
      for (int j = 0; j < m; ++j) {
        if ((1LL<<(m-1-j))&ans) {
          anss.push_back('1');
        } else {
          anss.push_back('0');
        }
      }
    }
    cout<<anss<<endl;
  }
  return 0;
}
