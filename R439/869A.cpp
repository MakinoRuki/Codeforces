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
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,k;
int x[N], y[N];
int main() {
	cin>>n;
	unordered_set<int> ss;
	ss.clear();
	for (int i = 1;i <= n; ++i) {
		scanf("%d", &x[i]);
		ss.insert(x[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &y[i]);
		ss.insert(y[i]);
	}
	int tot=0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int cur=x[i]^y[j];
			if (ss.find(cur) != ss.end()) {
				tot++;
			}
		}
	}
	if (tot%2==0) {
		cout<<"Karen"<<endl;
	} else {
		cout<<"Koyomi"<<endl;
	}
	return 0;
}
