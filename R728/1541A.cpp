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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			a[i] = i;
		}
		for (int i = 1; i <= n/2; ++i) {
			swap(a[2*i-1], a[2*i]);
		}
		if (n%2) {
			swap(a[n-1], a[n]);
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", a[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
