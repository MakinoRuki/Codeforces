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
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, x;
int a[N];
int b[N];
int main() {
	cin>>n;
	vector<int> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		rk.push_back(a[i]);
	}
	sort(rk.begin(), rk.end());
	if (n<=2) {
		cout<<0<<endl;
		for (int i = 1; i <= n; ++i) {
			printf("%d", a[i]);
			if (i<n) cout<<" ";
			else cout<<endl;
		}
		return 0;
	}
	if (n%2) {
		cout<<n/2<<endl;
		int j = 0;
		for (int i = 2; i <= n; i += 2) {
			b[i] = rk[j];
			j++;
		}
		for (int i = 1; i <= n; i += 2) {
			b[i] = rk[j];
			j++;
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", b[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	} else {
		cout<<(n-1)/2<<endl;
		int j = 0;
		memset(b, -1, sizeof(b));
		for (int i = 2; i <= n; i+=2) {
			if (j>=(n-1)/2) break;
			b[i]=rk[j];
			j++;
		}
		for (int i = 1; i <= n; ++i) {
			if (b[i]<0) {
				b[i]=rk[j];
				j++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", b[i]);
			if (i<n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
