
#include <string>

#include "myfile.cpp"



template<class T>
class set:public myvector<T>{
public:
    set();
    set<T> &operator<<(T&);
    set<T> operator<<(set<T>&);
    set<T> operator-(set<T>&);
    set<T>& I(set<T>&,set<T>&);
    set<T> &operator=(set<T>);
};

template <class T>
set<T>::set():myvector<T>(){};


template <class T>
set<T>& set<T>::I(set<T> &a,set<T> &b){
    int num=0;
    for(int i=0;i<a.size();i++){
        if(b.ismember(a.array[i])){
            (*this)<<(a.array[i]);
            num++;}
    }
    this->count=num;
    return *this;
}

template <class T>
set<T> set<T>::operator-(set<T>& b){
    set<T> res;
    
    for(int i=0;i<this->size();i++){
        if(b.ismember(this->array[i]))continue;
        else {res<<(this->array[i]);
            res.count++;
        }
    }
    
    return res;
}

template <class T>
set<T> set<T>::operator<<(set<T> &b){
    set<T> res;
    res.array=this->array;
    for(int i=0;i<b.size();i++){
        if(this->ismember(b.array[i]))continue;
        res<<b.array[i];
    }
    res.count=this->count+b.count;
    return res;
}

template <class T>
set<T>& set<T>::operator<<(T &val){
    T* tmp=new T[this->count +1];
    for(int i=0;i<this->count;i++){
        tmp[i]=this->array[i];
    }
    tmp[this->count]=val;
    // delete this->array;
    this->array=tmp;
    this->count++;
    return *this;
}

template <class T>
set<T>& set<T>::operator=(set<T> b){
   // delete array;
    this->array=b.array;
    this->count=b.count;
    return *this;
}





int main(){
    set<int> s1,s2,mix,inter,sub;
    cout<<"enter 2 char for s1"<<endl;
    int a,b,c,d;
    cin>>a>>b;
    s1<<a;s1<<b;s1.display();
    cout<<"enter 2 char for s2"<<endl;
    cin>>c>>d;
    s2<<c;s2<<d;
    //(s1<<s2).display();
    //(s1-s2).display();
    inter.I(s1,s2);
    mix= (s1<<s2);
    //inter = s1.I(s2);
    sub = (s1-s2);
    cout<<"union is :  "<<endl;mix.display();
    cout<<"intersection :"<<endl;
    if(inter.size()==0)cout<<"null"<<endl;
    else inter.display();
    cout<<"subtraction :"<<endl;sub.display();
    
}




