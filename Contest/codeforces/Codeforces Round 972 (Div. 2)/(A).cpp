#include<bits/stdc++.h>

using namespace std;

int main() {
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        int k = n / 5;
        int na = k;
        int ne = k;
        int ni = k;
        int no = k;
        int nu = k;
        n %= 5;
        if(n) na++, n--;
        if(n) ne++, n--;
        if(n) ni++, n--;
        if(n) no++, n--;
        if(n) nu++, n--;
        
        for(int i = na; i--; ) printf("a");
        for(int i = ne; i--; ) printf("e");
        for(int i = ni; i--; ) printf("i");
        for(int i = no; i--; ) printf("o");
        for(int i = nu; i--; ) printf("u");
        puts("");
    }
}
