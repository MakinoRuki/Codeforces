#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 1000005
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int a,b;
		scanf("%d%d%d", &n, &a, &b);
		if (a > n/2+1 || b < n/2) {
			puts("-1");
			continue;
		}
		ans[1] = a;
		ans[n] = b;
		set<int> ss;
		ss.clear();
		ss.insert(b);
		ss.insert(a);
		int cur=2;
		for (int i = n; i >= 1; --i) {
			if (ss.find(i) == ss.end()) {
				ans[cur++] = i;
				ss.insert(i);
			}
		}
		bool ok = true;
		for (int i =2; i < n; ++i) {
			if ((i<=n/2 && ans[i] < a) || (i>n/2 && ans[i]>b)) {
				ok = false;
				break;
			}
		}
		if (!ok) puts("-1");
		else {
			for (int i = 1; i <= n; ++i) {
				printf("%d", ans[i]);
				if (i < n) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}

