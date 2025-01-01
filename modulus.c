#include<stdio.h>

int simplifying(int base, int exponent, int modulus){

    if(exponent == 0) 
    return 1;

    int ans = 1;
    
    for(int counter = 0; counter < exponent; counter++){
        ans = (ans * base) % modulus;
    }
    return ans;
}

int main(){
    int base,exponent,modulus;
    printf("Enter the values:");
    scanf("%d %d %d",&base,&exponent,&modulus);

    int result = simplifying(base,exponent,modulus);
    printf("RESULT: %d", result);
}