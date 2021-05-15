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
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n,k,l;
int a[N];
int main() {
	cin>>n>>k>>l;
	int m = n*k;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+m+1);
	int j;
	for (j = 1; j <= m; ++j) {
		if (a[j]-a[1] > l) break;
	}
	j--;
	if (j < n) {
		puts("0");
		return 0;
	}
	ll tot = 0LL;
	ll det = m-j;
	int cnt = 0;
	for (int i = j; i >= 1; --i) {
		if (cnt == n) break;
		if (det >= k-1) {
			tot += a[i];
			cnt++;
			det -= (k-1);
		} else {
			det++;
		}
	}
	cout<<tot<<endl;
	return 0;
}
