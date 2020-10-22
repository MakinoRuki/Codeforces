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
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 20005
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		vector<int> ids;
		ids.clear();
		int maxv=a[1];
		for (int i = 1; i <= n; ++i) {
			if (a[i]>maxv) {
				ids.clear();
				ids.push_back(i);
				maxv=a[i];
			} else if (a[i]==maxv) {
				ids.push_back(i);
			}
		}
		int ans=-1;
		for (int i = 0; i < ids.size(); ++i) {
			int id=ids[i];
			if (id-1>=1 && a[id]>a[id-1]) {
				ans=id;
				break;
			}
			if (id+1<=n && a[id]>a[id+1]) {
				ans=id;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
