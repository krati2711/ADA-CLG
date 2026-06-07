#include <stdio.h>

int board[10][10];

int safe(int row,int col,int n){
    // check same column
    for(int i=0;i<row;i++)
        if(board[i][col]==1)
            return 0;

    // check left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        if(board[i][j]==1)
            return 0;

    // check right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        if(board[i][j]==1)
            return 0;

    return 1;
}

void solve(int row,int n){

    if(row==n){
        printf("solution:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%d ",board[i][j]);
            printf("\n");
        }

        return;
    }

    for(int col=0;col<n;col++){

        if(safe(row,col,n)){
            board[row][col]=1;
            solve(row+1,n);
            board[row][col]=0;
        }
    }
}

int main(){
    int n;
    printf("enter n:");
    scanf("%d",&n);

    solve(0,n);

    return 0;
}
