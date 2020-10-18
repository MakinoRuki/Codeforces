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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m,k;
bool a[N];
int main() {
	cin>>n>>m>>k;
	memset(a, false, sizeof(a));
	for (int i = 1; i <= n; ++i) {
		int ai;
		scanf("%d", &ai);
		a[ai]=true;
	}
	int ans=0;
	deque<int> dq;
//	cout<<dq.size()<<endl;
	for (int i = 1; i <= 1000001; ++i) {
		if (a[i]) {
			dq.push_back(i);
		}
		while(!dq.empty() && i-dq.front()>=m) {
			dq.pop_front();
		}
		if (i>=m) {
			int det=dq.size()-(k-1);
			if (det>0) {
				for (int j =1 ; j <= det; ++j) {
					dq.pop_back();
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
