#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
class ppe
{
	public:
		int pid;
		int at;
		int bt;
		int ct;
		int tat;
		int wt;
		int priority;
};
int n;
bool compare(ppe i1,ppe i2)
{
	return i1.at < i2.at;
}
int main()
{
	float sum=0;
	cout<<"Enter the number of processes : ";
	cin>>n;
	ppe list[n];
	cout<<"Enter the arrival time, burst time and priority : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\nProcess "<<i+1<<" :\n";
		list[i].pid=i;
		cout<<"Arrival time : ";
		cin>>list[i].at;
		cout<<"Burst time : ";
		cin>>list[i].bt;
		cout<<"Priority : ";
		cin>>list[i].priority;
	}
	sort(list,list+n,compare);
	int rt[n];
	for (int i = 0; i < n; i++)
      	rt[i] = list[i].bt;
	int complete = 0, t = 0, maxm = INT_MIN;
	int highest = 0, finish_time;
	bool check = false;
	while(complete != n)
	{
		for(int j=0;j<n;j++)
		{
			if((list[j].at <=t) && (list[j].priority > maxm && rt[j] >0))
			{
				maxm = list[j].priority;
				highest = j;
				check = true;
			}
		}
		if(check == false)
		{
			t++;
			continue;
		}
		rt[highest]--;
		if(rt[highest]==0)
		{
			complete++;
			check = false;
			finish_time = t+1;
			list[highest].wt = finish_time - list[highest].bt - list[highest].at;
			list[highest].ct = finish_time;
			if(list[highest].wt < 0)
				list[highest].wt = 0;
			maxm = INT_MIN;
		}
		t++;
	}
	for (int i = 0; i < n; i++)
      	list[i].tat = list[i].bt + list[i].wt;
	cout<<"Priority PE implementation of scheduling\n";
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
}
