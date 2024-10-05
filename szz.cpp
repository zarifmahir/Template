#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
int x[16];
int y[16];
double s[16];
int dis_arr[16];
double dist(int x1,int y1,int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
int n,t;
cin>>n;
t=n;
int i=0;
while(t--)
{   i++;
    
    cin>>x[i]>>y[i]>>s[i];
}
dis_arr[1]=dist(x[1],y[1],0,0);
for(int i=2;i<=n;i++)
{
    dis_arr[i]=dist(x[i],y[i],x[i-1],y[i-1]);
}
int m;
cin>>m;

double sum=dis_arr[1];
for(int i=2;i<=n;i++)
{
    sum+=(dis_arr[i]/m);
    m*=m;

}
double hi=s[1],lo=0,v_prev,v_cur;
v_prev=0;
v_cur=0;
while(1)
{
    double mid=(hi+lo)/2;
    v_prev=v_cur;
    v_cur=dis_arr[0]/mid; 
    if(fabs(v_cur-v_prev)<1e-3)
    {
        break;
    }
    if((sum/v_cur) >s[n])
    {
        lo=mid;
    }
    else{
        hi=lo;
    }

    
}

cout<<v_cur;
}
