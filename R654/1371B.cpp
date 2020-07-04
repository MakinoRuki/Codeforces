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
#define N 1005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
ll n, r;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>r;
    ll ans;
    if (r < n) {
      ans = r*(r+1)/2;
    } else {
      ans = n*(n-1)/2+1;
    }
    cout<<ans<<endl;
  }
  return 0;
}
