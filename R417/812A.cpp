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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, x;
int ls[4][4];
int main() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &ls[i][j]);
		}
	}
	bool ok=false;
	for (int i = 0; i < 4; ++i) {
		int i3 = (i+3)%4;
		int i2 = (i+2)%4;
		int i1 = (i+1)%4;
		if (ls[i][0]) {
			if (ls[i3][3] || ls[i][3]) {
				ok=true;
			}
		}
		if (ls[i][1]) {
			if (ls[i2][3] || ls[i][3]) {
				ok=true;
			}
		}
		if (ls[i][2]) {
			if (ls[i][3] || ls[i1][3]) {
				ok=true;
			}
		}
	}
	if (ok) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
