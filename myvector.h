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
