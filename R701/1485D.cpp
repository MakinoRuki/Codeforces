#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[N][N];
ll getgcd(ll x, ll y) {
	return y==0?x:getgcd(y, x%y);
}
int main() {
	ll x = 1;
	for (int i =2 ; i <= 16; ++i) {
		x = x*i/getgcd(x,i);
	}
	cin>>n>>m;
	for (int i =1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			if ((i+j)%2==0) {
				printf("%lld", x+a[i][j]*a[i][j]*a[i][j]*a[i][j]);
			} else {
				printf("%lld", x);
			}
			if (j < m) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
