//
//  User.hpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#ifndef User_hpp
#define User_hpp
#include<iostream>
#include<string>
using namespace std;
class User
{
public:
    string First_Name;
    string Second_Name;
    string Phone_Number;
    string City;
    string Email_Address;
    
    User();
    void CreateUser();
    void displayUserInfo();
};





#endif /* User_hpp */
