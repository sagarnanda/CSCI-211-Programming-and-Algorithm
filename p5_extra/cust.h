//sim.cpp
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>

#ifndef Cust_H
#define Cust_H
using namespace std;

class Cust
{ 
    public:
        Cust(string name,bool type, int arrival, int items);
        void print(ostream &os);
        void print_entered(ostream &os, int clock);
        void print_done_shopping(ostream &os, int clock, int checker_no);
        void print_checkout_shopper(ostream &os, int clock, int checker_no);
        void print_checkout_robber(ostream &os, int clock, int checker_no, int stole);
        void print_checkout(ostream &os, int clock, int checker_no);
        int done_shopping_time(); 
        bool time_at_checker(int clock);
        bool is_robber();
        int money_paid();
        ////////
        int m_done_checkout;
        string m_name;
    private:
        bool m_type;
        int m_arrival;
        int m_items;

};
#endif

