#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
int t, n, m;
int a[N], p[N];
int b[N];
int l[N], r[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m;
		unordered_set<int> ps;
		ps.clear();
		for (int i = 1; i <= n; ++i) {
			cin>>a[i];
			b[i] = a[i];
		}
		for (int j = 1; j <= m; ++j) {
			cin>>p[j];
			ps.insert(p[j]);
		}
		sort(b+1, b+1+n);
		for (int i = 1; i <= n; ++i) {
			if (i == 1 || b[i] != b[i-1]) {
				l[b[i]] = i;
				r[b[i]] = i;
			} else {
				r[b[i]] = i;
			}
		}
		// for (int i = 1; i <= n; ++i) {
		// 	cout<<i<<" "<<a[i]<<" "<<l[a[i]]<<" "<<r[a[i]]<<endl;
		// }
		int i, j;
		for (i = 1; i <= n; ++i) {
			if (a[i] != b[i]) {
				if (r[a[i]] < i) {
					for (j = r[a[i]]; j < i; ++j) {
						if (ps.find(j) == ps.end()) {
							break;
						}
					}
					if (j >= i) continue;
					break;
				} else if (l[a[i]] > i) {
					for (j = i; j < l[a[i]]; ++j) {
						if (ps.find(j) == ps.end()) {
							break;
						}
					}
					if (j >= l[a[i]]) continue;
					break;
				}
			}
		}
		if (i <= n) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
