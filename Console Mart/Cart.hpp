//
//  Cart.hpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#ifndef Cart_hpp
#define Cart_hpp
#include"Product.hpp"
#include "User.hpp"
#include<ctime>

class ShoppingCart {
private:
    int itemCount;
    int totalBill;
    Product* cartHead;
    Product* cartTail;

public:
    ShoppingCart();

    void AddToCart(Product* product);
    void DisplayCart();
    void UpdateCart();
    void ProcessCheckout();
};

#endif /* Cart_hpp */
