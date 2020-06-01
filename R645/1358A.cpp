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
//#include <priority_queue>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll n, m;
int main() {
  cin>>t;
  for (int cas=1;  cas<=t; ++cas) {
    scanf("%lld%lld", &n, &m);
    ll ans= (n*m+1)/2;
    cout<<ans<<endl;
  }
  return 0;
}
