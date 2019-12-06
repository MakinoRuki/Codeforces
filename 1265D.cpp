#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 400020
using namespace std;
int num[4];
void handle1(int a) {
	if (num[a] > 1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl<<a<<endl;
}
void handle2(int a, int b) {
	if (abs(num[a]-num[b]) > 1) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		if (num[a] >= num[b]) {
			for (int i = 0; i < num[a]+num[b]; ++i) {
				if (i%2 ==0) cout<<a;
				else cout<<b;
				if (i < num[a]+num[b]-1) cout<<" ";
				else cout<<endl;
			}
		} else {
			for (int i = 0; i < num[a]+num[b]; ++i) {
				if (i%2==0) cout<<b;
				else cout<<a;
				if (i < num[a]+num[b]-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
}
void handle3(int a, int b, int c) {
	vector<int> ans;
	ans.clear();
	bool ok = true;
	bool cur=false;
	while(true) {
		if ((!cur && num[a]) || (cur && !num[c])) {
			if (num[a]) {
				if (num[b]) {
					ans.push_back(a);
					ans.push_back(b);
					num[a]--;
					num[b]--;
					cur=!cur;
				} else {
					if (num[c]) {
						ok=false;
					} else if (num[a]>1) {
						ok=false;
					} else {
						ans.push_back(a);
						num[a]--;
					}
					break;
				}
			} else {
				if (num[b]>1) {
					ok=false;
				}
				break;
			}
		} else if ((cur&&num[c]) || (!cur && !num[a])) {
			if (num[c]) {
				if (num[b]) {
					ans.push_back(c);
					ans.push_back(b);
					num[b]--;
					num[c]--;
					cur=!cur;
				} else {
					if (num[a]) {
						ok=false;
					} else if (num[c] > 1) {
						ok=false;
					} else {
						ans.push_back(c);
						num[c]--;
					}
					break;
				}
			} else {
				if (num[b]>1) ok=false;
				break;
			}
		}
	}
	if (!ok) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		if (num[b]==1) cout<<b<<" ";
		for (int i = 0; i < ans.size(); ++i) {
			cout<<ans[i];
			if (i < ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
}
void handle4(int a, int b, int c, int d) {
	if (num[a] > num[b] || num[d] > num[c]) cout<<"NO"<<endl;
	else {
		vector<int> ans;
		ans.clear();
		int det1=num[b]-num[a];
		int det2=num[c]-num[d];
		if (abs(det1-det2) > 1) {
			cout<<"NO"<<endl;
		} else {
			if (det1>det2) {
				ans.push_back(b);
			}
			for (int i = 0; i < num[a]; ++i) {
				ans.push_back(a);
				ans.push_back(b);
			}
			for (int i = 0; i < min(det1, det2); ++i) {
				ans.push_back(c);
				ans.push_back(b);
			}
			for (int i = 0; i < num[d]; ++i) {
				ans.push_back(c);
				ans.push_back(d);
			}
			if (det1<det2) {
				ans.push_back(c);
			}
			cout<<"YES"<<endl;
			for (int i = 0; i < ans.size(); ++i) {
				cout<<ans[i];
				if (i < ans.size()-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
}
int main() {
	cin>>num[0]>>num[1]>>num[2]>>num[3];
	int tot=num[0]+num[1]+num[2]+num[3];
	if (num[0] == tot) {
		handle1(0);
	} else if (num[1]==tot) {
		handle1(1);
	} else if (num[2] == tot) {
		handle1(2);
	} else if (num[3] == tot) {
		handle1(3);
	} else if (num[0] && num[1] && num[0]+num[1] == tot) {
		handle2(0, 1);
	} else if (num[1] && num[2] && num[1]+num[2] == tot) {
		handle2(1, 2);
	} else if (num[2] && num[3] && num[2]+num[3] == tot) {
		handle2(2, 3);
	} else if (num[0] && num[1] && num[2] && num[0]+num[1]+num[2] == tot) {
		handle3(0, 1, 2);
	} else if (num[1] && num[2] && num[3] && num[1]+num[2]+num[3] == tot) {
		handle3(1, 2, 3);
	} else if (num[0] && num[1] && num[2] && num[3]) {
		handle4(0, 1, 2, 3);
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
