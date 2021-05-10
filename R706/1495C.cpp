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
#define M 21
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,m;
vector<string> mat;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		mat.clear();
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
		}
		for (int i = 0; i < m; ++i) {
			mat[0][i] = 'X';
		}
		int i = 0;
		while(i < n) {
			if (i + 3 < n) {
				for (int j = 0; j < m; ++j) {
					mat[i+3][j] = 'X';
				}
				int id2=-1,id3=-1;
				for (int j = 0; j < m; ++j) {
					if (mat[i+1][j] == 'X') {
						if (id2<0) id2 = j;
					}
					if (mat[i+2][j] == 'X') {
						if (id3<0) id3 = j;
					}
				}
				if (id3>=0) {
					for (int i2 = i; i2 <= i+3; ++i2) {
						mat[i2][id3] = 'X';
					}
				} else {
					if (id2<0) id2=0;
					for (int i2 = i; i2 <= i+3; ++i2) {
						mat[i2][id2] = 'X';
					}
				}
			} else {
				if (i+2<n) {
					for (int j = 0; j < m; ++j) {
						if (mat[i+2][j] == 'X') {
							mat[i+1][j] = 'X';
						}
					}
				}
			}
			i += 3;
		}
		for (int i = 0; i < n; ++i) {
			cout<<mat[i]<<endl;
		}
	}
  return 0;
}
