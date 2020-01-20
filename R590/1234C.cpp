#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q, n;
vector<string> ss;
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		cin>>n;
		ss.resize(2);
		cin>>ss[0]>>ss[1];
		int cx = 0, cy = 0;
		int px = 0, py = -1;
		bool ok = true;
		while(true) {
			if (cx < 0 || cx > 1 || cy < 0 || cy > n-1) {
				ok = false;
				break;
			}
			if (cx == 1 && cy == n-1) {
				break;
			}
			if (cx == 0) {
				if (ss[cx][cy] == '1' || ss[cx][cy] == '2') {
					if (px != cx) {
						ok = false;
						break;
					}
					px= cx;
					py = cy;
					cy++;
				} else {
					if (px == 0) {
						px = cx;
						py = cy;
						cx++;
					} else {
						px = cx;
						py = cy;
						cy++;
					}
				}
			} else {
				if (ss[cx][cy] == '1' || ss[cx][cy] == '2') {
					if (px != cx) {
						ok = false;
						break;
					}
					px = cx;
					py = cy;
					cy++;
				} else {
					if (px == 1) {
						px = cx;
						py = cy;
						cx--;
					} else {
						px = cx;
						py = cy;
						cy++;
					}
				}
			}
		}
		if (ok && cx == 1 && cy == n-1) {
			if (px == 0 && ss[cx][cy] != '1' && ss[cx][cy] != '2') {
				cout<<"YES"<<endl;
			} else {
				if (px == 1 && (ss[cx][cy] == '1' || ss[cx][cy] == '2')) {
					cout<<"YES"<<endl;
				} else {
					cout<<"NO"<<endl;
				}
			}
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
