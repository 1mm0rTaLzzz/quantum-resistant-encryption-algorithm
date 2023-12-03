#include <iostream>
#include <ctime>
#include <vector>

using namespace std;
int main() {
    srand(time(0));
    vector<double> primal1;
    vector<double> primal2;
    for(int i=0; i < 10;)
    {
        int t=rand();
        int p=rand();
        primal1.push_back(t%10000);
        primal2.push_back(p%10000);
        i=1+i;
    }
    vector<double> a1;
    vector<double> a2;
    for(int i=0; i < 10;)
    {
        int t=rand();
        int p=rand();
        a1.push_back(t%10000);
        a2.push_back(p%10000);
        i=1+i;
    }
    vector<double> e1;
    vector<double> e2;
    for(int i=0; i < 10;)
    {
        e1[i]=a1[i]*primal1[i];
        e2[i]=a2[i]*primal2[i];
        i=i+1;
    }
    cout<<e1[1]<<endl;
    cout<<e1[2]<<endl;
    cout<<a2[1];
}