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
int q;
int t, n, m;
int mat[N][N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				mat[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; ++i) {
			string s;
			cin>>s;
			for (int j = 1; j <= n; ++j) {
				if (s[j-1] == 'b') mat[i][j] = 2;
				else if (s[j-1] == 'a') mat[i][j] = 1;
			}
		}
		if (n == 2) {
			if (mat[1][2] == mat[2][1]) {
				puts("YES");
				for (int i = 1; i <= m+1; ++i) {
					if (i%2) printf("%d", 1);
					else printf("%d", 2);
					if (i<=m) cout<<" ";
					else cout<<endl;
				}
			} else {
				if (m%2==0) {
					puts("NO");
				} else {
					puts("YES");
					for (int i = 1;  i<= m+1; ++i) {
						if (i%2) printf("%d", 1);
						else printf("%d", 2);
						if (i<=m) cout<<" ";
						else cout<<endl;
					}
				}
			}
		} else {
			if (m%2) {
				puts("YES");
				for (int i = 1;  i<= m+1; ++i) {
					if (i%2) printf("%d", 1);
					else printf("%d", 2);
					if (i<=m) cout<<" ";
					else cout<<endl;
				}
			} else {
				int id1 = -1;
				int id2=-1;
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j) {
						if (i==j) continue;
						if (mat[i][j] == mat[j][i]) {
							id1 = i;
							id2 = j;
							break;
						}
					}
				}
				if (id1>=1) {
					puts("YES");
					for (int i = 1;  i<= m+1; ++i) {
						if (i%2) printf("%d", id1);
						else printf("%d", id2);
						if (i<=m) cout<<" ";
						else cout<<endl;
					}
				} else {
					int m2= m/2;
					if (m2%2) {
						int id = -1;
						int id1=-1;
						int id2=-1;
						for (int i = 1; i <= n; ++i) {
							id1=-1;
							id2=-1;
							for (int j = 1; j <= n; ++j) {
								if (i==j) continue;
								if (mat[i][j] == 1) id1 = j;
								else if (mat[j][i] == 1) id2=j;
							}
							if (id1>=1 && id2>=1) {
								id = i;
								break;
							}
						}
						puts("YES");
						for (int i = 1;  i<= m2+1; ++i) {
							if (i%2) printf("%d", id1);
							else printf("%d", id);
							cout<<" ";
						}
						for (int i = 1;  i<= m2; ++i) {
							if (i%2) printf("%d", id2);
							else printf("%d", id);
							if (i < m2) cout<<" ";
							cout<<endl;
						}
					} else {
						int id = -1;
						int id1=-1;
						int id2=-1;
						for (int i = 1; i <= n; ++i) {
							id1=-1;
							id2=-1;
							for (int j = 1; j <= n; ++j) {
								if (i==j) continue;
								if (mat[i][j] == 1) id1 = j;
								else if (mat[j][i] == 1) id2=j;
							}
							if (id1>=1 && id2>=1) {
								id = i;
								break;
							}
						}
						puts("YES");
						for (int i = 1;  i<= m2+1; ++i) {
							if (i%2) printf("%d", id);
							else printf("%d", id1);
							cout<<" ";
						}
						for (int i = 1;  i<= m2; ++i) {
							if (i%2) printf("%d", id2);
							else printf("%d", id);
							if (i < m2) cout<<" ";
							cout<<endl;
						}
					}
				}
			}
		}
	}
  return 0;
}
