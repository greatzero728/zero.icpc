#include<bits/stdc++.h>

using namespace std;

deque<char> s;

bool ask() {
    printf("? ");
    for(char c: s) cout<<c; puts("");
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        s.clear(); s.push_back('0');
        if(!ask()) s.back() = '1';
        
        bool ok = 1;
        for(int len = 2; len <= n; len++) {
            if(ok) {
                s.push_back('0');
                if(ask()) continue;
                
                s.back() = '1';
                if(ask()) continue;
                s.pop_back();
                ok = 0;
            }
            if(!ok) {
                s.push_front('0');
                if(!ask()) s.front() = '1';
            }
        }
        
        printf("! "); for(char c: s) cout<<c; puts("");
        fflush(stdout);
    }
}