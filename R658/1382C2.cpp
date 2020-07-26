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
// struct node {
// 	int l, r;
// 	bool f;
// 	int c0, c1;
// } tree[N<<4];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		cin>>a>>b;
		vector<int> ans;
		ans.clear();
		int l = 0, r = n-1;
		int cnt=0;
		for (int i = n-1; i >= 0; --i) {
			if (cnt%2==0) {
				int x = a[l]-'0';
				l++;
				if (b[i]-'0' == x) {
					ans.push_back(1);
				}
				ans.push_back(i+1);
				cnt++;
			} else {
				int x = a[r]-'0';
				r--;
				x = !x;
				if (b[i] - '0' == x) {
					ans.push_back(1);
				}
				ans.push_back(i+1);
				cnt++;
			}
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
