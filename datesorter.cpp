#include "datesorter.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

int monthToInt(string m){
    if (m == "Jan"){
        return 1;
    } else if (m == "Feb"){
        return 2;
    } else if (m == "Mar"){
        return 3;
    } else if (m == "Abr"){
        return 4;
    } else if (m == "May"){
        return 5;
    } else if (m == "Jun"){
        return 6;
    } else if (m == "Jul"){
        return 7;
    } else if (m == "Ago"){
        return 8;
    } else if (m == "Sep"){
        return 9;
    } else if (m == "Oct"){
        return 10;
    } else if (m == "Nov"){
        return 11;
    } else if (m == "Dic"){
        return 12;
    }
    return 0;
}

//pequeña pausa
void pause(){
    cout << "Press enter to continue.";
    cin.ignore(); // limpia cualquier residuo
    cin.get();    // espera por el click de cualquier tecla
}

// this function loads movie data from a csv and adds them to the catalog
void loadOrderData(const string& filename, vector<Order*>& _orders) {
    ifstream file(filename);
    string line;

    while(getline(file, line)){
        stringstream ss(line);
        string s, min, hr, day, month, year, n, r, o;

        // get each field from the csv line
        getline(ss, month,' ');
        getline(ss, day, ' ');       
        getline(ss, hr, ':');       
        getline(ss, min, ':');   
        getline(ss, s, ' ');   
        getline(ss, r, ' ');     
        getline(ss, o, '(');     
        getline(ss, n, ')');    


        // convert strings to numbers
        int _s, _min, _hr, _day, _month, _n;
        _s = stoi(s);
        _min = stoi(min);
        _hr = stoi(hr);
        _day = stoi(day);
        _month = monthToInt(month);
        _n = stoi(n);

        // create a new movie and add to the catalog
        Order* order = new Order(_s,_min,_hr,_day,_month,_n,r,o);
        _orders.push_back(order);
    }

    file.close();
}




int main(){
    vector<Order*> orders;
    int n = orders.size();         
    int* indices = new int[n];
       
    loadOrderData("orders.txt", orders);

    for (int i = 0; i < 10; i++){
        cout << orders[i]->str()<<endl;
    }
    delete[] indices, orders;
}