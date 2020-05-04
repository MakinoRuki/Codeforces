#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
ll n, m, k;
ll p[N];
int main() {
  cin>>n>>m>>k;
  set<ll> ids;
  ids.clear();
  for (int i = 1 ; i <= m; ++i) {
    scanf("%lld", &p[i]);
    ids.insert(p[i]-1);
  }
  int cnt=0;
  int tot=0;
  while(!ids.empty()) {
    ll cur=(*ids.begin()-cnt+k)/k;
    int cnt2=0;
    while(!ids.empty() && ((*ids.begin())-cnt+k)/k==cur) {
      ids.erase(ids.begin());
      cnt2++;
    }
    tot++;
    cnt += cnt2;
  }
  cout<<tot<<endl;
  return 0;
}
