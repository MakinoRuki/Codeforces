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
#define N 500005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int m, k, n, s;
int a[N], b[N];
int cnt1[N], cnt2[N];
int main() {
	cin>>m>>k>>n>>s;
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= s; ++i) {
		scanf("%d", &b[i]);
		cnt2[b[i]]++;
	}
	int i = 0;
	int tot=0;
	bool found=false;
	for (int j = 1; j <= m; ++j) {
		while(i+1 <= m && tot < s) {
			++i;
			cnt1[a[i]]++;
			if (cnt1[a[i]] <= cnt2[a[i]]) {
				tot++;
			}
		}
	//	cout<<"j="<<j<<" "<<i<<endl;
		//if (i==m) cout<<"j="<<j<<endl;
		if (tot == s) {
		//	cout<<"x="<<j<<" "<<i<<endl;
			int n1 = (j-1)/k;
			int r1 = (j-1)%k;
			int det=r1+i-j+1;
			if (det>k) {
				det -= min(r1, det-k);
			}
			if (det>k) {
				det -= min(i-j+1-s, det-k);
			}
			det = r1+i-j+1-det;
		//	cout<<"det="<<det<<endl;
			if ((m-det)/k >= n) {
		//		cout<<"y="<<det<<" "<<(m-det)/k<<endl;
				found=true;
				vector<int> ids;
				ids.clear();
				memset(cnt1, 0, sizeof(cnt1));
				for (int i2 = n1*k+1; i2 <= i; ++i2) {
					cnt1[a[i2]]++;
					if (cnt1[a[i2]] > cnt2[a[i2]] && ids.size() < det) {
						ids.push_back(i2);
					}
				}
				cout<<det<<endl;
				for (int i2 = 0; i2 < ids.size(); ++i2) {
					printf("%d", ids[i2]);
					if (i2 < ids.size()-1) cout<<" ";
					else cout<<endl;
				}
				break;
			}
		}
		cnt1[a[j]]--;
		if (cnt1[a[j]] < cnt2[a[j]]) {
			tot--;
		}
	}
	if (!found) {
		cout<<-1<<endl;
	}
	return 0;
}
