#include "Sales_data.h"
#include <iostream>

Sales_data::Sales_data(istream &is)
{
    read(is, *this); //������Ԫ����
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

double Sales_data::avg_price() const
{
    if(units_sold)
        return revenue / units_sold;
    else
        return 0;
}

//��Ԫ����ֻ������ʱʹ�ùؼ���friend���������嶨��ʱ��ʹ��
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price(); 

    return os;
}

istream &read(istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.price;
    item.revenue = item.units_sold * item.price;
    return is;
}