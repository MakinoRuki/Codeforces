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
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
  	scanf("%d", &n);
  	for (int i = 1; i <= n; ++i) {
  		scanf("%lld", &a[i]);
  	}
  	sort(a+1, a+n+1);
  	if (n == 1) {
  		puts("0");
  		continue;
  	}
  	ll mn = a[1];
  	ll mx = a[n];
  	vector<int> ans;
  	ans.clear();
  	while(mn != mx) {
  		ll r = mn%2;
  		ans.push_back(r);
  		mn = (mn+r)/2;
  		mx = (mx+r)/2;
  	}
  	int sz = (int)ans.size();
  	printf("%d\n", sz);
  	if (sz <= n) {
  		for (int i = 0; i < ans.size(); ++i) {
  			printf("%d ", ans[i]);
  		}
  		cout<<endl;
  	}
  }
  return 0;
}
