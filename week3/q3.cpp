#include <iostream>
#include <malloc.h>
#include <math.h>
using namespace std;

int sum;
int opcount;

void printSet(int *a,int x,int n){
	cout<<"Set1: ";
	for(int i=0;i<n;i++){
		if((x>>i)&1)
			cout<<a[i]<<" ";
	}
	cout<<"\nSet2: ";
	for(int i=0;i<n;i++){
		if(((~x)>>i)&1)
			cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void partition(int* a,int n){
	int total=pow(2,n-1);
	int val=0;
	for(int i=1;i<total;i++){
		int val=0;
		for(int x=0;x<n;x++){
			if((i>>x)&1){
				opcount++;
				val=val+a[x];
				if(val==(sum-val)){
					printSet(a,i,n);
					return;
				}	
			}
		}
	}
	cout<<"\nNo partition\n";
}



int main(int argc,char** argv){
	// cout<<argv[0];
	// string _filename=string(argv[0])+".csv";
	int T;
	cin>>T;
	FILE *fp=fopen("partition.csv","a");
    
	while(T--){
		opcount=0;
		int n;
		cout<<"size"<<endl;
		cin>>n;
		int *a=(int *)malloc(sizeof(int)*n);
		sum=0;
		cout<<"enter elements"<<endl;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum=sum+a[i];
		}
		partition(a,n);
		cout<<"\nOpCount"<<opcount<<"\n";
		fprintf(fp,"%d,%d\n",n,opcount);
	}

	return 0;
}