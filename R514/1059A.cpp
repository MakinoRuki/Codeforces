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
#define N 300005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int L, a;
int main() {
	cin>>n>>L>>a;
	int pre=0;
	int res=0;
	for (int i = 1; i <= n; ++i) {
		int t, l;
		scanf("%d%d", &t, &l);
		int det=t-pre;
		res += det/a;
		pre = t+l;
	}
	int det=L-pre;
	res += det/a;
	cout<<res<<endl;
	return 0;
}
