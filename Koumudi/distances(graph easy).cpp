#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
  int t ;
  cin>>t;
  while(t--){
	int n;
	cin>>n;
	int f=1,i,a[n+1],b[n+1];
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	cin>>b[i];
	if(a[1]!=0||b[n]!=0||a[n]!=b[1])
	f=0;
	for(i=1;i<=n;i++){
	if(a[i]+b[i]<a[n])
	f=0;
    if((a[n]+b[i])<a[i])
    f=0;
    if((b[1]+a[i])<b[i])
    f=0;
	}
	if(f==1)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
 }
 return 0;	
}
