#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 200
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t, n, m;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		bool ok=false;
		for (int i = 1; i <= n; ++i) {
			int x = a[i];
			for (int j = 2; j * j <= x; ++j) {
				if (x % j == 0) {
					int cnt=0;
					while(x%j==0) {
						x/=j;
						cnt++;
					}
					if (cnt%2) {
						ok=true;
						break;
					}
				}
			}
			if (x>1) ok=true;
			if (ok) break;
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}

/*myturn.ca.gov*/
