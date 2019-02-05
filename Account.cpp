#include<iostream>
#include<string>
#include<map>
using namespace std;


class Account{
    protected:
        string username, password, role;
        map<string, string> users;
        map<string, string> user_roles;
    public:
        void initializeUsers();
        void getUsernamePassword();
        bool validateLoginInfo();
};

void Account ::  initializeUsers(){
    this->users.insert(pair<string, string>("Karuna", "karuna"));
    this->user_roles.insert(pair<string,string>("Karuna", "user"));
    this->users.insert(pair<string, string>("Benita", "benita"));
    this->user_roles.insert(pair<string,string>("Benita", "user"));
    this->users.insert(pair<string, string>("Mayur", "mayur"));
    this->user_roles.insert(pair<string,string>("Mayur", "user"));
    this->users.insert(pair<string, string>("Sanidhya", "sanidhya"));
    this->user_roles.insert(pair<string,string>("Sanidhya", "driver"));
    this->users.insert(pair<string, string>("Yash", "yash"));
    this->user_roles.insert(pair<string,string>("Yash", "driver"));
}

void Account::  getUsernamePassword(){
    cout<<"Enter your username: ";
    cin>>username;
    this->username = username;
    cout<<"Enter password: ";
    cin>>password;
    this->password= password;
}

bool Account ::  validateLoginInfo(){
   if(username.compare(this->users.find(this->username)->first) == 0){
       if((this->password).compare((this->users).find(this->username)->second) == 0){
           cout<<"Welcome "<<this->username<<endl;
           return true;
       }else {
           cout<<"Incorrect password"<<endl;
           return false;
       }
   }else {
       cout<<"Username not registered."<<endl;
       return false;
   }
}
