#include<iostream>
#include<algorithm>
using namespace std;
class pnpe
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
bool compareAT(pnpe i1,pnpe i2)
{
	return i1.at < i2.at;
}
bool compare(pnpe i1,pnpe i2)
{
		return i1.priority > i2.priority;
}
int main()
{
	float sum=0;
	cout<<"Enter the number of processes : ";
	cin>>n;
	pnpe list[n];
	cout<<"Enter the arrival time and burst time : ";
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
	sort(list,list+n,compareAT);
	for(int i=0;i<n;i++)
	{
		int j=i+1;
		while(list[i].at == list[j].at)
			j++;
		sort(list+i,list+j,compare);
	}
	list[0].ct=list[0].at+list[0].bt;
	list[0].tat=list[0].ct-list[0].at;
	sort(list+1,list+n,compare);
	for(int i=1;i<n;i++)
	{
		list[i].ct=list[i].bt+list[i-1].ct;
		if(list[i-1].ct < list[i].at)
			list[i].ct += (list[i].at-list[i-1].ct);

	}
	for(int i=1;i<n;i++)
	{
		list[i].tat=list[i].ct-list[i].at;
		list[i].wt=list[i].tat-list[i].bt;
	}
	list[0].wt=0;
	cout<<"Priority NPE implementation of scheduling\n";
	cout<<"Pid\tAT\tBT\tCT\tTAT\tWT\tPriority\n";
	for(int i=0;i<n;i++)
	{
		cout<<list[i].pid<<" ";
		cout<<"\t"<<list[i].at<<" ";
		cout<<"\t"<<list[i].bt<<" ";
		cout<<"\t"<<list[i].ct<<" ";
		cout<<"\t"<<list[i].tat<<" ";
		cout<<"\t"<<list[i].wt<<" ";
		cout<<"\t"<<list[i].priority<<" ";
		cout<<"\n";
		sum+=list[i].wt;
	}

	cout<<"Average waiting time : "<<sum/n<<"\n";
}
