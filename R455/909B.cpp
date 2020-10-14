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
#define eps 1e-7
#define M 20005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m;
int main() {
	cin>>n;
	int ans=0;
	for (int i = 0; i <= n; ++i) {
		ans=max(ans, (i+1)*(n-i));
	}
	cout<<ans<<endl;
	return 0;
}
