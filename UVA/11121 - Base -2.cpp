#include <iostream>
#include <string>

using namespace std;

string rev(string dang);
string baseMinus2(long n);

int main(){
    int test, cases=0;
    cin >> test;
    while(test--){
        long n;
        cin >> n;
        cout << "Case #" << ++cases << ": " << baseMinus2(n) << endl;
    }
    return 0;
}

string baseMinus2(long n){
    if(n == 0) return "0";
    string res;
    while(n){
        if(n%(-2) == 0){
            res.append("0");
            n /= -2;
        }
        else if(n == -1){ // The special case need to notice
            res.append("11"); // apend 11 if there is a negative remainder
            n = 0;
        }
        else{
            res.append("1");
            n = (n-1)/(-2);
        }
    }

    return rev(res);
}

string rev(string dang){ // generated string from baseMinus2 need to be reversed
    int len=dang.size()-1, k;
    string reversed;
    for(k=len; k>=0; k--){
        reversed.append(1, dang[k]);
    }
    return reversed;
}
