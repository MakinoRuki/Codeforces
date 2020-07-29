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
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
vector<int> edges[N];
bool va[N], vb[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			va[i] = false;
			vb[i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			int k;
			edges[i].clear();
			scanf("%d", &k);
			for (int j = 1; j <= k; ++j) {
				int g;
				scanf("%d", &g);
				edges[i].push_back(g);
				if (!va[i] && !vb[g]) {
					va[i] = true;
					vb[g] = true;
				}
			}
		}
		int id = 0;
		for (int i = 1; i <= n; ++i) {
			if (!vb[i]) {
				id = i;
				break;
			}
		}
		if (id == 0) {
			cout<<"OPTIMAL"<<endl;
		} else {
			cout<<"IMPROVE"<<endl;
			int j;
			for (j = 1; j <= n; ++j) {
				if (!va[j]) break;
			}
			printf("%d %d\n", j, id);
		}
	}
  return 0;
}
