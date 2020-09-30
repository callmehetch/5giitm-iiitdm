#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
class hrrn
{
public:
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int completed;
	hrrn()
	{
		completed = 0;
	}
};
int n,ab;
bool compare(hrrn i1,hrrn i2)
{
	return i1.bt < i2.bt && i1.at <= ab;
}

int main()
{
	float sum=0,temp;
	int sum_bt=0,loc,t;
	cout<<"Enter the number of processes : ";
	cin>>n;
	hrrn list[n];
	cout<<"Enter the arrival time and burst time : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\nProcess "<<i+1<<" :\n";
		list[i].pid=i;
		cout<<"Arrival time : ";
		cin>>list[i].at;
		cout<<"Burst time : ";
		cin>>list[i].bt;
		sum_bt += list[i].bt;
	}
	for(t = list[0].at;t<sum_bt;)
	{
		cout<<"The value of t at start :"<<t<<"\n";
		float hrr = -9999;
		for(int i=0;i<n;i++)
		{
			cout<<"Element considered "<<list[i].pid<<"\n";
			cout<<"List[0] completed = "<<list[0].completed<<"\n";
			if(list[i].at <=t && list[i].completed != 1)
			{
				cout<<"Element taken into consideration : "<<list[i].pid<<"\n";
				temp = (list[i].bt + (t - list[i].at)) / list[i].bt;
				if(hrr < temp)
				{
					hrr = temp;
					loc = i;
				}
			}
		}
		cout<<"Process chosen : "<<list[loc].pid<<"\n";
		if(list[loc].completed!=1)
		{
			t += list[loc].bt;
			cout<<"Time taken so far : "<<t<<"\n";
			list[loc].ct = t;
			list[loc].wt = t - list[loc].at - list[loc].bt;
			list[loc].tat = t - list[loc].at;
			list[loc].completed = 1;
		}
		else
			t += 1;
		for(int i=0;i<n;i++)
			cout<<list[i].completed<<" ";
		cout<<"\n";
	}
	cout<<"HRRN implementation of scheduling\n";
	cout<<"Pid\tAT\tBT\tCT\tTAT\tWT\n";
	for(int i=0;i<n;i++)
	{
		cout<<list[i].pid<<" ";
		cout<<"\t"<<list[i].at<<" ";
		cout<<"\t"<<list[i].bt<<" ";
		cout<<"\t"<<list[i].ct<<" ";
		cout<<"\t"<<list[i].tat<<" ";
		cout<<"\t"<<list[i].wt<<" ";
		cout<<"\n";
		sum+=list[i].wt;
	}
	cout<<"Average waiting time : "<<sum/n<<"\n";
}
