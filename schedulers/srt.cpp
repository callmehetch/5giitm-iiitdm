#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
class srt
{
	public:
		int pid;
		int at;
		int bt;
		int ct;
		int tat;
		int wt;
};
int n;
bool compare(srt i1,srt i2)
{
	return i1.at < i2.at;
}
int main()
{
	float sum=0;
	cout<<"Enter the number of processes : ";
	cin>>n;
	srt list[n];
	cout<<"Enter the arrival time and burst time : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\nProcess "<<i+1<<" :\n";
		list[i].pid=i;
		cout<<"Arrival time : ";
		cin>>list[i].at;
		cout<<"Burst time : ";
		cin>>list[i].bt;
	}
	sort(list,list+n,compare);
	int rt[n];
	for (int i = 0; i < n; i++)
      	rt[i] = list[i].bt;
	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;
	while(complete != n)
	{
		for(int j=0;j<n;j++)
		{
			if((list[j].at <=t) && (rt[j] < minm))
			{
				if(rt[j] > 0)
				{
					minm = rt[j];
					shortest = j;
					check = true;
				}
			}
		}
		if(check == false)
		{
			t++;
			continue;
		}
		rt[shortest]--;
		minm = rt[shortest];
		if(minm ==0)
			minm = INT_MAX;
		if(rt[shortest]==0)
		{
			complete++;
			check = false;
			finish_time = t+1;
			list[shortest].wt = finish_time - list[shortest].bt - list[shortest].at;
			list[shortest].ct = finish_time;
			if(list[shortest].wt < 0)
				list[shortest].wt = 0;
		}
		t++;
	}
	for (int i = 0; i < n; i++)
      	list[i].tat = list[i].bt + list[i].wt;
	cout<<"SRT implementation of scheduling\n";
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
