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
#include <queue>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
int n;
int main() {
	cin>>n;
	int tot=0;
	for (int a=1; a<=n; ++a) {
		for (int b=a; b<=n; ++b) {
			int c=a^b;
			if (c>=a && c>=b && c<=n && a+b>c) {
				tot++;
			}
		}
	}
	cout<<tot<<endl;
	return 0;
}
