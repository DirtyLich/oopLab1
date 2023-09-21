#include<iostream>
#include<conio.h>

#define n 5

using namespace std;

int main()
{
    int k,j,i;
    int imin,jmin,imax,jmax;
    int a[n][n];
    jmin=0;
    imin=1;
    jmax=n-1;
    imax=n-1;
    k=0;
   do
        {
                for(i=imin;i<=imax;i++)  //pervii stolbec
                {
                        k++;
                        a[i][jmin]=k;
                }
                jmin++;
                for(j=jmin;j<=jmax;j++)  //posledniaia stroka
                {
                        k++;
                        a[imax][j]=k;
                }
                imax--;
                for(i=imax;i>=imin;i--)  //poslednii stolbec
                {
                        k++;
                        a[i][jmax]=k;
                }
                jmax--;             
                for(j=jmax;j>=jmin;j--) //pervaia stroka
                {
                        k++;
                        a[imin][j]=k;
                }
                imin++;                                
                }
        while (k<25);
    for(j=0;j<n;j++)
    {
    cout<<a[0][j]<<"  ";
    }
    cout<<endl;
    for(i=1;i<n;i++) 
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
            cout<<endl;
    }
}