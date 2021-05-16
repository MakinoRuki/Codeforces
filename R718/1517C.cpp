#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 502
#define M 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t, n, m;
int p[N];
int ans[N][N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; ++i) {
		int cx = i, cy = i;
		int cnt=0;
		while(true) {
			cnt++;
			ans[cx][cy] = p[i];
			if (cnt == p[i]) break;
			if (cy -1 >= 1 && !ans[cx][cy-1]) {
				cy--;
			} else {
				cx++;
			}
		}
		//cout<<"i="<<i<<endl;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d", ans[i][j]);
			if (j < i) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}

/*myturn.ca.gov*/
