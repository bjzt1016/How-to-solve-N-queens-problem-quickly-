#include<iostream>
#include<cstdio> 
#include<cstdlib>
#include<cmath>
#include <ctime> 

const int MAX=1000;
using namespace std;

int n;
int x[MAX];
int y[MAX];//记录结果
int flag;
//用于验证位置合法性 
bool place(int k){
	for(int j=1;j<k;j++){
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	}	
	return true;
}
//随机产生stopVegas个合法的位置 
bool queenLV(int stopVegas){
	int k=1;
	int count=1;
	srand((unsigned)time(NULL));
	while((k<=stopVegas)&&(count>0)){
		count=0;
		int j=0;
		for(int i=1;i<=n;i++){
			x[k]=i;
			if(place(k))
				if((rand()%++count)==0)  //随机
					j=i;
		}
		if(count>0) 
			x[k++]=j;
	}
	return (count>0);  //如果count==0表明没有找到合适的位置
}
//将剩下的位置用回溯法完成 
void backtrack(int t){
	int i;
	if(t>n){
		for(i=1;i<=n;i++)
			y[i]=x[i];
		flag=1;
	}
	else{
		for(i=1;i<=n;i++){
			if(flag==1)
			return;
			x[t]=i;
			if(place(t))
				backtrack(t+1);
		}
	}
}
//验证答案是否正确 
/*bool check_ans(int n){
	int flag=0;
	for(int i=1;i<=n;i++)
	    x[i]=y[i];
	for(int i=1;i<=n;i++)
	    if(!place(x[i])){
		    flag=1;
		    break;
	    }	
	if(flag)
	    return false;
	return true;        
}*/ 
int main(){
	while(cin>>n){
		int i;
		for(i=0;i<=n;i++){
		    x[i]=0;
			y[i]=0;
		}
		int stop;
		cin>>stop;
        flag=0;
		int time1=time(0);
		while(1){
		    while(!queenLV(stop) );
		    backtrack(stop+1);
		    if(flag==1)
		    break;
		}
		int time2=time(0);
	    cout<<"running time:"<<time2-time1<<endl;
		for(i=1;i<=n;i++){
			cout<<y[i]<<endl;  
		}
		//cout<<check_ans(n)<<endl;
	}
	return 0;
}

