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
#define M 25
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int k1, k2;
		int w,b;
		scanf("%d%d%d", &n, &k1, &k2);
		scanf("%d%d", &w, &b);
		// if (abs(k1-k2)%2) {
		// 	int det=abs(k1-k2);
		// } else {
		// 	int det=abs(k1-k2);
		// 	int n1 = min(k1,k2)+det/2;
		// 	int n2 = min(n-k1,n-k2)+det/2;
		// 	if (n1 < w || n2 < b) {
		// 		puts("NO");
		// 	} else {
		// 		puts("YES");
		// 	}
		// }
		int det=abs(k1-k2);
		int n1 = min(k1,k2)+det/2;
		int n2 = min(n-k1,n-k2)+det/2;
		if (n1 < w || n2 < b) {
			puts("NO");
		} else {
			puts("YES");
		}
	}
  return 0;
}
