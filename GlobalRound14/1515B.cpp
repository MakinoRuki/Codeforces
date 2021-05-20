#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#define N 102
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, x;
int w[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		if (n == 1) {
			puts("NO");
			continue;
		}
		int pw=0;
		while(n%2==0) {
			n/=2;
			pw++;
		}
		int sq = (int)sqrt(n);
		if (pw >= 1 && sq*sq == n) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
