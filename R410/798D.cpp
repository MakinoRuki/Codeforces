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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<pair<int, pair<int,int>>> ab;
int main() {
	cin>>n;
	ab.clear();
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		ab.push_back(make_pair(a, make_pair(-1, i)));
	}
	for (int i = 1; i <= n; ++i) {
		int b;
		scanf("%d", &b);
		ab[i-1].second.first = b;
	}
	sort(ab.begin(), ab.end());
	vector<int> ids;
	ids.clear();
	ids.push_back(ab.back().second.second);
	for (int i = ab.size()-2; i >= 0; i -= 2) {
		if (i==0) {
			ids.push_back(ab[i].second.second);
		} else {
			if (ab[i].second.first > ab[i-1].second.first) {
				ids.push_back(ab[i].second.second);
			} else {
				ids.push_back(ab[i-1].second.second);
			}
		}
	}
	printf("%d\n", n/2+1);
	for (int i = 0; i < ids.size(); ++i) {
		printf("%d", ids[i]);
		if (i < ids.size()-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
