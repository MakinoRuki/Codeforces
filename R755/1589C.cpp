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
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int a[N];
int b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n,m;
		scanf("%d", &n);
		set<pair<int,int>> ss;
		ss.clear();
		for (int i =1; i <= n; ++i) {
			scanf("%d", &a[i]);
			ss.insert(make_pair(a[i], i));
		}
		for (int i =1 ; i <= n; ++i) {
			scanf("%d", &b[i]);
		}
		sort(b+1, b+n+1);
		bool ok=true;
		for (int i = n; i >= 1; --i) {
			auto itr = *ss.rbegin();
			if (itr.first > b[i]) {
				ok=false;
				break;
			}
			if (itr.first == b[i]) {
				ss.erase(itr);
			} else {
				if (itr.first + 1 == b[i]) {
					ss.erase(itr);
				} else {
					ok=false;
					break;
				}
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
  return 0;
}
