// (ai+aj)*(ai^2+aj^2)=k(% p) <==> (ai-aj)*(ai+aj)*(ai^2+aj^2)=k(ai-aj)(% p) <==> (ai^4-aj^4)=k(ai-aj)(% p)
// <==> (ai^4-k*ai)=(aj^4-k*aj)(% p)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define N 300005
using namespace std;
typedef long long ll;
int n, k;
ll p;
ll a[N];
int main() {
  cin>>n>>p>>k;
  unordered_map<ll, ll> prs;
  prs.clear();
  for (int i = 0; i < n; ++i) {
    cin>>a[i];
    ll num = a[i] * a[i] % p;
    num = num * a[i] % p;
    num = num * a[i] % p;
    num = (num - k * a[i] % p + p) % p;
    prs[num]++;
  }
  ll ans = 0LL;
  for (auto pr : prs) {
    ll num = pr.second;
    ans += num * (num-1) / 2;
  }
  cout<<ans<<endl;
  return 0;
}
