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
#define N 300
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N];
int pos[N];
int main() {
	cin>>n;
	for (int i = 1; i <= 2*n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(pos, 0, sizeof(pos));
	int ans=0;
	for (int i = 1; i <= 2*n; ++i) {
		int j;
		for (j=i-1; j >= 1; --j) {
			if (a[j]==a[i]) {
				break;
			}
		}
		if (j<1) continue;
		for (int j2=i-1; j2>=j+1; --j2) {
			ans++;
			swap(a[j2], a[j2+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
