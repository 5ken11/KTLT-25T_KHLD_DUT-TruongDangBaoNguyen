#include <stdio.h>
#include <math.h>

int n;
bool check(int n){
    int ans = n*n;
    int result = 0;
    while(n > 0){
        int temp = n % 10;
        n = n / 10;
        result += temp*temp*temp;
    }
    if(ans == result) return true;
    else return false;
}
int main(){
    scanf("%d", &n);
    if(check(n)) printf("n^2 bằng tổng các lập phương các chữ số của n");
    else printf("n^2 không bằng tổng các lập phương các chữ số của n");
}