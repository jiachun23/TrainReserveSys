#include "login.h"
#include <iostream>
using namespace std;

login::login()
{
	string username = "";
    string password = "";
    bool loginSuccess = false;

    cout<<"\tWelcome to the database of passenger !!!"<<endl;

    do {
        cout<<"Username: ";
        cin>>username;
        cout<<"Password: ";
        cin>>password;

        if (username == "Train" && password == "letmein"){
            cout<<"\nSuccessful Login\n\n";
            loginSuccess = true;
        }
        else {
            cout<<"Incorrect username and password \n";
            cout<<"Please try again."<<endl;
        }
    }while(!loginSuccess);
}


