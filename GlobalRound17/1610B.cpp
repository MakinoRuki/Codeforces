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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int a[N];
bool check(int x) {
	int l = 1, r = n;
	while(l < r) {
		while(l < r && a[l] == x) {
			l++;
		}
		while(l < r && a[r] == x) {
			r--;
		}
		if (l >= r) {
			break;
		}
		if (a[l] == a[r]) {
			l++;
			r--;
		} else {
			return false;
		}
	}
	return true;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		int l = 1, r = n;
		while(l < r) {
			if (a[l] == a[r]) {
				l++;
				r--;
			} else {
				break;
			}
		}
	//	cout<<a[l]<<" "<<a[r]<<endl;
		if (check(a[l]) || check(a[r])) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
  return 0;
}

