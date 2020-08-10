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
#define N 2005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
vector<string> mat;
int main() {
	cin>>t;
	for (int cas=1; cas <= t; ++cas) {
		scanf("%d%d", &n, &m);
		mat.clear();
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
		}
		int cnt=0;
		for (int i = n-1; i >= 1; --i) {
			if (mat[i-1][m-1] == 'R') cnt++;
		}
		for (int j = m-1; j >= 1; --j) {
			if (mat[n-1][j-1] == 'D') cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
