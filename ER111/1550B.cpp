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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int a,b;
		scanf("%d%d%d", &n, &a, &b);
		cin>>s;
		int cnt=0;
		for (int i = 0; i < n; ++i) {
			if (i == 0 || s[i] != s[i-1]) {
				cnt++;
			}
		}
		int res = a*n;
		if (b > 0) {
			res += b*n;
		} else {
			res += b*(cnt/2+1);
		}
		printf("%d\n", res);
	}
  return 0;
}
