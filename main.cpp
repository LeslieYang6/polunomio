#include<iostream>

#include"seq.cpp"
using namespace std;


#include<iostream>

#include<cstring>

#include<math.h>
using namespace std;
//获得参数
void GetParameters(string p, Sqlist<double> *para)
{
    int j=0;
    int i;
    int length=(int)p.length();
    //递归的获得每一项的系数
    for(i=0;i<100;i++)
    {
        while(p[j]!='+'&&p[j]!='x'&&p[j]!='.')
        {
            double temp;
            para->ListDelete(i,temp);
            temp=temp*10+(p[j++]-'0');
            para->ListInsert(i,temp);
        }
        //如果是浮点的系数
        if(p[j]=='.') {
            j++;
            double temp = 0;
            int k = 1;
            while (p[j] <= '9')
                temp = temp + (p[j++] - '0') / pow(10, k++);
            double temp2;
            para->ListDelete(i,temp2);
            temp2=temp+temp2;
            para->ListInsert(i,temp2);
        }
        //遇到加号停止迭代
        while(p[j]!='+')
        {
            if(j+1==length)
                break;
            j++;
        }
        j++;
        if(j==length)
            break;

    }
    if(i==99&&j<length)
        cerr<<"out of bounds";

}
//加法
void add(Sqlist<double> *para1,Sqlist<double>* para2,Sqlist<double>*result)
{
    double temp1;
    double temp2;
    for(int i=0;i<100;i++) {
        para1->GetElem(i,temp1);
        para2->GetElem(i,temp2);
        result->ListInsert(i,temp1+temp2);
    }
}
//减法
void subtract(Sqlist<double> *para1,Sqlist<double>* para2,Sqlist<double>*result)
{
    double temp1;
    double temp2;
    for(int i=0;i<100;i++) {
        para1->GetElem(i,temp1);
        para2->GetElem(i,temp2);
        result->ListInsert(i,temp1-temp2);
    }
}

void multiple(Sqlist<double> *para1,Sqlist<double>* para2,Sqlist<double>*result)
{
    int length1=para1->ListLength();
    int length2=para2->ListLength();
    if(length1==0||length2==-0)
        return;
    if(length1+length2>100)
    {
        cerr<<"out of bounds";
    }
    
    //第i+j项的系数等于para1[i]+parai[2]
    for(int i=0;i<length1;i++) {
        double temp1,temp2,temp3;
        para1->GetElem(i,temp1);
        for (int j = 0; j < length2; j++) {

            para2->GetElem(j,temp2);
            result->ListDelete(i+j,temp3);
            result->ListInsert(i+j,temp3+temp2*temp1);
        }
    }
}


