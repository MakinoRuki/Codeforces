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
#define N 300005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
ll k, l;
ll d[N];
bool ok[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%lld%lld",&n,&k,&l);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &d[i]);
			ok[i] = false;
			if (d[i] + k <= l) {
				ok[i] = true;
			}
		}
		ok[0] = true;
		ok[n+1] = true;
		vector<int> ids;
		ids.clear();
		ids.push_back(0);
		for (int i = 1; i <= n; ++i) {
			if (ok[i]) ids.push_back(i);
		}
		ids.push_back(n+1);
		bool ok2 = true;
		for (int i = 1; i < ids.size(); ++i) {
			ll h = k;
			bool down = true;
			for (int j = ids[i-1]+1; j < ids[i]; ++j) {
				if (down) h--;
				else h++;
				if (d[j]+h<=l) {
					if (h==0) down = false;
					else if (h==k) down = true;
				} else {
					if (!down) {
						ok2 = false;
						break;
					}
					h = l-d[j];
					if (h < 0 || h > k) {
						ok2 = false;
						break;
					}
					if (h==0) down = false;
					else if (h==k) down = true;
				}
			}
			if (!ok2) break;
		}
		if (!ok2) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
  return 0;
}
