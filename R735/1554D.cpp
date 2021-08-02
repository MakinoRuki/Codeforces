#pragma GCC optimize(2)
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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, l, r, k;
string s;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		if (n == 1) {
			cout<<"a"<<endl;
		} else if (n == 2) {
			cout<<"ab"<<endl;
		} else if (n == 3) {
			cout<<"abc"<<endl;
		} else {
			string ans = "";
			if (n % 2 == 0) {
				int l = (n-1)/2+1;
				int r = (n-1)/2;
				ans = string(l, 'a');
				ans.push_back('b');
				for (int i = 1; i <= r; ++i) {
					ans.push_back('a');
				}
			} else {
				int l = (n-2)/2+1;
				int r = (n-2)/2;
				ans = string(l, 'a');
				ans += "bc";
				for (int i = 1; i <= r; ++i) {
					ans.push_back('a');
				}
			}
			cout<<ans<<endl;
		}
	}
  return 0;
}
