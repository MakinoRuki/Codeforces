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
#include <time.h>
#define N 200
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t,n;
int p[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n/2; ++i) {
		scanf("%d", &p[i]);
	}
	sort(p+1, p+n/2+1);
	int ans = inf;
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n/2; ++i) {
		s1 += abs(p[i]-(2*i-1));
		s2 += abs(p[i]-2*i);
	}
	ans = min(ans, min(s1, s2));
	cout<<ans<<endl;
	return 0;
}
