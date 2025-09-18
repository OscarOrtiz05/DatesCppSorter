#include <iostream>
using namespace std;

class Order {
    private:
    int sec, min, hr, day, month, n;
    string restaurant, name;
    public:
    Order(){
        sec = 0;
        min = 0;
        hr = 0;
        day = 0;
        month = 0;
        n = 0;
        restaurant = "";
        name = "";
    };
    Order(int _s, int _min, int _h, int _d, int _m, int _n, string _r, string _nm){
        sec = _s;
        min = _min;
        hr = _h;
        day = _d;
        month = _m;
        n = _n;
        restaurant = _r;
        name = _nm;
    };

    int getSec(){
        return sec;
    };
    int getMin(){
        return min;
    };
    int getHour(){
        return hr;
    };
    int getDay(){
        return day;
    };
    int getMonth(){
        return month;
    };
    int getNumber(){
        return n;
    };
    string getName(){
        return name;
    };
    string getRestaurant(){
        return restaurant;
    };
    string str(){
        return to_string(month) + " " + to_string(day) + " " + to_string(hr)+ ':' + to_string(min)+ ':' + to_string(sec)+ " " + name + restaurant + to_string(n);
    }
};