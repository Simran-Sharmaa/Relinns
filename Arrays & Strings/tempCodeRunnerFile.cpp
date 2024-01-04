#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>&mat){
    int n=mat.size();
    int m= mat[0].size();
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void multiplyMat(vector<vector<int> >& A, vector<vector<int>>&B){
    int R1=A.size();
    int R2= B.size();
    int C1=A[0].size();
    int C2= B[0].size();
    vector<vector<int>>ans(R1,vector<int>(C2,0));
    for(int i=0;i<R1;i++){
        for(int j=0;j<C2;j++){
            ans[i][j]=0;
            for(int k=0;k<R2;k++){
                ans[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    printMatrix(ans);
}
int main(){
    int a,b,c,d;
    cout<<"Enter the number of row and column of first matrix:"<<endl;
    cin>>a;
    cin>>b;
    cout<<"Enter the number of row and column of second matrix:"<<endl;
    cin>>c;
    cin>>d;
    vector<vector<int>>matrixA(a,vector<int>(b,0));
    vector<vector<int>>matrixB(c,vector<int>(d,0));
    cout<<"Enter elements for matrix 1"<<endl;

   for (int i = 0; i < a; i++)
   {
    cout<<"enter the elements for row"<<i+1<<endl;
    for (int j = 0; j < b; j++)
    {
        cin>>matrixA[i][j];
    }
   }
    cout<<"Enter elements for matrix 2"<<endl;
   for (int i = 0; i < c; i++)
   {
    cout<<"enter the elements for row"<<i+1<<endl;
    for (int j = 0; j < d; j++)
    {
        cin>>matrixB[i][j];
    } 
   }
   multiplyMat(matrixA,matrixB);
}