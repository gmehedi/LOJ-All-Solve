
#include<stdio.h>

int Ans(char s1[1000000],char s2[1000000], double num){
    int i = 0;
    for( i = 0; i < 12; i++) num = (num * 10);
    double num1 = 0, num2 = 0;
    int len1 = 0, len2 = 0, flag1 = 0, flag2 = 0;

    for( i = 0; s1[i] != '\0'; i++){
        if(flag1 != 0) len1++;
        if(s1[i] != '.'){

            num1 = (num1 * 10) + (s1[i]-'0');
        }
        else flag1 = 1;
    }
    for( i = 0; i < (12-len1); i++) num1 = (num1 * 10);

    for( i = 0; s2[i] != '\0'; i++){
        if(flag2 != 0) len2++;
        if(s2[i] != '.'){
            num2 = (num2 * 10) + (s2[i]-'0');
        }
        else flag2 = 1;
    }
    double res = 0.0;
  //  printf("Len   %d   %d\n",len1,len2);
    for( i = 0; i < (12-len2); i++) num2 = (num2 * 10);

    if(num1 > num2){
        res = num1 - num2;
    }
    else res = num2 - num1;
    //printf("All %f   %f   %f\n",num1,num2,num);
   // printf("M   %f\n",res);
    if(res < num) return 0;
    if(res > num) return 1;
    return 2; // both are equal
}

int main(){

    char s1[1000000],s2[1000000];
    double num;

    scanf("%s%s%lf",s1,s2,&num);
    int ans = Ans(s1,s2,num);

    if(ans == 1) {
        printf("It's true\n");
    }
    else if(ans == 0) printf("It's false\n");
    else printf("Both are equal\n");

    return 0;
}
