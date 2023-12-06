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
#define N 500005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n,p,l,r;
    scanf("%lld%lld%lld%lld",&n, &p,&l,&r);
    ll lb = 0, rb = n;
    while(lb < rb) {
    	ll mid = (lb+rb+1)/2;
    	ll tot = (n-mid)*l;
    	ll dt = ((n-1)/7+1);

    	tot += min(2LL*(n-mid), dt) * r;
    	if (tot >= p) {
    		lb = mid;
    	} else {
    		rb = mid-1;
    	}
    }
    printf("%lld\n", rb);
  }
  return 0;
}
