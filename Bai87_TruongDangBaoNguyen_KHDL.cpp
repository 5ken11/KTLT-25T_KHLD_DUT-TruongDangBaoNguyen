#include <stdio.h>
#define max 1001

int A[max + 1][max + 1];
int B[max + 1][max + 1];
int m, n;
int t = 1;

bool queue(){                               //Truy vấn xem thử có tiếp tục không?
    char s;
    printf("Tiep tuc?(Y/N):");
    scanf("%c", &s);
    if (s == 'Y') return true;
    else if (s == 'N') return false;
}

void input(){                               //Nhập ma trận ban đầu.
    scanf("%d %d", &m, &n);
    int temp;
    for(int i = 1 ; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &temp);
            A[i][j] = temp;
        }
    }    
}

void refresh(){                             //Làm mới ma trận để chuẩn bị cho truy vấn tiếp theo.
    for(int i = 1 ; i <= m; i++){
        for(int j = 1; j <= n; j++){
           A[i][j] = B[i][j];
           B[i][j] = 0;
        }
    }
}

int getSum(int i, int j){                   //Tính tổng các cá thể xung quanh vị trí i, j.
    return A[i - 1][j - 1] + A[i - 1][j] + A[i - 1][j + 1] + A[i][j - 1] + A[i][j + 1] + A[i + 1][j - 1] + A[i + 1][j] + A[i + 1][j + 1];    
}

void solution(){                            //Phương pháp giải quyết.
    int temp;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            temp = getSum(i, j);
            if(A[i][j] == 0 && temp == 3){  //Th1:Nếu có đúng 3 cá thể xung quanh thì sẽ được sinh ra.
                B[i][j] = 1;
            }
            else if(temp < 2 && A[i][j] == 1) B[i][j] = 0; //Th2: Nếu có ít hơn 2 cá thể thì sẽ chết.
            else if(temp > 3 && A[i][j] == 1) B[i][j] = 0;  //Th3: Nếu có nhiều hơn 3 cá thể thì sẽ chết.
            else B[i][j] = A[i][j];
        }
    }
}

void printMatrix(){                         //In Ma trận.
    printf("Ma trận sau %d thế hệ:\n", t);
    for(int i = 1 ; i <= m; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    input();
    solution();
    refresh();
    printMatrix();
    bool getQueue = queue();
    while (getQueue){
        t++;
        solution();
        refresh();
        printMatrix();
        getQueue = queue();    
    }   
}
