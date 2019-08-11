
#include<stdio.h>

int Ans(char s1[1000000],char s2[1000000], double num, int isMinus1, int isMinus2 ){

  //  printf("S  %s  %s  %d   %d\n",s1,s2,isMinus1, isMinus2);
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

    if(isMinus1) num1 = (num1 * (-1));
    if(isMinus2) num2 = (num2 *(-1));

    if(num1 > num2){
        res = num1 - num2;
    }
    else res = num2 - num1;
  // printf("All %f   %f   %f   %f\n",num1,num2,res, num);
  //  printf("M   %f\n",res);
    if(res > num) return 1;

    return 0;
}

int Check(char s1[10000], char s2[10000], double num){
    char x1[10000],y1[10000],x2[10000],y2[10000];
    // printf("tttffg\n");

    int i = 0, j = 0, minusx1 = 0, minusy1 = 0, minusx2 = 0, minusy2 = 0;
    if(s1[0] == '-') minusx1 = 1;
    if(s2[0] == '-') minusx2 = 1;

    while(s1[i] != ','){
        x1[i] = s1[i];
        i++;
    }
    x1[i] = '\0';
    while( 1 ){
        if(s1[i] == '-') minusy1 = 1;
        if(s1[i] >= '0' && s1[i] <= '9') break;
        i++;
    }

    j = 0;
    while(s1[i] != '\0'){
        y1[j] = s1[i];
        i++, j++;
    }

    y1[j] = '\0';
    //........................//
   // printf("dfghjk\n");

    i = 0, j = 0;
    while(s2[i] != ','){
        x2[i] = s2[i];
        i++;
    }
    x2[i] = '\0';
    while( 1 ){
        if(s2[i] == '-') minusy2 = 1;
        if( (s2[i] >= '0' && s2[i] <= '9') ) break;
        i++;
    }
    j = 0;
    while(s2[i] != '\0'){
        y2[j] = s2[i];
        i++, j++;
    }
   //printf("F  %d  %d  %d  %d  %d\n",x1,x2,y1,y2);

    int res1 = Ans(x1,x2,num,minusx1,minusx2);
    int res2 = Ans(y1,y2,num,minusy1,minusy2);

    return (res1 == 1 || res2 == 1);

}

int myFunction(char s1[1000000],char s2[1000000], double num){
    return Check(s1,s2,num);
}

int main(){

    int ans = myFunction("33.145334,-117.243233","33.145333,-117.243334",0.000100);

    if(ans == 1) {
        printf("It's true\n");
    }
    else  printf("It's false\n");

    return 0;
}

/*

"33.145334,-117.243233",33.145333,-117.243334",0,000100

*/
