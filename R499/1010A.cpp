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
#define N 1005
#define eps 1e-6
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int a[N], b[N];
bool check(double cur, double mm) {
	//cout<<"mm="<<mm<<endl;
	for (int j = 1; j <= n; ++j) {
	//	cout<<"j="<<j<<endl;
		if (j==1) {
			if (cur > a[j]*mm) {
				return false;
			}
			mm -= cur/a[j];
			cur -= cur/a[j];
		} else {
			if (cur > b[j]*mm) {
				return false;
			} else {
				mm -= cur/b[j];
				cur -= cur/b[j];
			}
			if (cur > a[j]*mm) {
				return false;
			} else {
				mm -= cur/a[j];
				cur -= cur/a[j];
			}
		}
	//	cout<<"j2="<<j<<endl;
	//	cout<<cur<<" "<<mm<<endl;
	}
	if (cur > b[1]*mm) {
		return false;
	}
	return true;
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	double l = 0.0, r = 1000000000.0;
	for (int i = 1; i <= 1000; ++i) {
		if (fabs(l-r) <= eps) {
			break;
		}
		double mid=(l+r)*0.5;
		if (!check(m+mid, mid)) {
			l=mid;
		} else {
			r=mid;
		}
	}
	if (check(m+r, r)) {
		printf("%.7lf\n", r);
	} else {
		cout<<-1<<endl;
	}
	//cout<<check(m+10,10)<<endl;
	//cout<<check(m+500000000,500000000)<<endl;
	return 0;
}
