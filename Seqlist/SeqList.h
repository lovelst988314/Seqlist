# include <iostream>
# include <cstdlib>               
# include "linearList.h"
using namespace std;

const int defaultSize = 100;
template<class T>
class SeqList:public LinearList<T>{
    protected:
        T * data;    // 用以存放表中元素的数组
        int maxSize; //表最大可容纳表项个数
        int last; // last为表中元素的个数
        void reSize(int newSize);                           // 改变data数组空间大小
    public:
        SeqList(int sz = defaultSize);                      // 构造函数
        SeqList(SeqList<T>& L);                             // 复制构造函数
        ~SeqList(){delete[] data;}                          // 析构函数
        int Size()const{return maxSize;}                    // 计算表最大可容纳表项个数
        int Length()const{return last+1;}                   // 计算表长度
        int Search(T& x)const;                                     // 搜索x在表中位置，返回表项序号
        int Locate(int i)const;                             // 定位第i个表项，函数返回表项序号
        bool getData(int i, T& x);                      // 取第i个表项的值
        bool setData(int i,T& x)                            // 用x修改第i个表项的值
            {if(i > 0 && i <= last + 1) {data[i - 1] = x;return true;}else return false;}
        bool Insert(int i, T& x);                           // 插入x在第i个表项之后
        bool Remove(int i, T& x);                           // 删除第i个表项，通过x返回表项的值
        bool IsEmpty(){return (last == -1) ? true : false;}    // 判表空否，空则返回true，否则返回false
        bool IsFull(){return (last == maxSize-1) ? true : false;}   // 判表满否，满则返回true；否则返回false
        void input();                                      // 输入
        void output();                                     // 输出
        SeqList<T>& operator=(SeqList<T>& L);               // 表整体赋值
};