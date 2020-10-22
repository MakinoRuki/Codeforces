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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,a,b;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &a, &b);
		int res=0;
		for (int i = 30; i >= 0; --i) {
			if (((1<<i)&a)!=((1<<i)&b)) {
				res += (1<<i);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
