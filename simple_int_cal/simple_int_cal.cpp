#include <iostream>
using namespace std;

class Principal
{
public:
    Principal(int m_principal):p(m_principal){}
    Principal():p(0){}

   
    int set_principal(int p)
    {
        return p=p;
        cout<<"set principal"<<endl;
    }

    float get_principal()
    {
        return p;
    }

    ~Principal()
    {
        // cout<<"calling destructor of class principal"<<endl;
    }

private:
    int p;
};

class Rate: public Principal
{
public:
    Rate (float m_rate):r(m_rate){}
    Rate ():r(0){}

   
    float set_rate(float r)
    {
        return r=r;
    }

    float get_rate()
    {
        return r;
    }

    ~Rate()
    {
        // cout<<"calling destructor of class rate"<<endl;
    }

private:
    float r;
};

class Time_period: public Rate
{
public:
    Time_period (float m_time):t(m_time){}
    Time_period ():t(0){}

   
    int set_time(float t)
    {
        return t=t;
    }

    float get_time()
    {
        return t;
    }


    ~Time_period()
    {
        // cout<<"calling destructor of class Time_period"<<endl;
    }

private:
    float t;
};

int main()
{   
Principal P;
Rate R;
Time_period T;

P.set_principal(5000);
P.get_principal();
R.set_rate(5.2);
R.get_rate();
T.set_time(4.5);
T.get_time();

float simple_interest=P.get_principal()+R.get_rate()+T.get_time();
cout<<"The simple interest is : "<<simple_interest<<endl;

    return 0;
}
