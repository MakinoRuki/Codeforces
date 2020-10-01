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
#include <queue>
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,x;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &x);
		if (n<=2) {
			printf("1\n");
		} else {
			int det=n-2;
			int res=((det+x-1)/x)+1;
			printf("%d\n", res);
		}
	}
	return 0;
}
