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
#define N 105
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		vector<string> ans;
		ans.clear();
		for (int i = 1; i <= n; ++i) {
			if (i==1) {
				if (a[i]==0) {
					ans.push_back("a");
					ans.push_back("b");
				} else {
					ans.push_back(string(a[i], 'a'));
					ans.push_back(string(a[i], 'a'));
				}
			} else {
				if (a[i] > ans.back().size()) {
					int det=a[i]-(int)ans.back().size();
					char c = 'a';
					string t = ans.back();
					ans.pop_back();
					if (!ans.empty() && ans.back().size()>t.size() && ans.back()[t.size()] == c) {
						c = 'b';
					}
					for (int j = 1; j <= det; ++j) {
						t.push_back(c);
					}
					ans.push_back(t);
					ans.push_back(t);
				} else {
					string t = ans.back();
					if (a[i]==0) {
						if (t[0]=='a') ans.push_back("b");
						else ans.push_back("a");
					} else {
						ans.push_back(t.substr(0, a[i]));
					}
				}
			}
		}
		for (int i = 0; i < ans.size(); ++i) {
			cout<<ans[i]<<endl;
		}
		//cout<<endl;
	}
  return 0;
}
