//
//  Console Mart.hpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#ifndef Console_Mart_hpp
#define Console_Mart_hpp
#include "Product.hpp"
#include "Cart.hpp"

class ConsoleMart
{
public:
    Product* lastSearch;
    Product* lastPurchase;
    ShoppingCart cartObject;
    int itemCount;
    Product* root;
    
    ConsoleMart();
    void findMax(Product* root, int& max);
    Product* findMinPrice();
    Product* findMaxPrice();

    void removeProduct(string);
    void updateProduct(string);
    void searchProduct(string);
    void displayInorder(Product* node);
    void displayPreorder(Product* node);
    void displayPostorder(Product* node);

    void insertProduct(Product* newNode);
    void processTree(Product*& root);
    bool searchByName(string name);
    void removeItem(string name);
    void ShowCategory(Product* root, string cat);
//    void categorySearch(string category);
    Product* findSuccessor(Product* root);
    void showProductsByCategory(Product* root, string category);
    void deleteProduct(Product* parent, Product* temp, string key);
    Product* searchByNameHelper(Product* prod, string name);
//    void printSortedByOccurrence(Product* root);
//    void printRecommendations();
    void displayPurchaseHistory();
    void printPurchaseHistory(Product* root);
    void displaySearchHistory();
    void printSearchHistory(Product* root);
    void CategoryCall(string cate);
    void calculateTotalCall(Product* bySearch, Product* byPurchase);
    void calculateTotal(Product* root, Product* byS, Product* byP, int& searchCount, int& purchaseCount);
    void BSTToArray(Product* root, Product* arr[], int &index);
    Product** BSTToArray();
    void sortProductsByOccurrence(Product* arr[], int size);
    void printSortedProducts(Product* arr[], int size);
    void recommendations();
//    void calculateTotalHelper(Product* node, Product* product, int& count, int limit);
//    void calculateTotalForSearch(Product* bySearch);
//    void calculateTotalForPurchase(Product* byPurchase);
};




#endif /* Console_Mart_hpp */
