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
#define N 100005
#define M 20010
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
string a, b;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		cin>>a>>b;
		vector<int> ans;
		ans.clear();
		for (int i = n-1; i >= 0; --i) {
			if (a[i] == b[i]) continue;
			int j;
			for (j = i-1; j >= 0; --j) {
				if (a[j] == b[i]) {
					break;
				}
			}
			if (j < 0) {
				ans.push_back(i+1);
				for (int k = 0; k <= i; ++k) {
					a[k] = b[i];
				}
				continue;
			}
			ans.push_back(j+1);
			for (int k = 0; k <= j; ++k) {
				if (a[k]=='0') a[k]='1';
				else a[k] = '0';
			}
			string t = a.substr(0, j+1);
			reverse(t.begin(), t.end());
			a = t + a.substr(j+1);
			if (a[i] == b[i]) continue;
			ans.push_back(i+1);
			for (int k = 0; k <= i; ++k) {
				if (a[k] == '0') a[k]='1';
				else a[k] = '0';
			}
			t = a.substr(0, i+1);
			reverse(t.begin(), t.end());
			a = t+a.substr(i+1);
		}
		int sz = ans.size();
		printf("%d", sz);
		for (int i = 0; i < ans.size(); ++i) {
			printf(" %d", ans[i]);
		}
		cout<<endl;
	}
  return 0;
}
