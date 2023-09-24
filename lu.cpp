#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;
void printMatrix(vector<vector<double>> matrix)
{
    cout<<fixed<<setprecision(3);
    for(auto it:matrix)
    {
        for(double d: it)
            cout<<d<<"   ";
        cout<<endl;
    }
    cout<<endl;
}
void luFactorization(vector<vector<double>> matrix,vector<vector<double>>& L,vector<vector<double>>& U,int n) 
{
    for (int i=0;i<n;i++) 
    {
        for (int k=i;k<n;k++) 
        {
            double sum=0;
            for (int j=0;j<i;j++) 
                sum+=L[i][j]*U[j][k];
            U[i][k]=matrix[i][k]-sum;
        }
        for (int k=i;k<n;k++) 
        {
            if (i==k)
                L[i][i]=1;
            else 
            {
                double sum=0.0;
                for (int j=0;j<i;j++) 
                    sum+=matrix[k][j]*U[j][i];
                L[k][i]=(matrix[k][i]-sum)/U[i][i];
            }
        }
    }
}
vector<double> x_solve(const vector<vector<double>>& U, const vector<double>& y_vector) 
{
    int n = U.size();
    vector<double> result(n, 0);

    for (int i = n - 1; i >= 0; --i) 
    {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) 
        {
            sum += U[i][j] * result[j];
        }
        result[i] = (y_vector[i] - sum) / U[i][i];
    }

    return result;
}

vector<double> y_solve(const vector<vector<double>>& L, const vector<double>& b_vector) 
{
    int n = L.size();
    vector<double> result(n, 0);

    for (int i = 0; i < n; ++i) 
    {
        double sum = 0;
        for (int j = 0; j < i; ++j) 
        {
            sum += L[i][j] * result[j];
        }
        result[i] = (b_vector[i] - sum) / L[i][i];
    }

    return result;
}

void printResult(vector<double> result)
{
    for(double i:result) cout<<i<<" ";
    cout<<endl;
}
vector<vector<double>> multiplyMatrices(vector<vector<double>> matrix1,vector<vector<double>> matrix2) 
{
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();
    vector<vector<double>> result(rows1, vector<double>(cols2,0));
    for (int i = 0; i < rows1; i++) 
        for (int j = 0; j < cols2; j++) 
            for (int k = 0; k < cols1; k++) 
                result[i][j] += matrix1[i][k] * matrix2[k][j];
    return result;
}

int main() 
{
    int n = 3;
    vector<vector<double>> matrix = {{2,-1,0},{-1,2,-1},{0,-1,2}};
    vector<vector<double>> L(n, vector<double>(n,0));
    vector<vector<double>> U(n, vector<double>(n,0));
    vector<double> y_vector={3,4,5};

    luFactorization(matrix,L,U,n);
    
    //printMatrix(multiplyMatrices(L,U)); // right
    //printMatrix(multiplyMatrices(U,L)); //wrong

    printMatrix(L);
    vector<double> x_vector=y_solve(L,y_vector);
    printResult(x_vector);
    

    printMatrix(U);
    vector<double> solution=x_solve(U,x_vector);
    printResult(solution);

    return 0;
}

