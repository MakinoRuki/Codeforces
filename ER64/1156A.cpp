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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
int main() {
	bool ok = true;
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int tot=0;
	for (int i = 2; i <= n; ++i) {
		if ((a[i]==2 && a[i-1]==3) || (a[i]==3 && a[i-1]==2)) {
			ok=false;
		} else {
			if ((a[i]==1 && a[i-1]==3) || (a[i]==3 && a[i-1]==1)) {
				tot += 4;
			} else if ((a[i-1]==1 && a[i]==2) || (a[i-1]==2 && a[i]==1)) {
				tot += 3;
			}
			if (a[i]==2 && a[i-1]==1 && (i-2>=1 && a[i-2]==3)) {
				tot--;
			}
		}
	}
	if (ok) {
		cout<<"Finite"<<endl;
		cout<<tot<<endl;
	} else {
		cout<<"Infinite"<<endl;
	}
	return 0;
}
