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
#define N 60
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int c[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	vector<vector<int>> ans;
	ans.clear();
	while(true) {
		int i;
		bool found=false;
		for (i=n; i > 1; --i) {
			int j1;
			for (j1 = 1; j1 <= n; ++j1) {
				if (c[j1]==i) {
					break;
				}
			}
			int j2;
			for (j2=1; j2<=n; ++j2) {
				if (c[j2]==i-1) {
					break;
				}
			}
		//	cout<<i<<" "<<j1<<" "<<j2<<endl;
			if (j2>j1) {
				found=true;
				vector<int> tmp;
				tmp.clear();
				int c2[N];
				int j3=j1;
				while(true) {
					if (c[j3+1]==c[j3]+1) {
						j3++;
					} else {
						break;
					}
				}
				if (j1>1) tmp.push_back(j1-1);
				tmp.push_back(j3-j1+1);
				tmp.push_back(j2-j3);
				if (j2<n) tmp.push_back(n-j2);
				int id=1;
				for (int j5=j2+1;j5<=n; ++j5) {
					c2[id++]=c[j5];
				}
				for (int j5=j3+1; j5<=j2; ++j5) {
					c2[id++]=c[j5];
				}
				for (int j5=j1; j5<=j3;++j5) {
					c2[id++]=c[j5];
				}
				for (int j5=1; j5<j1; ++j5) {
					c2[id++]=c[j5];
				}
				for (int j5=1; j5<=n; ++j5) {
					c[j5]=c2[j5];
				}
				ans.push_back(tmp);
				break;
			}
		}
		if (!found) break;
	}
	cout<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d", (int)ans[i].size());
		for (int j = 0; j < ans[i].size(); ++j) {
			printf(" %d", ans[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
