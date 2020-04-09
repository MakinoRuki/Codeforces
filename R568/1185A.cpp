#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 3005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int a, b, c, d;
int main() {
	cin>>a>>b>>c>>d;
	vector<int> rk;
	rk.push_back(a);
	rk.push_back(b);
	rk.push_back(c);
	sort(rk.begin(), rk.end());
	int tot=0;
	if (rk[1]-rk[0] < d) {
		tot += d-(rk[1]-rk[0]);
	}
	if (rk[2]-rk[1] < d) {
		tot += d-(rk[2]-rk[1]);
	}
	cout<<tot<<endl;
	return 0;
}
