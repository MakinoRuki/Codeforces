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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
string s,t;
int main() {
	cin>>n>>m;
	cin>>s>>t;
	int ans=n+1;
	vector<int> ids;
	ids.clear();
	for (int i = 0; i + n <= m; ++i) {
		int cnt=0;
		vector<int> tmp;
		tmp.clear();
		for (int j = 0; j < n; ++j) {
			if (s[j] != t[i+j]) {
				tmp.push_back(j+1);
				cnt++;
			}
		}
		if (cnt<ans) {
			ans=cnt;
			ids=tmp;
		}
	}
	cout<<ans<<endl;
	for (int i = 0; i < ids.size(); ++i) {
		printf("%d", ids[i]);
		if (i<ids.size()-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}

