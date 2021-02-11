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
#define M 21
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, x2;
bool pr[N];
int main() {
	memset(pr, false, sizeof(pr));
	for (int i = 2; i*i <= 1000000; ++i) {
		if (!pr[i]) {
			for (int j = i*i; j <= 1000000; j += i) {
				pr[j] = true;
			}
		}
	}
	vector<int> ps2;
	ps2.clear();
	for (int i = 2; i <= 1000000; ++i) {
		if (!pr[i]) {
			ps2.push_back(i);
		}
	}
	cin>>x2;
	vector<int> ps;
	ps.clear();
	for (int i = 2; i <= x2; ++i) {
		if (!pr[i] && (x2%i == 0)) {
			ps.push_back(i);
		}
	}
	int x0 = -1;
	for (int p : ps) {
		for (int p2 : ps2) {
			int c2 = x2/p;
			int c1 = c2-1;
			int c3 = (c1*p)/p2 + 1;
			if (c3 * p2 <= x2) {
				if (c3 > 1) {
					x0 = (x0 < 0 ? (c3-1)*p2+1 : min(x0, (c3-1)*p2+1));
				}
			}
		}
	}
	cout<<x0<<endl;
  return 0;
}
