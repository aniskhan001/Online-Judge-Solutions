#include <stdio.h>

int main(){
    int result, day;
    float H, U, D, F, distance;
    while(scanf("%f %f %f %f", &H, &U, &D, &F) && H){
        F = U*F/100;
        day = 0;
        distance = 0;
        while(distance <= H && distance >= 0){
            distance += U;
            U -= F;
            if(U<0)
                U=0;
            if(distance <= H)
                distance -= D;
            day++;
        }
        if(distance > H)
            printf("success on day %d\n", day);

        else if(distance < 0)
            printf("failure on day %d\n", day);
    }

    return 0;
}
