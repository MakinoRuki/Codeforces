#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define N 102
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, x;
int w[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &x);
		int tot=0;
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &w[i]);
			tot += w[i];
			rk.push_back(make_pair(w[i], i));
		}
		sort(rk.begin(), rk.end());
		if (tot == x) {
			puts("NO");
		} else {
			vector<int> ans;
			ans.clear();
			int sum=0;
			for (int i = 0; i < rk.size(); ++i) {
				sum += rk[i].first;
				if (sum == x) {
					ans.push_back(rk[i+1].first);
					ans.push_back(rk[i].first);
					sum += rk[i+1].first;
					i++;
				} else {
					ans.push_back(rk[i].first);
				}
			}
			puts("YES");
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d", ans[i]);
				if (i < ans.size()-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
