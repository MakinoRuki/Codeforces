#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok = true;
    set<ll> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      ll res = (a[i]+i+1000000000LL * n) % n;
      if (ss.find(res) != ss.end()) {
        ok = false;
        break;
      }
      ss.insert(res);
    }
    if (!ok) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
  return 0;
}
