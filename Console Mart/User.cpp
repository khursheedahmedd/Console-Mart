//
//  User.cpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#include "User.hpp"
#include"User.hpp"
User::User()
{

}

void User::CreateUser() {
    cout<<"\nEnter your first name: ";
    cin>>First_Name;
    cout<<"\nEnter your last name: ";
    cin>>Second_Name;
    cout<<"\nEnter your phone number: ";
    cin>>Phone_Number;
    cout<<"\nEnter your city: ";
    cin>>City;
    cout<<"\nEnter your Email Address: ";
    cin>>Email_Address;
}

void User::displayUserInfo()
{
    cout<<"\n------------------------------------------";
    cout << "\nName : " << First_Name<<" "<< Second_Name;
    cout << "\nPhone Number : " << Phone_Number;
    cout << "\nCity : " << City;
    cout << "\nEmail Address : " << Email_Address;
    cout<<"\n------------------------------------------\n";
}
