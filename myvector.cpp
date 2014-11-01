
#include "myvector.h"

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
	
	
	
