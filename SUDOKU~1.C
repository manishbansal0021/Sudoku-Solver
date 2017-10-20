#include<stdio.h>
int solvesudoku(int a[9][9]);
void printarray(int a[9][9]);
int findempty(int a[9][9] , int *row , int *col);
int issafe(int a[9][9] , int row , int col , int num);
int isrowsafe(int a[9][9] , int row ,int num);
int iscolsafe(int a[9][9] ,int col , int num);
int isboxsafe(int a[9][9] , int row , int col , int num);
int main(){
int t,i,a[9][9]={
		 {8,0,0,0,1,0,3,4,7},
		 {0,2,0,8,0,0,0,5,1},
		 {7,0,0,0,6,0,0,0,0},
		 {0,0,0,3,0,0,0,7,0},
		 {6,0,1,0,0,0,9,0,4},
		 {0,7,0,0,0,4,0,0,0},
		 {0,0,0,0,7,0,0,0,6},
		 {0,9,0,0,0,2,0,8,5},
		 {0,0,3,0,5,0,0,0,9}
		};
int j,k;
//scanf("%d",&t);
//for( i=0;i<t;i++){
    for( j=0;j<9;j++){
	for( k=0;k<9;k++){
	    scanf("%d",&a[j][k]);
	}
    }
    if(solvesudoku(a)!=0){
printarray(a); }
/*if(i!=t-1){
    printf("\n");
}
}
else
printf("no solution");
}

*/

return 0;
}
int solvesudoku(int a[9][9]){
int row=0,col=0,i;
if(findempty(a,&row,&col)!=0){
return 1;
}
for(i=1;i<=9;i++){
if(issafe(a,row,col,i)!=0){
a[row][col]=i;


if(solvesudoku(a)!=0){
return 1;
}
a[row][col]=0;
}
}
return 0;

}


void printarray(int a[9][9]){
int i,j;
for(i=0;i<9;i++){
for(j=0;j<9;j++){
printf("%d ",a[i][j]);
}
printf("\n");
}
}


int findempty(int a[9][9] , int *row , int *col){
int i,j;
for(i=0;i<9;i++){
for(j=0;j<9;j++){
if(a[i][j]==0){
*row=i;
*col=j;
return 0;
}

}
}
return 1;
}


int issafe(int a[9][9] , int row , int col , int num){
if(isrowsafe(a,row,num)==1 && iscolsafe(a,col,num)==1 && isboxsafe(a,row,col,num)==1){
return 1;
}
return 0;
}

int isrowsafe(int a[9][9] , int row ,int num){
int i;
for(i=0;i<9;i++){
if(a[row][i]==num){
return 0;
}
}
return 1;
}


int iscolsafe(int a[9][9] ,int col , int num){
int i;
for(i=0;i<9;i++){
if(a[i][col]==num){
return 0;
}
}
return 1;

}
int isboxsafe(int a[9][9] , int row , int col , int num){
int i,j,x_start,y_start;
x_start=row-row%3;
y_start=col-col%3;
for(i=0;i<3;i++){
for(j=0;j<3;j++){
if(a[x_start+i][y_start+j]==num){
return 0;
}
}
}
return 1;
}
