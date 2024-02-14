//
//  Cart.cpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#include "Cart.hpp"


ShoppingCart::ShoppingCart() {
    itemCount = 0;
    totalBill = 0;
    cartHead = nullptr;
    cartTail = nullptr;
}

void ShoppingCart::AddToCart(Product* product) {
    if (cartHead == nullptr) {
        cartHead = product;
        cartTail = product;
        itemCount++;
        return;
    }

    cartTail->next = product;
    product->pre = cartTail;
    cartTail = cartTail->next;
    itemCount++;
}

void ShoppingCart::DisplayCart() {
    if (itemCount != 0) {
        totalBill = 0;
        Product* temp = cartHead;

        while (temp != nullptr) {
            cout << "-----------------------------------" << endl << endl;
            cout << "Name : " << temp->productName << endl;
            cout << "Description :  " << temp->productDescription << endl;
            cout << "Category :  " << temp->productCategory << endl;
            cout << "Price :  " << temp->productPrice << endl;
            cout << "-----------------------------------" << endl << endl;
            totalBill += temp->productPrice;
            temp = temp->next;
        }
    } else {
        cout << "Your Cart Is Empty" << endl;
    }
}
void ShoppingCart::UpdateCart() {
    if (!cartHead) {
        cout << "Your Cart Is Empty" << endl;
        return;
    }

    cout << "------------------------" << endl;
    cout << "\tUpdate Cart" << endl;
    cout << "------------------------" << endl;

    string productName;
    cout << "Enter Product Name To Cancel Order :" << endl;
    cin.ignore();
    getline(cin, productName);

    if (productName.empty()) {
        cout << "Invalid product name. Please try again." << endl;
        return;
    }

    if (cartHead->productName == productName && cartTail->productName == productName) {
        totalBill = totalBill - cartHead->productPrice;
        delete cartHead;
        cartHead = cartTail = nullptr;
        cout << "\tOrder Canceled Successfully " << endl;
        itemCount--;

        return;
    }

    if (cartHead->productName == productName) {
        totalBill = totalBill - cartHead->productPrice;
        Product* toDelete = cartHead;
        cartHead = cartHead->next;
        cartHead->pre = nullptr;
        delete toDelete;
        cout << "\tOrder Canceled Successfully " << endl;
        itemCount--;
        return;
    }

    if (cartTail->productName == productName) {
        totalBill = totalBill - cartTail->productPrice;
        Product* toDelete = cartTail;
        cartTail = cartTail->pre;
        cartTail->next = nullptr;
        delete toDelete;
        cout << "\tOrder Canceled Successfully :" << endl;
        itemCount--;
        return;
    }

    Product* temp = cartHead;
    while (temp->next != nullptr) {
        if (temp->next->productName == productName) {
            totalBill = totalBill - temp->next->productPrice;
            Product* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next != nullptr) {
                toDelete->next->pre = temp;
            }
            delete toDelete;
            cout << "\tOrder Canceled Successfully :" << endl;
            itemCount--;
            return;
        }
        temp = temp->next;
    }
    cout << "No order with this name " << productName << endl;
}
void ShoppingCart::ProcessCheckout(){

    if (itemCount != 0) {

        User user;
        user.CreateUser();
        
        if (totalBill != 0) {
         

            user.displayUserInfo();

//            time_t now = time(0);
            tm ltm;
//            localtime_s(&ltm, &now);

            int year = 1900 + ltm.tm_year;
            int month = 1 + ltm.tm_mon;
            int day = ltm.tm_mday;
            int day1 = day;

            day = day + 5;
            if (day > 31) {
                day = day / 31;
                month++;
                day += 3;
            }


            cout << "Date Of Order Placement : 1 feb, 2024.";

            cout << "Date Of Delivery \t: 12 feb, 2024.";

            cout << "Your Total Bill Is Rs. " << totalBill << endl;
        } else {
            cout << "Your Cart Is Empty" << endl;
        }

        cout << "Thanks For Purchasing From Us!" << endl;
        totalBill = 0;
        itemCount = 0;

        while (cartHead != NULL) {
            Product* toDelete = cartHead;
            cartHead = cartHead->next;
            delete toDelete;
        }
    } else {
        cout << "Your Cart Is Empty" << endl;
    }
}
