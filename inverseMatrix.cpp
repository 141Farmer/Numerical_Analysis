#include <iostream>
#include <vector>
using namespace std;
void input(vector<vector<double>> &matrix)
{
      freopen("matInput.txt","r",stdin);
      int n;
      cin>>n;
      matrix.resize(n, vector<double>(n));
      for (int i=0;i<n;++i) 
            for (int j=0;j<n;++j) 
                  cin>>matrix[i][j];
}
void printMatrix(vector<vector<double>> matrix) 
{
      for(vector<double> it:matrix)
      {
            for(double d:it)
                  cout<<d<<" ";
            cout<<endl;
      }
      cout<<endl;
}
vector<vector<double>> inverseMatrix(vector<vector<double>> matrix) 
{
      int n=matrix.size();
      vector<vector<double>>augmentedMatrix(n,vector<double>(2*n));
      for(int i=0;i<n;++i) 
            for(int j=0;j<n;++j) 
            {
                  augmentedMatrix[i][j]=matrix[i][j];
                  augmentedMatrix[i][j+n]=(i==j) ? 1.0 : 0.0; 
            }
      printMatrix(augmentedMatrix);
      for(int i=0;i<n;++i) 
      {  
            double pivot=augmentedMatrix[i][i];
            for(int j=0;j<2*n;++j) 
                  augmentedMatrix[i][j]/=pivot;
            for(int k=0;k<n;++k) 
            {
                  if (k!=i) 
                  {
                        double factor=augmentedMatrix[k][i];
                        for(int j= 0;j<2*n;++j) 
                              augmentedMatrix[k][j]-=factor*augmentedMatrix[i][j];
                  }
            }
            printMatrix(augmentedMatrix);
      }
      vector<vector<double>> inverse(n,vector<double>(n));
      for (int i=0;i<n;++i) 
            for (int j=0;j<n;++j) 
                  inverse[i][j]=augmentedMatrix[i][j+n];
      return inverse;
}
int main() 
{    
    vector<vector<double>>matrix;
    input(matrix);
    printMatrix(matrix);
    vector<vector<double>> invMatrix=inverseMatrix(matrix);
    printMatrix(invMatrix);
    return 0;
}