#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int t, n, m;
int main() {
	cin>>n;
	int tot=0;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		tot += a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	ll s1=0,s2=0;
	for (int i = 0; i < n/2; ++i) {
		s1 += a[i];
	}
	for (int i = 0; i < (n+1)/2; ++i) {
		s2 += a[i];
	}
	ll ans = max(s1*s1+(tot-s1)*(tot-s1), s2*s2+(tot-s2)*(tot-s2));
	cout<<ans<<endl;
	return 0;
}
