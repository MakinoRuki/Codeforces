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
#define N 105
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int a[N];
int main() {
	cin>>n>>m;
	int maxv = 0;
	int tot=0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		maxv = max(maxv, a[i]);
		tot += a[i];
	}
	int maxk = maxv+m;
	int det=maxv*n-tot;
	int mink = maxv;
	if (m > det) {
		det = m-det;
		mink += (det+n-1)/n;
	}
	cout<<mink<<" "<<maxk<<endl;
	return 0;
}
