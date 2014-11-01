#include "myvector.h"

int main(){
	myvector<int> v1;
	int a,b,c,d;
	cout<<"enter 4 int val"<<endl;
	cin>>a>>b>>c>>d;
	v1<<(a);v1<<(b);
	cout<<"display"<<endl;
	v1.display();
	myvector<int> v2(v1);
	myvector<int> v3;
	v2<<(c);
	v3<<(d);v3<<(v2);
    v3.display();
	cout<<"size compare :"<<endl;
	if(v3 >=v2)cout<<"v3 is greater/equal "<<endl;
	else cout<<"v3 is less than v2"<<endl;
	v3=v2;
	cout<<"enter value to check member"<<endl;
	int e;cin>>e;
	if(v3.ismember(e))cout<<e<<" is a mem of v3"<<endl;
	else cout<<e<<" isnt a member of v3"<<endl;
    cout<<"index :  v3[2]   "<<v3[2]<<endl;
    
	/*myvector<pair> prd;
	prd=v2*v3;
	prd.display_pair();
	*/
}
