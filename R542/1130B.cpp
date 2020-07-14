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
#define N 200005
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
vector<int> a[N];
int main() {
	cin>>n;
	for (int i = 1; i <= 2*n; ++i) {
		int x;
		scanf("%d", &x);
		a[x].push_back(i);
	}
	ll ans=0;
	for (int i = 1; i <= n; ++i) {
		ll p1 = 1;
		ll p2 = 1;
		if (i > 1) {
			p1 = a[i-1][0];
			p2 = a[i-1][1];
		}
		ll q1 = a[i][0];
		ll q2 = a[i][1];
		ans += min(abs(p1-q1)+abs(p2-q2), abs(p1-q2)+abs(p2-q1));
	}
	cout<<ans<<endl;
  return 0;
}
