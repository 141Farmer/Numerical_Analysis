#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double fx(double x)
{
    return sin(x); 
}
double bissection(double ub,double lb)
{
    if((fx(ub)) * (fx(lb)) >0) return -1e9;
    double x=(ub+lb)/2;
    while((abs(fx(x)-1e-6)) > 0)
    {
        if(fx(x)<0) lb=x;
        else ub=x;
        x=(ub+lb)/2;
    }
    return x;
}
double false_position(double ub,double lb)
{
    if((fx(ub)) * (fx(lb)) >0) return -1e9;
    double x= (ub*fx(lb)-lb*fx(ub)) / (fx(lb)-fx(ub));
    while(abs(fx(x))>1e-9)
    {
        if(fx(x)<0) lb=x;
        else ub=x;
        x=(ub*fx(lb)-lb*fx(ub)) / (fx(lb)-fx(ub));
    }
    return x;


}
int main()
{
    cout<<fixed<<setprecision(9)<<false_position(1.3,-1.4)<<endl;

}