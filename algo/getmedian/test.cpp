#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#include "mymedian.h"
using namespace std;
template <class T>
void getMedian(vector<T>& vdatas,int k,int m)//读取一个数组中每个数的前k个数前第m个小的数
{
	vector<T> vdata;
	for(int i=0;i!=k;i++)
	{
		vdata.push_back(vdatas[i]);
	}
	MyMedian<T> mymedian;
	mymedian.makeHeap(vdata,m);//初始化
	cout<<"The median is:";
	cout<<mymedian.getMedian()<<endl;//获取第1+k/2小的数
	cout<<"heap ok!"<<endl;
	for(int i=k;i!=vdatas.size();++i)
	{
		T removed=mymedian.removeItem(vdatas[i-k]);//删除数
		cout<<"removed:"<<removed<<endl;
		cout<<"add:"<<vdatas[i]<<endl;
		mymedian.addItem(vdatas[i]);//添加数
		cout<<"The median is:";
		cout<<mymedian.getMedian()<<endl;
	}
}
int main()
{
	double idatas[]={2.4,3.5,5,2,5.0,67,12.4,657,34.7,1,1.0,2,2.6,4,5,3.3,6,8,5};
	vector<double> vdatas(idatas,idatas+19);
	for(int i=0;i!=vdatas.size();++i)
	{
		cout<<" "<<vdatas[i];
	}
	cout<<endl;
	int k=6;
	getMedian(vdatas,k,k/2);
	cout<<"all is done!"<<endl;
	return 0;
}
