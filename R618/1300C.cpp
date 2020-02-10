#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int t;
ll a[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	int res=-1;
	for (int i = 32; i >= 0; --i) {
		int cnt=0;
		int idx=-1;
		for (int j = 1; j <= n; ++j) {
			if ((1LL<<i) & a[j]) {
				cnt++;
				idx = j;
			}
		}
		if (cnt == 1) {
			res = idx;
			break;
		}
	}
	if (res >= 0) {
		cout<<a[res];
		for (int i = 1; i <= n; ++i) {
			if (i == res) continue;
			cout<<" "<<a[i];
		}
		cout<<endl;
	} else {
		for (int i = 1; i <= n; ++i) {
			cout<<a[i];
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
