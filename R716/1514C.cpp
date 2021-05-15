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
#define N 200
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t, n, k;
ll getgcd(ll x, ll y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>n;
	// n--;
	// int len=0,st=0;
	// for (int i = 0; i < (1<<n); ++i) {
	// 	int res= 1;
	// 	int len2=0;
	// 	for (int j = 0; j < n; ++j) {
	// 		if ((1<<j) & i) {
	// 			res = res * (j+1) % (n+1);
	// 			len2++;
	// 		}
	// 	}
	// 	if (res == 1) {
	// 		if (len2>len) {
	// 			len = len2;
	// 			st = i;
	// 		}
	// 	}
	// }
	// for (int j = 0; j < n; ++j) {
	// 	if ((1<<j) & st) {
	// 		printf("%d ", j+1);
	// 	}
	// }
	// cout<<endl;
	ll res = 1LL;
	vector<int> nums;
	nums.clear();
	for (int i = 1; i < n-1; ++i) {
		if (getgcd(i, n) == 1) {
			nums.push_back(i);
			res = res*(ll)i % n;
		}
	}
	if (res * (ll)(n-1) % n == 1) {
		nums.push_back(n-1);
	}
	printf("%d\n", (int)nums.size());
	for (int i = 0; i < nums.size(); ++i) {
		printf("%d", nums[i]);
		if (i < nums.size()-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}

/*myturn.ca.gov*/
