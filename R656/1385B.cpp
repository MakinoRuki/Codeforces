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
#define N 102
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= 2*n; ++i) {
			scanf("%d", &a[i]);
		}
		vector<int> res;
		res.clear();
		int j;
		for (int i = 1; i <= 2*n; ++i) {
			if (res.empty()) {
				res.push_back(a[i]);
				j = 0;
			} else {
				if (j >= res.size() || a[i] != res[j]) {
					res.push_back(a[i]);
				} else {
					j++;
				}
			}
		}
		for (int i =0; i < res.size(); ++i) {
			printf("%d", res[i]);
			if (i < res.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
