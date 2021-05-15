#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#include <time.h>
#define N 2005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t,n,m;
vector<string> mat;
int cnt[N];
int main() {
	cin>>n>>m;
	mat.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
	}
	memset(cnt, 0, sizeof(cnt));
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (mat[i][j] == '1') cnt[j]++;
		}
	}
	bool found=false;
	for (int i = 0; i < n; ++i) {
		int j;
		for (j = 0; j < m; ++j) {
			if (mat[i][j]=='1' && cnt[j] == 1) {
				break;
			}
		}
		if (j >= m) {
			found=true;
			break;
		}
	}
	if (found) puts("YES");
	else puts("NO");
	return 0;
}
