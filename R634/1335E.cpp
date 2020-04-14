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
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int t, n;
int a[N];
int cnt[202];
vector<int> ids[202];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= 200; ++i) {
			ids[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			ids[a[i]].push_back(i);
		}
		int ans=1;
		for (int i = 1; i <= 200; ++i) {
			int sz= ids[i].size();
			ans = max(ans, sz);
			if (ids[i].size() >= 2) {
				memset(cnt, 0, sizeof(cnt));
				int mid = sz/2-1;
				int l = mid;
				int r = ((sz % 2) ? l+2 : l+1);
			//	cout<<l<<" "<<r<<endl;
				int maxv = 0;
				for (int j = ids[i][l]+1; j < ids[i][r]; ++j) {
					if (a[j] == i) continue;
					cnt[a[j]]++;
					maxv = max(maxv, cnt[a[j]]);
				}
				//cout<<maxv<<endl;
				while(l >= 0) {
					ans = max(ans, maxv + (l+1)*2);
					if (l > 0) {
						for (int j = ids[i][l]; j > ids[i][l-1]; --j) {
							if (a[j] == i) continue;
							cnt[a[j]]++;
							maxv = max(maxv, cnt[a[j]]);
						}
						for (int j = ids[i][r]; j < ids[i][r+1]; ++j) {
							if (a[j] == i) continue;
							cnt[a[j]]++;
							maxv = max(maxv, cnt[a[j]]);
						}
						l--;
						r++;
					} else {
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
