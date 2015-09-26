#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

struct content{
    int freq=0;
    char letter;
};

bool my_compare(content a, content b){
    if(a.freq > b.freq)
        return true;
    else if(a.freq==b.freq && a.letter<b.letter)
        return true;
    else
        return false;
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    string line;
    int result[100] = {0};

    while(n--){
        getline(cin, line);
        for(int k=0, len=line.size(); k<len; k++){
            if( isalpha(line[k]) ){
                result[toupper(line[k])]++;
            }
        }
    }

    struct content letters[26];

    for(int i=0, k=65; k<=90; k++){
        if(result[k]){
            letters[i].freq = result[k];
            letters[i].letter = k;
            i++;
        }
    }

    sort(letters, letters+26, my_compare);

    for(int k=0; letters[k].freq; k++){
        printf("%c %d\n", letters[k].letter, letters[k].freq);
    }

    return 0;
}
