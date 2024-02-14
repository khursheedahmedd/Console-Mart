//
//  Product.hpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#ifndef Product_hpp
#define Product_hpp
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Product {
public:
    Product* next;
    Product* pre;

    Product();
    Product(string productName, double productRating, int productPrice, string productDescription, int productStock,  string productCategory);

    double productRating;
    string productName;
    int productPrice;
    string productDescription;
    int productStock;
    string productCategory;
    float occurrence;
    bool searched;
    bool purchased;

    Product* left, * right;
};



#endif /* Product_hpp */
