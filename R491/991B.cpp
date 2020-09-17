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
#define N 105
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[N];
int main() {
	cin>>n;
	int tot=0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		tot += a[i];
	}
	sort(a+1, a+n+1);
	if (2*tot >= 9*n) {
		cout<<0<<endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] < 5) {
			tot += 5-a[i];
			if (2*tot >= 9*n) {
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
