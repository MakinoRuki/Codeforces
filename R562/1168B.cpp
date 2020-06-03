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
#define N 300005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
string s;
int main() {
  cin>>s;
  n = s.size();
  ll ans=0LL;
  int cnt[10];
  for (int i = 1; i <= n; ++i) {
    memset(cnt, 0, sizeof(cnt));
    int j;
    bool found=false;
    for (j = i+1; j <= min(i+8, n); ++j) {
      for (int k = j-1; k >= i; --k) {
        if (s[j-1]==s[k-1]) {
          int det=j-k;
          if (k-det>=i && s[k-1]==s[k-det-1]) {
            found=true;
            break;
          }
        }
      }
      if (found) break;
    }
    if (found) {
      ans += (ll)(n-j+1);
    }
  }
  cout<<ans<<endl;
  return 0;
}
