#include <iostream>
using namespace std;

const int maxSize = 100;//定义线性表最大长度为100

template<typename T> class Sqlist
{
public:
    void InitList();//初始化一个空表
    bool ListEmpty();//判断线性表是否为空
    void ClearList();//将线性表清空
    bool GetElem(int location, T &element);//返回线性表中第i个值
    int LocateElem(T element);//线性表中查找与e相等的元素，返回第一个与e相等元素在线性表中的序号，否则，返回0
    bool ListInsert(int location, T element);//在线性表中的第i个位置插入新元素
    bool ListDelete(int location, T &element);//删除线性表中第i个位置的元素，并返回其值
    int ListLength();//返回线性表的长度
private:
    T *data;//线性表中的数据
    int length;//线性表的当前长度
};

//开始实现各成员函数
template<typename T> void Sqlist<T>::InitList()
{
    data = new T[maxSize];//初始化一个空表
    length = 0;
}

template<typename T> bool Sqlist<T>::ListEmpty()
{
    if(length == 0)
        return true;
    return false;
}

template<typename T> void Sqlist<T>::ClearList()
{
    data = NULL;
    length = 0;
}

template<typename T> bool Sqlist<T>::GetElem(int location, T &element)
{
    if (location > length)
    {
        return false;//越界了
    }
    element = *(data + location - 1);
    return true;
}

template<typename T> int Sqlist<T>::LocateElem(T element)
{
    for (int i = 0; i < length; i++)
    {
        if(*(data+i) == element)
            return i+1;
    }
    return 0;
}

template<typename T> bool Sqlist<T>::ListInsert(int location, T element)
{
    if (location > (length + 1))
        return false;
    for (int i = length; i >= location; i--)
    {
        *(data + i) = *(data + i - 1);
    }
    *(data+location-1) = element;
    length+=1;
    return true;
}

template<typename T> bool Sqlist<T>::ListDelete(int location, T &element)
{
    if (location > length)
    {
        return false;
    }
    element = *(data + location - 1);
    for (int i = location - 1; i < (length - 1); i++)
    {
        *(data + i) = *(data + i + 1);
    }
    length -= 1;
    return true;
}

template<typename T> int Sqlist<T>::ListLength()
{
    return length;
}



