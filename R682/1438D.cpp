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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
int main() {
	cin>>n;
	for (int i = 1; i <=n ;++i) {
		scanf("%d", &a[i]);
	}
	if (n%2) {
		cout<<"YES"<<endl;
		int tot=n/2*2-1;
		cout<<tot<<endl;
		for (int i = 1; i <= n; i += 2) {
			if (i+2<=n) {
				printf("%d %d %d\n", i, i+1, i+2);
			}
		}
		for (int i = n-4; i >= 1; i -= 2) {
			printf("%d %d %d\n", i, i+1, i+2);
		}
	} else {
		int sum=0;
		for (int i = 1; i <= n; ++i) {
			sum ^= a[i];
		}
		if (sum!=0) {
			cout<<"NO"<<endl;
			return 0;
		} else {
			cout<<"YES"<<endl;
		}
		int m = n-1;
		int tot=m/2*2-1;
		cout<<tot<<endl;
		for (int i = 1; i < n; i += 2) {
			if (i+2<n) {
				printf("%d %d %d\n", i, i+1, i+2);
			}
		}
		for (int i = n-5; i >= 1; i -= 2) {
			printf("%d %d %d\n", i, i+1, i+2);
		}
	}
	return 0;
}
