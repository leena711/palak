#include <iostream>
using namespace std;

/*
template <class T>
class pair{
	public: 
	T a,b;
};
* */

template <class T>
class myvector{
protected:
	T* array;
	int count;
public:
	myvector();
	myvector (myvector<T> &);
	virtual myvector &operator = (myvector<T>&);
	virtual myvector &operator <<(T&);
	virtual myvector &operator <<(myvector<T> &);
	virtual T &operator [](int);
	virtual bool operator <(myvector<T> &);
	virtual bool operator >(myvector<T> &);
	virtual bool operator <=(myvector<T>&);
	virtual bool operator >=(myvector<T>&);
	virtual int size();
	virtual bool ismember(T&);
	virtual void display();
	//void display_pair();
	//myvector<T>& operator *(myvector<T>&);
	
};


template <class T>
myvector<T>::myvector(){
	array =new T[0];count=0;
	}
	
template <class T>	
myvector<T>::myvector(myvector<T> &v){
	count=v.count;
	array=new T[count];
	for(int i=0;i<count;i++){
		array[i]=v.array[i];
	}
}
template <class T>
myvector<T>& myvector<T>::operator= (myvector<T> &v){
	delete array;
	count=v.count;
	array=v.array;
	return *this;
	
}
template <class T>
myvector<T>& myvector<T>::operator <<(T &t){
	T* tmp=new T[count+1];
	for(int i=0;i<count;i++){
		tmp[i]=array[i];
	}
	tmp[count]=t;
	delete array;
	array=tmp;
	count++;
	return *this;
	
}
template <class T>
myvector<T>& myvector<T>::operator <<(myvector<T> &v){
    int s=count+v.count;
    T* tmp=new T[s];
    for(int i=0;i<count;i++){
		tmp[i]=array[i];
	}
	for(int i=0;i<v.count;i++){
		tmp[i+count]=v.array[i];
	}
	array=tmp;
	count=s;
	return *this;
}
template <class T>
T& myvector<T>::operator [](int k){
	return array[k];
}
template <class T>
bool myvector<T>::operator <(myvector<T>  &v ){
	if (count< v.count)return true;
	else return false;
}

template <class T>
bool myvector<T>::operator >(myvector<T>  &v){
	if (count> v.count)return true;
	else return false;
}

template <class T>
bool myvector<T>::operator <=(myvector<T>  &v){
	if (count<= v.count)return true;
	else return false;
}

template <class T>
bool myvector<T>::operator >=(myvector<T> &v){
	if (count>= v.count)return true;
	else return false;
}

template <class T>
int myvector<T>::size(){return count;}

template <class T>
bool myvector<T>::ismember(T &t){
	for(int i=0;i<count;i++){
		if(array[i]==t)return true;
	}
	return false;
}

template <class T>
void myvector<T>::display(){
	for(int i=0;i<count;i++){
		cout<<i+1<<". "<<array[i]<<endl;
	}
}
/*
template <class T>
myvector<T>& myvector<T>::operator*(myvector<T> &v){
	
	
	myvector<pair> product;
	pair p;
	for(int i=0;i<count;i++){
		for(int j=0;j<v.count;j++){
			p.a=array[i];p.b=v.array[j];
			product<<(p);
		}
	}
	product.count=count*v.count;
	
	return product;
}

template<class T>
void myvector<T>::display_pair(){
	for(int i=0;i<size;i++){
		cout<<"( "<<array[i].a<<", "<<array[i].b<<endl;
	}
}
*/	
	
	
	
/*
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
	
}
*/
