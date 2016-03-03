//sim.cpp
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>
#include"cust.h"

using namespace std;

Cust::Cust(string name,bool type, int arrival, int items)
{
    m_name = name;
    m_type = type;
    m_arrival = arrival;
    m_items = items;
    m_done_checkout = 0;
}
void Cust::print(ostream &os)
{
    os<<m_name<<" "<<(m_type ? "robber":"shopper")<<" "<<m_arrival<<" "<<m_items<<endl;
}
void Cust::print_entered(ostream &os, int clock)
{
    os<<clock<<": "<<m_name<<" entered store"<<endl;
}
void Cust::print_done_shopping(ostream &os, int clock, int checker_no)
{
    os<<clock<<": "<<m_name<<" done shopping, waiting for checker " <<checker_no<<endl;
}
void Cust::print_checkout(ostream &os, int clock, int checker_no )
{
    os<<clock<<": "<<m_name<<" started checkout with checker "<<checker_no<<endl;
    if(m_type == true)
    {
        m_done_checkout = clock + 4;
    }
    else
    {
        m_done_checkout = clock + m_items;
    }
}
void Cust::print_checkout_shopper(ostream &os, int clock,int checker_no)
{
    if(m_items < 2 )
    {
        os<<clock<<": "<<m_name<<" paid $"<<m_items * 3  <<" for "<<m_items<<" item to checker "<<checker_no<<endl;
    }
    else
    {
        os<<clock<<": "<<m_name<<" paid $"<<m_items * 3  <<" for "<<m_items<<" items to checker "<<checker_no<<endl;
    }
}
void Cust::print_checkout_robber(ostream &os, int clock,int checker_no,int stole)
{
    if(m_items < 2 )
    {
        os<<clock<<": "<<m_name<<" stole $"<<stole<<" and "<<m_items<<" item from checker "<<checker_no<<endl;
    }
    else
    {
        os<<clock<<": "<<m_name<<" stole $"<<stole<<" and "<<m_items<<" items from checker "<<checker_no<<endl;
    }
}
bool Cust::is_robber()
{
    return m_type;
}
int Cust::money_paid()
{
    if(m_type == true)
    {
        return 0;
    }
    else
    {
        return m_items * 3;
    }
}
int Cust::done_shopping_time()
{
    return m_arrival + (m_items * 2);
}

bool Cust::time_at_checker(int clock)
{   
    if (clock == m_done_checkout)
    {
        return true;
    }
    else
    {
        return false;
    }
}
