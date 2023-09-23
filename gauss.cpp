#include<iostream>
#include<vector>
using namespace std;
void input(vector<vector<double>> &matrix)
{
    freopen("matInput.txt","r",stdin);
    int n,x;
    cin>>n;
    matrix.resize(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n+1;++j)
        {
            cin>>x;
            matrix[i].push_back(x);
        }
    }
    freopen("CON","r",stdin);
}
vector<vector<double>> gauss(vector<vector<double>> matrix,int n)
{
    int i,j,k;
    int lc=-1;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(!matrix[i][j]) break;
        }
        if(j==n) 
        {
            lc=i;
            break;
        }
    }
    if(i==n)
    {
        cout<<"No solution\n";
    }
    swap(matrix[lc],matrix[0]);
    for(i=1;i<n;++i)
    {
        if(!matrix[i][i])
        {
            for(int j=1;j<n;++j)
            {
                if(matrix[j][i] and matrix[i][j])
                    swap(matrix[i],matrix[j]);
            }
            if(j==n) 
            {
                cout<<"No solution \n";
            }
        }
    }
    for(k=0;k<n-1;++k)
    {
        for(i=k+1;i<n;++i)
        {
            double temp=matrix[i][k]/matrix[k][k];
            //cout<<"("<<temp<<")"<<endl;
            for(j=0;j<n+1;++j)
            {
                matrix[i][j]-=temp*matrix[k][j];
            }
        }   
    }
    return matrix;
}
void printMatrix(vector<vector<double>> matrix)
{
    for(auto it:matrix)
    {
        for(int i:it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
vector<double> solve(vector<vector<double>> &augMat)
{
    int n=augMat.size();
    vector<double>result(n,0);
    for(int i=n-1;i>=0;--i)
    {
        double sum=0;
        for(int j=i+1;j<n;++j)
        {
            sum+=augMat[i][j]*result[j];
        }
        result[i]=(augMat[i][n]-sum)/augMat[i][i];
    }
    return result;
}
void printResult(vector<double> result)
{
    for(double i:result) cout<<i<<" ";
    cout<<endl;
}
int main()
{
    vector<vector<double>> matrix;
    input(matrix);
    printMatrix(matrix);
    vector<vector<double>> augMat=gauss(matrix,matrix.size());
    printMatrix(augMat);
    vector<double> result=solve(augMat);
    printResult(result);
    return 0;
}