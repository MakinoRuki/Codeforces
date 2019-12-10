#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <unordered_set>
#define N 200020
using namespace std;
typedef long long ll;
int n,m;
int a[N];
vector<ll> sum;
vector<ll> ans;
int main() {
	cin>>n>>m;
	sum.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n; ++i) {
		sum[i] = (i-m>=0 ? sum[i-m]+a[i] : a[i]);
	}
	int cnt=0;
	ll p = 1;
	for (int i = n-1; i>=0; --i) {
		cnt++;
		ans[n-1]+=a[i]*p;
		if (cnt == m) {
			p++;
			cnt=0;
		}
	}
	for (int i=n-2; i >= 0; --i) {
		ans[i] = ans[i+1] - sum[i+1];
	}
	for (int i = 0; i < n; ++i) {
		cout<<ans[i];
		if (i < n-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
