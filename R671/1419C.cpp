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
#define N 1005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, x;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int cnt=0;
		int det=0;
		for (int i = 1; i <= n; ++i) {
			if (a[i]==x) {
				cnt++;
			}
			det += a[i]-x;
		}
		if (cnt==n) {
			cout<<0<<endl;
		} else {
			if (cnt>0) {
				cout<<1<<endl;
			} else {
				if (det==0) {
					cout<<1<<endl;
				} else {
					cout<<2<<endl;
				}
			}
		}
	}
	return 0;
}
