#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
char text[MAX], ptrn[MAX];
int F[MAX];

void build_failure( char *ptrn, int len ){
    F[0] = F[1] = 0;
    int i,j;
    for( i=2; i<=len; ++i ){
        j = F[i-1];
        while( true ) {
            if( ptrn[j] == ptrn[i-1] ) {
                F[i] = j+1;
                break;
            }
            if( j==0 ) {
                F[i] = 0;
                break;
            }
            j = F[j];
        }
    }
}

int KMP( char *text, int len_t, char *ptrn, int len_p ){
    int cnt = 0;
    build_failure( ptrn, len_p );
    int a = 0, b = 0;

    while ( b<len_t ){
        if ( text[b] == ptrn[a] ) {
            ++a, ++b;
            if( a == len_p ) ++cnt; // match found
        } else if( a>0 ) a = F[a];
        else ++b;
    }
    return cnt;
}

int main () {
    int test, res, cases=0;
    cin >> test;

    while (test--) {
        cin >> text;
        cin >> ptrn;

        res = KMP(text, strlen(text), ptrn, strlen(ptrn));
        cout << "Case " << ++cases << ": " << res << endl;
    }
    return 0;
}
