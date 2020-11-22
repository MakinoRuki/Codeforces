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
#define N 10005
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
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int tot=0;
	int e;
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			tot++;
			e = a[1];
		} else {
			if (i <= e) {
				e = max(e, a[i]);
			} else {
				tot++;
				e = a[i];
			}
		}
	}
	cout<<tot<<endl;
	return 0;
}
