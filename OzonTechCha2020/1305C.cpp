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
#define N 1002
using namespace std;
typedef long long ll;
int n, m;
ll cnt1[N];
int a[200005];
int main() {
	cin>>n>>m;
	memset(cnt1, 0, sizeof(cnt1));
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	if (n > m) {
		cout<<0<<endl;
	} else {
		sort(a, a+n);
		ll res=1LL;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				ll tmp = (a[i]-a[j])%m;
				res = res*tmp%m;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
