#include <iostream>
#include <ctime>
#include <vector>
using std::vector;


vector<double> RandomPoint (vector<double>& a,vector<double>& b)
{
    vector<double> Point;
    srand(time(0));
    double t=(static_cast<double>(rand())/RAND_MAX)*2000-1000;
    double m=(static_cast<double>(rand())/RAND_MAX)*2000-1000;
    for(int i=0; i < a.size(); i++)
    {
        Point.push_back(a[i]*t+b[i]*m);
    }
    return Point;
} 
// debag print
int main()
{
    vector<double> r;
    vector<double> a {5,6,3,7};
    vector<double> b {4,2,5,4};
    vector<double> P = RandomPoint(a,b);
    for(int i=0; i < a.size(); i++)
    {
    std::cout<<P[i]<<std::endl;
    }
}