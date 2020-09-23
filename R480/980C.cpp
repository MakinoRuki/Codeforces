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
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
int p[N];
int lm[300];
int main() {
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}
	memset(lm, -1, sizeof(lm));
	for (int i = 1; i <= n; ++i) {
		if (lm[p[i]] >= 0) {
			p[i]=lm[p[i]];
		} else {
			lm[p[i]]=p[i];
			for (int j = 1; j < k; ++j) {
				if (p[i]-j<0) break;
				if (lm[p[i]-j] < 0) {
					lm[p[i]]=min(lm[p[i]], p[i]-j);
				} else {
					int id=lm[p[i]-j];
					if (p[i]-id+1<=k) {
						lm[p[i]]=min(lm[p[i]], id);
					} else {
						break;
					}
				}
			}
			for (int j = p[i]-1; j >= lm[p[i]]; --j) {
				lm[j] = lm[p[i]];
			}
		}
		// if (vis[p[i]]) {
		// 	int j;
		// 	for (j = 0; j < k; ++j) {
		// 		if (p[i]-j>=0 && vis[p[i]-j]==vis[p[i]]) {
		// 			continue;
		// 		}
		// 	}
		// 	j--;
		// 	p[i]=p[i]-j;
		// } else {
		// 	int j;
		// 	for (j=0; j <k; ++j) {
		// 		if (p[i]-j<0) break;
		// 		if (vis[p[i]-j]) break;
		// 	}
		// 	if (j>=k || p[i]-j<0) {
		// 		j--;
		// 		for (int j2=0; j2 <= j; ++j2) {
		// 			vis[p[i]-j2]=cnt;
		// 		}
		// 		p[i]=p[i]-j;
		// 		cnt++;
		// 	} else {
		// 		int j2;
		// 		for (j2=j; p[i]-j2>=0 ;++j2) {
		// 			if (vis[p[i]-j2] != vis[p[i]-j]) {
		// 				break;
		// 			}
		// 		}
		// 		j2--;
		// 		if (j2+1<=k) {
		// 			for (int j3=0; j3 < j; ++j3) {
		// 				vis[p[i]-j3]=vis[p[i]-j];
		// 			}
		// 			p[i]=p[i]-j2;
		// 		} else {
		// 			for (int j3=0; j3<j; ++j3) {
		// 				vis[p[i]-j3]=cnt;
		// 			}
		// 			cnt++;
		// 			p[i]=p[i]-j+1;
		// 		}
		// 	}
		// }
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d", lm[p[i]]);
		if (i<n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
