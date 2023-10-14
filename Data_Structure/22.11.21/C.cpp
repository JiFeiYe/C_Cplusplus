#include<iostream>
using namespace std;

int height(char *arr,int n){  //获得当前结点的高度
	if(arr[n] == '0') return 0;
	return height(arr,n*2+1)>height(arr,n*2+2) ? height(arr,n*2+1) + 1: height(arr,n*2+2) + 1;
}

void output(char *arr,int n){ // 后序输出高度差
	if(arr[n] == '0') return ;
	output(arr,n*2+1);
	output(arr,n*2+2);
	cout<<arr[n]<<" "<<height(arr,n*2+1) - height(arr,n*2+2)<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		char *arr;
		int n;
		cin>>n;
		int a = 2;
		while(a/2 < n){ 
			a*=2;
		} 
		arr = new char[a+3];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		for(int i = n; i < a; i++){
			arr[i] = '0';  //补全二叉树变成满二叉树 ,让判断时访问不会越界 
		}
		output(arr,0); 
	}
	return 0;
}
