#include<stdio.h>
#include<string.h>
int main(){
	int n;
	int i;
	char str1[100];
	n=10;
	char str[] ="ATTACK";
    for(i=0;i<=strlen(str);i++){
    str1[i] = (str[i] - 'A' + n) % 26 + 'A';
    }

    printf("%s\n", str1);

    return 0;
}
    	
