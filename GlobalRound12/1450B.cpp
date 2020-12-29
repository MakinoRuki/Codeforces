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
#define M 31
#define N 100002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
vector<pair<int,int>> bs;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		bs.clear();
		for (int i = 1; i <= n; ++i) {
			int x,y;
			scanf("%d%d",&x, &y);
			bs.push_back(make_pair(x, y));
		}
		bool found=false;
		for (int i = 0; i < n; ++i) {
			int j;
			for (j = 0; j < n; ++j) {
				if (abs(bs[i].first-bs[j].first)+abs(bs[i].second-bs[j].second) > k) {
					break;
				}
			}
			if (j >= n) {
				found=true;
				break;
			}
		}
		if (found) cout<<1<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
