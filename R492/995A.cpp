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
#define N 100
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, k;
int park[5][N];
int main() {
	cin>>n>>k;
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &park[i][j]);
		}
	}
	vector<pair<int,pair<int,int>>> ans;
	ans.clear();
	int cnt=0;
	while(true) {
		for (int i = 1; i <= n; ++i) {
			if (park[2][i]==park[1][i] && park[1][i]>0) {
				cnt++;
				park[2][i]=0;
				ans.push_back(make_pair(park[1][i], make_pair(1,i)));
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (park[3][i]==park[4][i] && park[4][i]>0) {
				cnt++;
				park[3][i]=0;
				ans.push_back(make_pair(park[4][i], make_pair(4,i)));
			}
		}
		bool found=false;
		// int idx=0,idy=0;
		for (int i = 1; i <= n; ++i) {
			if (park[2][i]) {
				if (i==n) {
					if (park[3][i]==0) {
						ans.push_back(make_pair(park[2][i], make_pair(3,i)));
						park[3][i]=park[2][i];
						park[2][i]=0;
						found=true;
						break;
					}
				} else {
					if (park[2][i+1]==0) {
						ans.push_back(make_pair(park[2][i], make_pair(2,i+1)));
						park[2][i+1]=park[2][i];
						park[2][i]=0;
						found=true;
						break;
					}
				}
			}
			if (park[3][i]) {
				if (i==1) {
					if (park[2][i]==0) {
						ans.push_back(make_pair(park[3][i], make_pair(2,i)));
						park[2][i]=park[3][i];
						park[3][i]=0;
						found=true;
						break;
					}
				} else {
					if (park[3][i-1]==0) {
						ans.push_back(make_pair(park[3][i], make_pair(3,i-1)));
						park[3][i-1]=park[3][i];
						park[3][i]=0;
						found=true;
						break;
					}
				}
			}
		}
		if (!found) break;
	}
	if (cnt<k) {
		cout<<-1<<endl;
	} else {
		cout<<ans.size()<<endl;
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
		}
	}
	return 0;
}
