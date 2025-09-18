#include <iostream>
using namespace std;

class Order {
    private:
    int sec, min, hr, day, month, n;
    string restaurant, name;
    public:
    Order() : sec(0), min(0), hr(0), day(0), month(0), n(0), restaurant(""), name("") {}
     Order(int _s, int _min, int _h, int _d, int _m, int _n, const string& _r, const string& _nm)
        : sec(_s), min(_min), hr(_h), day(_d), month(_m), n(_n),
          restaurant(_r), name(_nm) {}

    int getSec() const { return sec; }
    int getMin() const { return min; }
    int getHour() const { return hr; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getNumber() const { return n; }
    string getName() const { return name; }
    string getRestaurant() const { return restaurant; }

    int compareTime(const Order& other) const {

        if (month != other.month) {return (month < other.month) ? (-2) : (2);}
        if (day   != other.day)   {return (day   < other.day)   ? (-3) : (3);}
        if (hr    != other.hr)    {return (hr    < other.hr)    ? (-4) : (4);}
        if (min   != other.min)   {return (min   < other.min)   ? (-5) : (5);}
        if (sec   != other.sec)   {return (sec   < other.sec)   ? (-6) : (6);}
        return 0;
    }

    string str(){
        return to_string(month) + " " + to_string(day) + " " + to_string(hr)+ ':' + to_string(min)+ ':' + to_string(sec)+ " " + name + restaurant + to_string(n);
    }

    bool operator == (const Order& other) const {
        return (compareTime(other) == 0);
    }
    bool operator > (const Order& other) const {
        return (compareTime(other) > 0);
    }
    bool operator < (const Order& other) const {
        return (compareTime(other) < 0);
    }
    
};