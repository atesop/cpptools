#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
template <class T=int> 
class MyMedian {
private:
    map<T,int,greater<T> > smallDatas;
    map<T,int> bigDatas;
    unsigned int l_smalldatas;
    unsigned int l_bigdatas;
    unsigned l_k;
    unsigned l_l;
    T median;
public:
    void makeHeap(vector<T>& vdatas,unsigned k)
    {
        sort(vdatas.begin(),vdatas.end());
        l_k=k;
        median=vdatas[l_k-1];
        unsigned l=vdatas.size();
        l_l=l;
        cout<<l_k<<","<<l_l<<endl;
        l_smalldatas=l_k-1;
        l_bigdatas=l-l_k;
        for(unsigned i=0;i!=l_k-1;i++)
        {
            if(smallDatas.find(vdatas[i])==smallDatas.end())
            {
                smallDatas[vdatas[i]]=1;
            }
            else
            {
                smallDatas[vdatas[i]]+=1;
            }
        }
        for(unsigned i=l_k;i!=l;++i)
        {
            if(bigDatas.find(vdatas[i])==bigDatas.end())
            {
                bigDatas[vdatas[i]]=1;
            }
            else
            {
                bigDatas[vdatas[i]]+=1;
            }
        }
    }


    void addItem(const T& item)
    {
        if(item<median)
        {
            if(smallDatas.find(item)==smallDatas.end())
            {
                smallDatas[item]=1;
            }
            else
            {
                smallDatas[item]+=1;
            }
            l_smalldatas++;

            if(l_smalldatas>l_k-1)
            {
                if(bigDatas.find(median)==bigDatas.end())
                {
                    bigDatas[median]=1;
                }
                else
                {
                    bigDatas[median]+=1;
                }
                l_bigdatas++;
                typename map<T,int,greater<T> >::iterator iter=smallDatas.begin();
                median=iter->first;
                if(iter->second==1)
                {
                    smallDatas.erase(iter);
                }
                else
                {
                    --(iter->second);
                }
                --l_smalldatas;
            }
        }
        else if(item>median)
        {
            if(bigDatas.find(item)==bigDatas.end())
            {
                bigDatas[item]=1;
            }
            else
            {
                bigDatas[item]+=1;
            }
            l_bigdatas++;

            if(l_bigdatas>l_l-l_k)
            {
                if(smallDatas.find(median)==smallDatas.end())
                {
                    smallDatas[median]=1;
                }
                else
                {
                    smallDatas[median]+=1;
                }
                l_smalldatas++;
                typename map<T,int>::iterator iter=bigDatas.begin();
                median=iter->first;
                if(iter->second==1)
                {
                    bigDatas.erase(iter);
                }
                else
                {
                    --(iter->second);
                }
                --l_bigdatas;
            }
        }
        else if(item==median)
        {
            if(l_smalldatas<l_k-1)
            {
                ++l_smalldatas;
                if(smallDatas.find(median)==smallDatas.end())
                {
                    smallDatas[median]=1;
                }
                else
                {
                    ++smallDatas[median];
                }
            }
            else
            {
                ++l_bigdatas;
                if(bigDatas.find(median)==bigDatas.end())
                {
                    bigDatas[median]=1;
                }
                else
                {
                    ++bigDatas[median];
                }
            }
        }
    }
    T removeItem(T& item)
    {
        T removed;
        if(item==median)
        {
            removed=median;
            typename map<T,int,greater<T> >::iterator iter=smallDatas.begin();
            median=iter->first;
            if(iter->second==1)
            {
                smallDatas.erase(iter);
            }
            else
            {
                --(iter->second);
            }
            --l_smalldatas;
        }
        if(item<median)
        {
            typename map<T,int,greater<T> >::iterator iter=smallDatas.find(item);
            if(iter==smallDatas.end())
            {
                cout<<item<<" not exist!"<<endl;
            }
            else
            {
                removed=iter->first;
                if(iter->second==1)
                {
                    smallDatas.erase(iter);
                }
                else
                {
                    --(iter->second);
                }
                --l_smalldatas;
            }
        }
        else
        {
            typename map<T,int>::iterator iter=bigDatas.find(item);
            if(iter==bigDatas.end())
            {
                cout<<item<<" not exist!"<<endl;
            }
            else
            {
                removed=iter->first;
                if(iter->second==1)
                {
                    bigDatas.erase(iter);
                }
                else
                {
                    --(iter->second);
                }
                --l_bigdatas;
            }
        }
        return removed;
    }
    T& getMedian(void)
    {
        return median;
    }
};
