#pragma GCC optimize(2)
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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, l, r, k;
string s;
int cost[3][N][3][3];
int getcost(int id, int x, int y) {
	int z;
	set<int> ss;
	ss.clear();
	ss.insert(x);
	ss.insert(y);
	for (int i = 0; i < 3; ++i) {
		if (ss.find(i) == ss.end()) {
			z = i;
			break;
		}
	}
	int res=0;
	if (id < n && s[id]-'a' != x) {
		res++;
	}
	if (id +1 < n && s[id+1]-'a' != y) {
		res++;
	}
	if (id+2 < n && s[id+2]-'a' != z) {
		res++;
	}
	return res;
}
int main() {
	cin>>n>>m;
	cin>>s;
	memset(cost, 0, sizeof(cost));
	for (int i = n-1; i >= 0; --i) {
		for (int x = 0; x < 3; ++x) {
			for (int y = 0; y < 3; ++y) {
				if (x==y) continue;
				cost[i%3][i][x][y] = getcost(i, x, y);
				if (i + 3 < n) {
					cost[i%3][i][x][y] += cost[i%3][i+3][x][y];
				}
			}
		}
	}
	// cout<<getcost(0,1,0)<<endl;
	// cout<<cost[0][0][1][0]<<" "<<cost[0][3][1][0]<<endl;
	while(m-->0) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		int det=r-l+1;
		int q = det/3;
		int rm = det % 3;
		if (det == 1) {
			puts("0");
		} else {
			int ans = INT_MAX;
			for (int x = 0; x < 3; ++x) {
				for (int y = 0; y < 3; ++y) {
					if (x == y) continue;
					// set<int> ss;
					// ss.clear();
					// ss.insert(x);
					// ss.insert(y);
					// int z;
					// for (z = 0; z < 3; ++z) {
					// 	if (ss.find(z) == ss.end()) {
					// 		break;
					// 	}
					// }
					int res = 0;
					if (det >= 3) {
						res = cost[l%3][l][x][y] - cost[l%3][l+q*3][x][y];
					}
					int l2 = l+q*3;
					if (rm >= 1 && l2 < n && s[l2]-'a' != x) res++;
					if (rm >= 2 && l2+1<n && s[l2+1]-'a' != y) res++;
				//	cout<<x<<" "<<y<<" "<<res<<endl;
					ans = min(ans, res);
				}
			}
			printf("%d\n", ans);
		}
	}
  return 0;
}
