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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cout<<2<<endl;
		if (n==2) {
			cout<<1<<" "<<2<<endl;
		} else {
			cout<<n<<" "<<n-2<<endl;
			cout<<n-1<<" "<<n-1<<endl;
			for (int i = n-1; i >= 3; --i) {
				printf("%d %d\n", i, i-2);
			}
		}
	}
	return 0;
}
