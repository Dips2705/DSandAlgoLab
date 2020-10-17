#include <iostream>
using namespace std;
int main(){
	int m,n,i,x,y,d,sum;
	cin>>m>>n;
	long long int a[m],b[n],min=0,max=0;
	for(i=0;i<m;i++){
	cin>>a[i];
	if(a[i]<a[min])
	min=i;
    } 
	for(i=0;i<n;i++){
    cin>>b[i];
    if(b[i]>b[max])
	max=i;
}
    for(i=0;i<m;i++){
    	cout<<i<<" "<<max<<endl;
        
    } 
       for(i=0;i<n;i++){
       	if(i!=max){
       	cout<<min<<" "<<i<<endl;
		   }
	   }

	return 0;
	
}
