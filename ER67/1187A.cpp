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
#define M 20005
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int T;
int n,s,t;
int main() {
	cin>>T;
	for (int cas=1; cas<= T; ++cas) {
		scanf("%d%d%d", &n, &s, &t);
		int sn=s;
		int tn=t;
		int cn=s+t-n;
		sn -= cn;
		tn -= cn;
		int res=max(sn, tn)+1;
		printf("%d\n", res);
	}
	return 0;
}
