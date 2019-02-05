#include<iostream>
#include<iostream>
#include<vector>
#include<iterator>
#include<utility>
#include "Account.cpp"
#include "SourceDest.cpp"
#include "Eta.cpp"
#include "GPS.cpp"
#include<thread>
using namespace std;

void func1() {
    Account acc_obj;
    acc_obj.initializeUsers();
    acc_obj.getUsernamePassword();
    acc_obj.validateLoginInfo();

    Map map_obj;
    map_obj.locationList();
    map_obj.populateGraph();

    SourceDest sd_obj;
    sd_obj.getSourceDest(map_obj);
    int source_index = sd_obj.getSourceIndex();
    int destination_index = sd_obj.getDestIndex();

    Eta eta_obj;
    eta_obj.decrementTime(map_obj,source_index,destination_index);
}

void func2() {
    Gps gps_obj;
    gps_obj.isGpsWeak();
}

int main() {
    thread td1(func1);
    thread td2(func2);
    td1.join();
    td2.join();

    return 0;
}
