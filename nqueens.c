#include<stdio.h>
int n;

void display(int board[][n],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int isSafe(int i,int j,int board[][n],int n){
    int originalRow = i;
    int originalCol = j;

    while(j>=0){
        if(board[i][j--]==0) return 0;
    }
    j=originalCol;
    while(j>=0 && i>=0){
        if(board[i--][j--]==0) return 0;
    }
    i=originalRow;
    j= originalCol;
    while(j>=0 && i<n){
        if(board[i++][j--]==0) return 0;
    }

    return 1;
}
void solve(int col,int board[][n],int n){
    if(col==n){
        display(board,n);
        return;
    }
    int i;
    for(i=0;i<n;i++){
        if(isSafe(i,col,board,n)){
            board[i][col]=0;
            solve(col+1,board,n);
            board[i][col]=1;
        }
    }
}


int main(){
int i,j;
   printf("Enter number of queens to be placed:\n");
   scanf("%d",&n);
   printf("\n");
   int board[n][n];
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        board[i][j]=1;
    }
   }
   solve(0,board,n);
}
