#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int test, cases=0, sqrt_check, point, k;
    string dang, new_dang;

    cin >> test;
    cin.ignore(); // stops getline from skipping the first input

    while(test--){
        getline(cin, dang);
        sqrt_check = sqrt(dang.size());
        if(dang.size() == sqrt_check*sqrt_check){
            point = 0; new_dang.clear();
            while(point < sqrt_check){
                for(k=point; k<dang.size(); k+=sqrt_check){
                    string dang_child(1, dang[k]); // converting a single character to a string
                    new_dang.append(dang_child);
                }
                point++;
            }
            cout << new_dang << endl;
        }
        else
            cout << "INVALID\n";
    }
    return 0;
}
