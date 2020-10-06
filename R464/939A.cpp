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
#include <cmath>
#define N 5005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int f[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &f[i]);
	}
	bool ok=false;
	for (int i = 1; i <= n; ++i) {
		vector<int> tmp;
		tmp.clear();
		tmp.push_back(i);
		tmp.push_back(f[i]);
		tmp.push_back(f[f[i]]);
		tmp.push_back(f[f[f[i]]]);
		if (tmp[0]!=tmp[1] && tmp[1]!=tmp[2] && tmp[0]!=tmp[2] && tmp[0]==tmp[3]) {
			ok=true;
			break;
		}
	}
	if (ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
