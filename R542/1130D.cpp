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
#define N 5002
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<int> segs[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		segs[a].push_back(b);
	}
	for (int i = 0; i < n; ++i) {
		int maxv = 0;
		for (int j = 0; j < n; ++j) {
			if (segs[j].empty()) continue;
			int sum = (j-i+n)%n;
			int minv = n;
			for (int k = 0; k < segs[j].size(); ++k) {
				int v = segs[j][k];
				if (k > 0) {
					sum += n;
				}
				minv = min(minv, (v-j+n)%n);
			}
			sum += minv;
			maxv = max(maxv, sum);
		}
		printf("%d", maxv);
		if (i < n-1) cout<<" ";
		else cout<<endl;
	}
  return 0;
}
