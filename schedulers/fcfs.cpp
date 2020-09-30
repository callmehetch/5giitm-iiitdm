#include<iostream>

using namespace std;

 struct list
{
 int ro;
 int at;
 int bt;
 int ct;
 int tat;
 int wt;

};

 struct list a[4];

 int main()
{
 for(int i=0;i<4;i++)
{

 cout<<"enter the process id \n";
 cin>>a[i].ro;
 cout<<"enter the arrival time \n";
 cin>>a[i].at;
 cout<<"enter the burst time \n";
 cin>>a[i].bt;
}
 int i,j;

 int n=4;

 struct list x;
 for (i = 0; i < n-1; i++)      
 
{      
 for (j = 0; j < n-i-1; j++) 
 if (a[j].at > a[j+1].at)
{
 x=a[j];
 a[j]=a[j+1];
 a[j+1]=x;
}
}
 int totwt=0;
 for(i=0;i<4;i++)
{

 if(i==0)
{
 a[0].ct=a[0].bt+a[0].at;}
 else

{
 if(a[i].at>a[i-1].ct)
 a[i].ct=a[i].at + a[i].bt;
 else
 a[i].ct=a[i-1].ct+a[i].bt;

 a[i].tat=a[i].ct-a[i].at;
 a[i].wt=a[i].tat-a[i].bt;
 totwt+=a[i].wt;
}
}
 float avg= (float) totwt/4.0;
 for(i=0;i<4;i++)
{
 cout<<a[i].ro<<" ";
 cout<<a[i].at<<" ";
 cout<<a[i].bt<<" ";
 cout<<a[i].ct<<" ";
 cout<<a[i].tat<<" ";
 cout<<a[i].wt<<endl;
}
 cout<<"avg waiting time="<<avg;
 return(0);
}
