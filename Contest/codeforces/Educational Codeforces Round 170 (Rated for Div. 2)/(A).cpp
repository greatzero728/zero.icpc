#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        string a, b; cin>>a>>b;
        int nn = 0;
        for(int i = 0; i < a.size() && i < b.size(); i++) {
            if(a[i] != b[i]) break;
            nn++;
        }
        printf("%d\n", min(a.size() + b.size(), a.size() + b.size() - nn + 1));
    }
	return 0;
}
