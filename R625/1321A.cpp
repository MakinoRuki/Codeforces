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
#define N 102
#define M 40005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int n;
int r[N], b[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>r[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin>>b[i];
	}
	int ans=0;
	while(true) {
		ans++;
		if (ans > 500) break;
		ll tot1=0;
		ll tot2=0;
		for (int i = 1; i <= n; ++i) {
			if (r[i] && !b[i]) tot1 += ans;
			else if (!r[i] && b[i]) tot2++;
		}
		if (tot1 > tot2) {
			break;
		}
	}
	cout<<(ans > 500 ? -1 : ans)<<endl;
	return 0;
}
