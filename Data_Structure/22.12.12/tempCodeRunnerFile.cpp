#include<iostream>
using namespace std;
int main(){
	int t,n;
	int i,j,k,flag;
	int a[20]={0};
	int b[20]={0};
	cin>>t;
	n=t*(t-1)*(t-2);
	for(int g=0;g<n;g++){
		cin>>i>>j>>k>>flag;
		if(flag==1){
			a[k]++;//记下有效信息中的k节点出现次数
			b[k]=j;
		}
	}
	int temp=0,id=0,sum=1;
	int c[t];
	for(int g=1;g<=t;g++){
		if(a[g]>a[temp]){//去除出现次数最多的
			temp=g;
		} 
	}
	for(int h=1;h<=t;h++){//查验该节点是否在孩子中出现
		if(temp==b[h]){
			sum=0;
		}
	}			
	if(sum==1){
		cout<<temp<<endl;
	}
	return 0;
}