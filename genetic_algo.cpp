#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;
void print(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
}
void galgo(int [],int [],int [],int [],int [],int [],int,int [],int);
void crossover(int a[],int n,int b[],int m){
	int temp=0;
	int p=rand()%5;
	for(int i=0;i<p;i++){
		int pos=rand()%n+1;
		temp=a[pos];
		a[pos]=b[pos];
		b[pos]=temp;
	}
}
void mutation(int a[],int n,int nos){
	int k1,k2;
	for(int i=0;i<nos;i++){
		k1=rand()%n;
		k2=rand()%n;
		a[k1]=a[k2];
	}
} 
void calculate_feetness(int parent[],int n,int child[],int group){
	int temp[n+1],total=0;
	for(int i=0;i<n;i++){
		temp[i]=child[i];
	}
	int maximum=0,minimum=0,maxx=0,minn=10000,flagmax=0,flagmin=0,l=0,m=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(temp[i]!=-1&&temp[i]==temp[j]){
				if(parent[i]>parent[j]){
					maxx=parent[i];
					temp[j]=-1;
					flagmax=1;
				}
				else if(parent[i]<parent[j]){
					minn=parent[i];
					temp[j]=-1;
					flagmin=1;
				}	
			}
		}
		if(flagmax==1&&flagmin==1){
			total=total+(maxx-minn);
		}
		else if(flagmax==1&&flagmin==0){
			total=total+maxx;
		}
		if(flagmin==1&&flagmax==0){
			total=total+minn;
		}
		flagmax=0;
		flagmin=0;
	}
	child[n]=total;
}
void best_generation(int g1[],int g2[],int g3[],int g4[],int g5[],int g6[],int n,int sort[]){
	int temp=0;
	sort[0]=g1[n];
	sort[1]=g2[n];
	sort[2]=g3[n];
	sort[3]=g4[n];
	sort[4]=g5[n];
	sort[5]=g6[n];	
	for(int i=0;i<n+1;i++){
		for(int j=i+1;j<n+1;j++){
		if(sort[i]>sort[j]){
			temp=sort[i];
			sort[i]=sort[j];
			sort[j]=temp;
		}
		}
	}
	for(int i=0;i<3;i++){
		if(sort[i]==g4[n]){
			for(int j=0;j<n;j++){
				g1[i]=g4[i];	
			}
		}
		else if(sort[i]==g5[n]){
			for(int j=0;j<n;j++){
				g2[i]=g5[i];	
			}
		}
		if(sort[i]==g6[n]){
			for(int j=0;j<n;j++){
				g3[i]=g6[i];	
			}
		}
	}
} 
void print_feetness(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
} 
void printgropu(int a[],int g[],int n,int no_group){
	
	int temp[n],k=1;
	cout<<"\n\ng1[] is : \n";
	for(int i=0;i<n;i++){
		temp[i]=g[i];
		cout<<g[i]<<" ";
	}
	cout<<"\n";
	cout<<"\n\nai[] is : \n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\nmain gropus : \n";
	int flag=0;
	int i=0,j=0;
	int group[n],t=0;
	for(i=0;i<n-1;i++){
		if(temp[i]!=-1){
			if(flag!=1){
				group[t++]=a[i];
				flag=1;
				}
		for(j=i+1;j<n;j++){
			if(temp[i]==temp[j]&&temp[j]!=-1){
				group[t++]=a[j];
				temp[j]=-1;
			}
		}
		flag=0;
		}
	}
	cout<<"\n";
	int p=1;
	cout<<"group "<<p<<" -- ";
	for(i=0;i<t;i++){
		cout<<group[i]<<" ";
		if(g[i]!=g[i+1]&&i!=n-1){
		cout<<"\n";
		p++;
		cout<<"group "<<p<<" -- ";}
	}
}
void replace(int g[],int n,int g1[],int g2[],int g3[],int kth){
	if(kth==0){
		for(int i=0;i<n;i++){
				g[i]=g1[i];
		}
	}
	if(kth==1){
		for(int i=0;i<n;i++){
				g[i]=g2[i];
		}
	}
	if(kth==2){
		for(int i=0;i<n;i++){
				g[i]=g3[i];
		}
	}
}
int main()
{
	int n,m,k,i=0,j=0,kg;
	n=5;
	//cin>>n;
	m=1;
	kg=2;
	//cin>>kg;
	int t=3;
	int same[n];
	int a[i];
	srand(time(0));
	for(i=0;i<n;i++){
		//cin>>a[i];
		k=rand()%50;
		a[i]=k;
	}
	int g1[n+1];
	int g2[n+1];
	int g3[n+1];
	int g4[n+1];
	int g5[n+1];
	int g6[n+1];
	for(j=1;j<=t;j++){
	for(i=0;i<n;i++){
		k=rand()%kg;
		if(j==1){
		g1[i]=k;
		g4[i]=k;
		}
		else if(j==2){
			g2[i]=k;
			g5[i]=k;
		}
		if(j==3){
			g3[i]=k;
			g6[i]=k;
		}
	}
	}
	galgo(g1,g2,g3,g4,g5,g6,n,a,kg);
}
void galgo(int g1[],int g2[],int g3[],int g4[],int g5[],int g6[],int n,int a[],int kg)
{
	int k;
	cout<<"1st g \n";
	print(g1,n);
	cout<<"2nd g \n";
	print(g2,n);
	cout<<"3rd g \n";
	print(g3,n);
	k=rand()%6+1;
	//cout<<k;
	while(k--)
	{
		int k1=rand()%4;
		int k2=rand()%4;
		int sum=k1+k2;
		if(sum<4)
		crossover(g1,n,g2,n);
		else if(sum==4)
		crossover(g2,n,g2,n);
	}
	cout<<"\nAfter crossover \n";
		cout<<"1st g \n";
	print(g1,n);
	cout<<"2nd g \n";
	print(g2,n);
	cout<<"3rd g \n";
	print(g3,n);
	int iter=4;
	while(iter--){
		k=rand()%6;
		while(k--){
			int k1=rand()%n+1;
			int k3=rand()%4;
			if(k3==1||k3==0)
			mutation(g1,n,k1);
			else if(k3==2)
			mutation(g2,n,k1);
			if(k3==3)
			mutation(g3,n,k1);
		}
		cout<<"\nMutation \n";
			cout<<"1st g \n";
		print(g1,n);
		cout<<"2nd g \n";
		print(g2,n);
		cout<<"3rd g \n";
		print(g3,n);
		calculate_feetness(a,n,g1,kg);
		calculate_feetness(a,n,g2,kg);
		calculate_feetness(a,n,g3,kg);
		calculate_feetness(a,n,g4,kg);
		calculate_feetness(a,n,g5,kg);
		calculate_feetness(a,n,g6,kg);
		int sort[6];
		best_generation(g1,g2,g3,g4,g5,g6,n,sort);
		for(int i=0;i<kg;i++){
			if(sort[i]==g4[n]){
				replace(g4,n,g1,g2,g3,i);
			}
			if(sort[i]==g5[n]){
				replace(g5,n,g1,g2,g3,i);
			}
			if(sort[i]==g6[n]){
				replace(g6,n,g1,g2,g3,i);
			}
		}
		cout<<"\n";
		if(sort[0]==g1[n]){
			printgropu(a,g1,n,kg);
		}
		if(sort[0]==g2[n]){
			printgropu(a,g2,n,kg);
		}
		if(sort[0]==g3[n]){
			printgropu(a,g1,n,kg);
		}
		if(sort[0]==g4[n]){
			printgropu(a,g1,n,kg);
		}
		if(sort[0]==g5[n]){
			printgropu(a,g2,n,kg);
		}
		if(sort[0]==g6[n]){
			printgropu(a,g1,n,kg);
		}
	}
}

