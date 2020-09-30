#include<iostream>
using namespace std;
class sjf
{
  public:
  	int flag,at,bt,ct,tat,wt,n,pid;
  	void algo();
};

int main()
{
	sjf o;
	o.algo();	
}

void sjf::algo()
{
	sjf a[10];
    cout<<"enter the number of processes \n";
    cin>>n;
    cout<<"enter PID , AT , BT for each one\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i].pid>>a[i].at>>a[i].bt;
		a[i].flag=0;
	}
    for(int i=0;i<n;i++)
    	for(int j=0;j<n-i-1;j++)
    	{ 
    		if(a[j].at>a[j+1].at)
    		{
    	        sjf t;
    	  		t=a[j];
    	  		a[j]=a[j+1];
    	  		a[j+1]=t;
    	  	}
    	}
	a[0].flag=1;
	int c=a[0].ct=a[0].at+a[0].bt;
	int min,k=n-1,f=0,j=1;
	sjf b[n];
	b[0]=a[0];
	while(k>0)
	{
		int x;
	   for(int i=1;i<n;i++)
	   	if(a[i].flag==0)
	   	{
	        min=x=i;
	        break;
	    }
	   f=0;
	   for(int i=1;i<n;i++)
	   {
		if(a[i].at<=c && a[i].bt<a[min].bt && a[i].flag!=1)
		{
			min=i;
			f=1;
		}
	   }
	   if(min==x)
	   {
	   	    for(int i=min;i<n;i++)
	   	    	if(a[i].flag==0 && a[i].at==a[min].at && a[i].bt<a[min].bt)
	   	    		min=i;
	   	    f=1;
	   }
	   if(f==1 && a[min].flag!=1)
	   	{
	   		if (a[min].at>c)	
	   		  a[min].ct=c=a[min].at+a[min].bt;
	   		else
	   		a[min].ct=c=c+a[min].bt;
	   		a[min].flag=1;
	   		b[j]=a[min];
	   		j++;
	   		k--;
	   	}

	}

	cout<<"PID\t"<<"AT\t"<<"BT\t"<<"WT\t"<<"TAT\t"<<"CT\n";
	for(int i=0;i<n;i++)
	{
		b[i].tat=b[i].ct-b[i].at;
		cout<<b[i].pid<<"\t"<<b[i].at<<"\t"<<b[i].bt<<"\t"<<b[i].tat-b[i].bt<<"\t"<<b[i].tat<<"\t"<<b[i].ct<<endl;
	}
}
