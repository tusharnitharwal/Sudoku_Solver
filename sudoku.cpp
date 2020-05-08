#include<iostream>
#include<cmath>
using namespace std;

bool test(int a[][10], int i, int j, int n, int q)
{
    
    for(int k=0;k<n;k++)
    {
        if(k==i)
        {
            continue;
        }
        if(a[k][j]==q)
        {
            return false;
        }
    }
    for(int k=0;k<n;k++)
    {
        if(k==j)
        {
            continue;
        }
        if(a[i][k]==q)
        {
            return false;
        }
    }
    int root=sqrt(n);
    int sx=(i/root)*root;
    int sy=(j/root)*root;
    for(int k=sx;k<sx+root;k++)
    {
        for(int l=sy;l<sy+root;l++)
        {
            if(a[k][l]==q)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudo(int a[][10], int i, int j, int n)
{
    // cout<<"HI";
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==n)
    {
        // cout<<"LL";
        return sudo(a,i+1,0,n);
    }

    if(a[i][j]!=0)
    {
        return sudo(a,i,j+1,n);
    }
    for(int k=1;k<=9;k++)
    {
        
        if(test(a,i,j,n,k))
        {
            a[i][j]=k;
            if(sudo(a,i,j+1,n))
            {
                return true;
            }           
        }
    }
    a[i][j]=0;
    return false;
}

int main() {
    int n;
    cin>>n;
    int a[10][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    sudo(a,0,0,n);
    return 0;
}