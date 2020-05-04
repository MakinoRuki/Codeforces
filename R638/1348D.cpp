#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#define N 105
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    ll a = 1;
    ll det = n-1;
    vector<ll> ans;
    ans.clear();
    while(det) {
      if (a > det) {
        break;
      }
      ll x = min(max(0LL, det/2-a), a);
      if (x > 0) {
        ans.push_back(x);
        a += x;
        det -= a;
      } else {
        if (det > a && det <= 2*a) {
          ans.push_back(det-a);
          a += det-a;
          det -= a;
        } else {
          ans.push_back(0);
          det -= a;
        }
      }
    }
    if (det) cout<<-1<<endl;
    else {
      cout<<ans.size()<<endl;
      for (int i = 0; i < ans.size(); ++i) {
        printf("%lld", ans[i]);
        if (i < ans.size()-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
