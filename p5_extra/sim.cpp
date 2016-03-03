//sim.cpp
//Nanda, Sagar
//snanda

#include<iostream>
#include<string>
#include<fstream>

#include"cust.h"
#include"pqueue.h"

using namespace std;

struct Checker
{
    Cust *m_cust;    
    int money_reg;
    int m_time_available;
};

bool legal_int(char *str);
void run_simulation(Pqueue &arrival_queue, int num_checkers, int break_duration, ostream &os);

int main(int argc, char *argv[])
{

    int num_checker = 0;
    int break_dur = 0;
    string name;
    string role_string;
    int arrival = 0;
    int items = 0;

    Pqueue arrival_q;

    if(argc != 5)
    {
        cerr<<"Error: invalid number of command line arguments."<<endl;
        return 1;
    }    
    ifstream my_ifile(argv[3], ios::in);
    ofstream my_ofile(argv[4], ios::out);
    if(!my_ifile)
    {
        cerr<<"Error: could not open input file <" <<argv[3]<<">."<< endl;
        return 1;
    } 
    if(!my_ofile)
    {
        cerr<<"Error: could not open output file <" <<argv[4]<<">."<<endl;
        return 1;
    }
    if(!legal_int(argv[1]))
    {
        cerr<<"Error: invalid number of checkers specified."<<endl;
        return 1;
    }
    num_checker = atoi(argv[1]);
    if(num_checker < 1)
    {
        cerr<<"Error: invalid number of checkers specified."<<endl;
        return 1;
    }
    if(!legal_int(argv[2]))
    {
        cerr<<"Error: invalid checker break duration specified."<<endl;
        return 1;
    }
    break_dur = atoi(argv[2]);
    if(break_dur < 0)
    {
        cerr<<"Error: invalid checker break duration specified."<<endl;
        return 1;
    }
    while(my_ifile>>name)
    {
        my_ifile>>role_string;
        my_ifile>>arrival;
        my_ifile>>items;
        arrival_q.enqueue(new Cust(name,(role_string == "robber" ? 1:0),arrival,items),arrival);
    }
    run_simulation(arrival_q,num_checker,break_dur,my_ofile);
}

bool legal_int(char *str)
{
    while (*str != 0)
    {
        if(!isdigit(*str))
        {
            return false;
        }
        str = str + 1;
    }
    return true;
}

int available_checkoutQ(Pqueue *checkout_q, Checker *checkers, int num_checkers)
{
    int temp = 0;
    int min = 2147483647;
    int index = 0;
    for(int i =0; i < num_checkers; i++)
    {
        temp = checkout_q[i].total_customers();
        if(checkers[i].m_cust != NULL)
        {
            temp++; 
        }
        if(temp < min)
        {
            min = temp;
            index = i;
        }
    } 
    return index;
}

void run_simulation(Pqueue &arrival_q, int num_checkers, int break_duration, ostream &os)
{ 
    Checker *checkers = new Checker[num_checkers];
    for (int i = 0; i < num_checkers;i++)
    {
        checkers[i].money_reg = 100;
        checkers[i].m_cust = NULL;
        checkers[i].m_time_available = 0;
    }  

    Pqueue shopping_q;
    Pqueue *checkout_q = new Pqueue[num_checkers];
    int num_customers = arrival_q.total_customers();    
    int fclock = 1;
    for (int clock = 1; num_customers > 0; clock++)
    {
        fclock++;
        while(clock == arrival_q.first_prio())  
        {
            Cust *cur_cust = arrival_q.dequeue();                          
            cur_cust->print_entered(os,clock);
            shopping_q.enqueue(cur_cust,cur_cust->done_shopping_time());
        }    
        while(clock == shopping_q.first_prio())
        {
            Cust *cur_cust = shopping_q.dequeue();
            int index = available_checkoutQ(checkout_q, checkers, num_checkers);
            checkout_q[index].enqueue(cur_cust,1);
            cur_cust->print_done_shopping(os,clock,index);
        } 
        for(int i = 0;i < num_checkers;i++)
        {

            if(checkers[i].m_cust != NULL && checkers[i].m_cust->time_at_checker(clock))   
            {
                if(checkers[i].m_cust -> is_robber() == true)
                {
                    checkers[i].m_cust->print_checkout_robber(os, clock, i,checkers[i].money_reg); 
                    checkers[i].money_reg = 0;
                    checkers[i].m_time_available = clock + break_duration;  
                }
                else
                {
                    checkers[i].money_reg += checkers[i].m_cust->money_paid();
                    checkers[i].m_cust->print_checkout_shopper(os, clock, i);
                }
                delete checkers[i].m_cust;
                num_customers--;
                checkers[i].m_cust = NULL;
            }
        }
        for(int i = 0;i < num_checkers;i++)
        { 
            if(checkout_q[i].empty()==false && checkers[i].m_cust == NULL && checkers[i].m_time_available <= clock)
            {
                Cust *cur_cust = checkout_q[i].dequeue();                         
                checkers[i].m_cust = cur_cust;  
                checkers[i].m_time_available = cur_cust->time_at_checker(clock); 
                cur_cust->print_checkout(os,clock,i);

            } 
        }     
    }
    for (int i = 0; i < num_checkers; i++)
    {
        os<<"registers["<<i<<"] = $"<<checkers[i].money_reg<<endl;     
    }
    os<<"time = "<<fclock<<endl;
    delete []checkers;
    delete []checkout_q;
}
