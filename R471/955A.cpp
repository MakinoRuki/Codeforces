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
#define N 2602
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int hh, mm;
int h, d, c;
int main() {
	string s1,s2;
	cin>>s1>>s2;
	hh = stoi(s1);
	mm = stoi(s2);
	cin>>h>>d>>c>>n;
	int t1 = hh*60+mm;
	// if (hh==0 && mm == 0) {
	// 	t1 = 24*60;
	// }
	int t2 = 20*60;
	if (t1 >= t2 && t1 < 24*60) {
		int x = (h+n-1)/n;
		double res = (double)x*(double)c*0.8;
		printf("%.10lf\n", res);
	} else {
		int det = t2-t1;
		double ans = -1;
		for (int i = 0; i <= h; ++i) {
			ll cur = h-(ll)i*(ll)n;
			if (cur > 0) {
				cur += (ll)d*(ll)det;
				cur = (cur + n - 1) / n;
			}
			cur = max(cur, 0LL);
			double res = (double)i * (double)c + (double)cur * (double)c * 0.8;
			if (ans < 0 || res < ans) {
				ans = res;
			}
		}
		printf("%.10lf\n", ans);
	}
  return 0;
}
