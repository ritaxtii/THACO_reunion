#include <bits/stdc++.h>

using namespace std;
typedef long long int t;
typedef long double fl;

fl finddt(t x1,t y1,t x2,t y2)
{
    fl dt=sqrt((pow(x1-x2,2))+pow(y1-y2,2));
    return dt;
}

int main()
{
    t n,m;
    t br=0;
    cin>>n>>m;
    t a[n][2]={},b[m][4]={};
    for(t i=0; i<n; i++)
    {
        for(t j=0; j<2; j++)
        {
            cin>>a[i][j];
        }
    }
    for(t i=0; i<m; i++)
    {
        for(t j=0; j<3; j++)
        {
            cin>>b[i][j];
            b[i][3]=b[i][2];
            if(abs(b[i][0])+b[i][2]==1e9||abs(b[i][1])+b[i][2]==1e9){
                br++;
            }

        }
    }
    for(t i=0; i<n; i++)
    {
        for(t j=0; j<m; j++)
        {
            if(b[j][2]!=0)
            {
                if(finddt(a[i][0],a[i][1],b[j][0],b[j][1])<(fl)b[j][2])
                {
                    br++;
                    b[j][2]=0;
                }
            }
        }
    }
    t al=0;
    for(t j=0; j<m; j++)
    {
        for(t i=0; i<n; i++)
        {
            if(finddt(a[i][0],a[i][1],b[j][0],b[j][1])<(fl)b[j][3])
            {
                al=1;
            }
            else
            {
                al=0;
                break;
            }
        }
        if(al==1)
        {
            br--;
        }
    }
    cout<<br;
    return 0;
}
