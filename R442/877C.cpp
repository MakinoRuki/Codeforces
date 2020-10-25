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
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int main() {
	cin>>n;
	cout<<n+n/2<<endl;
	int cnt=0;
	for (int i = 2; i <= n; i += 2) {
		printf("%d", i);
		cnt++;
		if (cnt==n+n/2) cout<<endl;
		else cout<<" ";
	}
	for (int i = 1; i <= n; i += 2) {
		printf("%d", i);
		cnt++;
		if (cnt==n+n/2) cout<<endl;
		else cout<<" ";
	}
	for (int i = 2; i <= n; i += 2) {
		printf("%d", i);
		cnt++;
		if (cnt==n+n/2) cout<<endl;
		else cout<<" ";
	}
	return 0;
}
