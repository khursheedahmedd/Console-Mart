//
//  Product.cpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#include "Product.hpp"

Product::Product() {
    productName = "";
    productRating = 0.0;
    productPrice = 0;
    productDescription = "";
    productStock = 0;
    left = right = NULL;
    pre = next = NULL;
    occurrence = 0;
    searched = false;
    purchased = false;
}

Product::Product(string name, double rating, int price, string description, int stock, string category) {
    this->productName = name;
    this->productDescription = description;
    this->productPrice = price;
    this->productRating = rating;
    this->productStock = stock;
    this->productCategory = category;
}
