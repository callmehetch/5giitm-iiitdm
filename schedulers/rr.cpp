#include <bits/stdc++.h>
using namespace std;

struct gannt
{
	int pid;
	int st;
	int et;
	int rt;
};
struct process
{
	int pid;
	int at;
	int bt;
	int obt;

};
bool comp(process p1,process p2)
{
	return (p1.at<p2.at);
}
bool check(vector<process> v,int n)
{
	int flag = 1;
	for(auto itr=v.begin();itr!=v.end();itr++)
	{
		if(itr->bt!=0)
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		return true;
	return false;

}
bool notin(vector<int > arr,int query)
{
	for(auto itr=arr.begin();itr!=arr.end();itr++)
	{
		if(*itr==query)
			return false;
	}
	return true;
}
int getat(int pid, vector<process> p)
{
	for(auto itr=p.begin();itr!=p.end();itr++)
	{
		if(itr->pid==pid)
		{
			return(itr->at);
		}
	}
}
int getbt(int pid, vector<process> p)
{
	for(auto itr=p.begin();itr!=p.end();itr++)
	{
		if(itr->pid==pid)
		{
			return(itr->obt);
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the number of processes : ";
	cin>>n;
	cout<<"Enter the time quanta : ";
	int tq;
	cin>>tq;
	vector<process> p(n);
	cout<<"Enter the arrival time and burst time : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\nProcess "<<i+1<<" :\n";
		p[i].pid=i;
		cout<<"Arrival time : ";
		cin>>p[i].at;
		cout<<"Burst time : ";
		cin>>p[i].bt;
		p[i].obt = p[i].bt;
	}
	queue<int> q;
	bool c;
	sort(p.begin(),p.end(),comp);
	int temp=-1;
	gannt gvar;
	vector<gannt> v;
	vector<int > pidsinq;
		int t=(p.begin())->at;
		int flag;
	do{

	for(auto itr=p.begin();itr!=p.end();itr++)
	{
		flag = 0;
		if(itr->at<=t && notin(pidsinq,itr->pid) )
		{
			flag=1;
			q.push(itr->pid);
			pidsinq.push_back(itr->pid);
		}
	}

	if(temp>=0 )
	{
		q.push(temp);
	}
	if(!q.empty())
	{
	temp=q.front();
	q.pop();
	}
	if(flag==0 && q.empty() && temp==-1)
	{
		t++;
	}
	for(auto itr=p.begin();itr!=p.end();itr++)
	{
		if(itr->pid==temp)
		{
			gvar.pid=temp;
			gvar.st=t;
			if(itr->bt>tq)
			{
				gvar.et = gvar.st+tq;
				itr->bt-=tq;
				t+=tq;
				gvar.rt=itr->bt;
				v.push_back(gvar);
			}
			else if(itr->bt>0)
			{
				gvar.et = gvar.st+itr->bt;

				t+=itr->bt;
				itr->bt=0;
				temp=-1;
				gvar.rt=itr->bt;
				v.push_back(gvar);
			}
		}
	}
	 c = check(p,n);
	}while(!c);
cout<<"Round robin implementation of scheduling\n";
cout<<"AT\tBT\tCT\tTAT\tWT\n";
int tat,wt;
float avg=0;
for(auto itr=v.begin();itr!=v.end();itr++)
{
	if(itr->rt!=0)
	{
		//cout<<itr->pid<<"\t"<<itr->st<<"\t"<<itr->et<<"\t"<<itr->rt<<endl;
	}
	else
	{
		tat = itr->et-getat(itr->pid,p);
		wt = tat - getbt(itr->pid,p);
		cout<<itr->pid<<"\t"<<itr->st<<"\t"<<itr->et<<"\t"<<itr->rt<<"\t"<<tat<<"\t"<<wt<<endl;
		avg+=wt;
	}

}
cout<<"Average waiting time = "<<avg/n<<endl;

}
