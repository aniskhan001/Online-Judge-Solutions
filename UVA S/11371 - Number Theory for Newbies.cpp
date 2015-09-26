#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

bool descend(char a, char b){
    return (a>b);
}

int main(){

//    freopen("input.txt", "r", stdin);

    string number;
    while(cin >> number){
        sort(number.begin(), number.end());

            int counter = 0;
    //        Counting the number of zeros
            for(int k=0, len=number.size(); k<len; k++){
                if(number[k] == '0')
                    counter++;
            }
    //        Deleting all zeros
            number.erase(remove(number.begin(), number.end(), '0'), number.end());

    //        Initialing the zeros
            string zeros = "";
            while(counter--)
                zeros += "0";

    //        Inserting the zeros right after the first character
            number.insert(1, zeros);

        long long n = atoll(number.c_str());

        sort(number.begin(), number.end(), descend);
        long long p = atoll(number.c_str());

        long long r = p-n;
        printf("%lld - %lld = %lld = 9 * %lld\n", p, n, r, r/9);
    }
    return 0;
}
