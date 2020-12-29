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
#define N 3002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		int tot=0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			tot += a[i];
		}
		int ans=n-1;
		int sum=0;
		for (int i = 1; i < n; ++i) {
			sum += a[i];
			if (tot % sum == 0) {
				int cnt=1;
				int sum2=0;
				bool ok=true;
				for (int j = i+1; j <= n; ++j) {
					if (sum2 + a[j] <= sum) {
						sum2 += a[j];
					} else {
						if (a[j] > sum) {
							ok=false;
							break;
						}
						if (sum2 != sum) {
							ok=false;
							break;
						}
						cnt++;
						sum2 = a[j];
					}
				}
				if (!ok) continue;
				cnt++;
				if (sum2 == sum) {
					ans =min(ans, n-cnt);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
