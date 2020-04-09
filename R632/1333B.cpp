#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m;
int t;
int a[N], b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
		}
		bool ok = true;
		bool pz = false, z = false, ng = false;
		for (int i = 1; i <= n; ++i) {
			int det = b[i]-a[i];
			if (det > 0 && !pz) {
				ok = false;
				break;
			} else if (det < 0 && !ng) {
				ok = false;
				break;
			}
			if (a[i] > 0) pz = true;
			if (a[i] < 0) ng = true;
			if (a[i] == 0) z = true;
		}
		if (!ok) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
