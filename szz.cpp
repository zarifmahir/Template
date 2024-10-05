#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
double x[16];
double y[16];
double s[16];
double dis_arr[16];
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
for(int j=2;j<=n;j++)
{
    dis_arr[j]=dist(x[j],y[j],x[j-1],y[j-1]);
   
}


double m;
cin>>m;

double sum=dis_arr[1];
for(int j=2;j<=n;j++)
{
    sum+=(dis_arr[j]/m);
    m*=m;

}

double hi=s[1],lo=0,v_prev,v_cur;
v_prev=0;
v_cur=0;
double brk=1.0/1000;
while(1)
{
    double mid=(hi+lo)/2.0;
    v_prev=v_cur;
    v_cur=dis_arr[1]/mid; 
   cout<<v_cur<<" "<<v_prev<<endl;
    if(fabs(v_cur-v_prev)<brk)
    {
        break;
    }
    if((sum/v_cur) >s[n])
    {
        lo=mid;
    }
    else{
        hi=mid;
    }

    
}

cout<<v_cur;
}
