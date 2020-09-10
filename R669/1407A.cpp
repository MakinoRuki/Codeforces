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
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, q;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas <=t ; ++cas) {
		scanf("%d", &n);
		vector<int> ds;
		ds.clear();
		int sum=0;
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			if (sum%2==0) {
				sum += x;
				ds.push_back(x);
			} else {
				if (x) {
					ds.push_back(x);
					sum++;
				} else {
					ds.pop_back();
					ds.push_back(x);
					sum--;
				}
			}
		}
		if (sum%2) {
			ds.pop_back();
		}
		printf("%d\n", (int)ds.size());
		for (int i = 0; i < ds.size(); ++i) {
			printf("%d", ds[i]);
			if (i < ds.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
