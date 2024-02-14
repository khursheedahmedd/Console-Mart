//
//  Console Mart.cpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#include "Console Mart.hpp"
#include<queue>

ConsoleMart::ConsoleMart()
{
    root = NULL;
    itemCount = 0;
    lastPurchase = lastSearch = NULL;
}

void ConsoleMart::findMax(Product* node, int& max)
{
    if (node == NULL)
        return;

    findMax(node->left, max);
    if (node->productPrice > max)
        max = node->productPrice;
    findMax(node->right, max);
}


Product* findMinPriceRecursive(Product* node) {
    if (node == nullptr) {
        cout << "\nCannot find minimum price.";
        return nullptr;
    }

    if (node->left!= nullptr) {
        return findMinPriceRecursive(node->left);
    }

    return node;
}


Product* ConsoleMart::findMinPrice() {
    return findMinPriceRecursive(root);
}

Product* ConsoleMart::findMaxPrice() {
    if (root == nullptr) {
        cout << "Cannot find maximum price." << endl;
        return nullptr;
    }

    Product* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }

    return current;
}



void ConsoleMart::insertProduct(Product* newNode)
{
    if (root == NULL)
        root = newNode;
    else
    {
        Product* temp = root;
        while (temp != NULL)
        {
            if (temp->productName <= newNode->productName)
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
            else if (temp->productName > newNode->productName)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
        }
    }
}


void ConsoleMart::displayInorder(Product* node) {
    if (node != nullptr) {
        displayInorder(node->left);
        
        cout<<"\nName: "<<node->productName;
        cout<<"\nCategory: "<<node->productCategory;
        cout<<"\nPrice: "<<node->productPrice;
        displayInorder(node->right);

    }
}

void ConsoleMart::displayPreorder(Product* node) {
    if (node != nullptr) {
        cout<<"\n----------------------------------";
        cout<<"\nName: "<<node->productName;
        cout<<"\nCategory: "<<node->productCategory;
        cout<<"\nPrice: "<<node->productPrice;
        cout<<"\n----------------------------------\n";
        displayPreorder(node->left);
        displayPreorder(node->right);
    }
}

void ConsoleMart::displayPostorder(Product* node) {
    if (node != nullptr) {
        displayPostorder(node->left);
        displayPostorder(node->right);
        cout<<"\nName: "<<node->productName;
        cout<<"\nCategory: "<<node->productCategory;
        cout<<"\nPrice: "<<node->productPrice;
    }
}



void ConsoleMart::updateProduct(string name)
{
    if (root == NULL)
    {
        cout << "Product List is Empty" << endl;
        return;
    }
    Product* temp = root;
    while (temp != NULL)
    {
        if (temp->productName > name)
        {
            temp = temp->left;
        }
        else if (temp->productName < name)
        {
            temp = temp->right;
        }
        else if (temp->productName == name)
        {
            cout << "Ok Found!" << endl;
            break;
        }
    }
    if (temp != NULL)
    {

        string  description, category;
        int stock, price;

        cout << "Enter Product Price" << endl;
        cin >> price;
        cout << "Enter Product Description : " << endl;
        getline(cin, description);
        cout << "Enter Product Category : " << endl;
        cin.ignore();
        getline(cin, category);
        cout << "Enter Product Available Stock : " << endl;
        cin >> stock;

        temp->productPrice = price;
        temp->productDescription = description;
        temp->productCategory = category;
        temp->productStock = stock;

    }
    else
    {
        cout << "Product Not Found" << endl;
    }
}

void ConsoleMart::searchProduct(string name)
{
    if (root == NULL)
    {
        cout << "No Record Found!" << endl;
    }
    else
    {
        Product* temp = root;
        while (temp != NULL)
        {
            if (temp->productName == name)
            {
                cout << endl;
                cout << "Product Name :" << temp->productName << endl;
                cout << "Product Price :" << temp->productPrice << endl;
                cout << "Product Description :" << temp->productDescription<< endl;
                cout << "Product Available Stock :" << temp->productStock << endl;
                cout << "Product Rating :" << temp->productRating << endl << endl << endl;
                
                temp->occurrence += .70;
                temp->searched = true;
                lastSearch = temp;

                int ch;
                do {

                    cout << "Do You Want To Purchase It ? Press for yes (1/0)" << endl;
                    cin >> ch;
                    if (ch == 1)
                    {

                        Product* DummyNode = new Product();

                        DummyNode->productName = lastSearch->productName;
                        DummyNode->productPrice = lastSearch->productPrice;
                        DummyNode->productRating = lastSearch->productRating;
                        DummyNode->productDescription = lastSearch->productDescription;
                        DummyNode->productStock = lastSearch->productStock;
                        DummyNode->productCategory = lastSearch->productCategory;

                        cartObject.AddToCart(DummyNode);
                        lastPurchase = temp;
                        cout << "\nYour Current Cart\n";
                        cartObject.DisplayCart();
                        cout << "Product Added To Cart SuccessFully" << endl;
                        cout << endl;
                        
                        temp->occurrence += .30;
                        temp->purchased  = true;
                        int x = 0;
                        do {
                            cout << "Do You Want To Continue Shopping ? (1/0)" << endl;
                            cin >> x;
                            if (x == 1)
                            {
                                CategoryCall(temp->productCategory);
                                int x = 0;
                                do {


                                    cout << "--------------------------------------------------------\n";
                                    cout << "Do you want to purchase more? Press 1 for yes (1/0)" << endl;
                                    cout << "--------------------------------------------------------\n";
                                    cin >> x;
                                    if (x == 1)
                                    {
                                        cout << "\nEnter Product Name: " << endl;
                                        string name;
                                        cin.ignore();
                                        getline(cin, name);
                                        searchProduct(name);
                                        return;


                                    }
                                    else if (x == 0)
                                    {
                                        cout << "BAck To Main Menuu" << endl;
                                        return;
                                    }
                                    else {
                                        cout << "In valid Choice" << endl;
                                    }
                                } while (x != 1 && x != 0);

                            }
                            else if (x == 0)
                            {
                                cout << "Proceeding To Checkout" << endl;
                                cartObject.ProcessCheckout();
                                return;
                            }
                            else {
                                cout << "Invalid Choice" << endl;
                            }
                        } while (x != 1 && x != 0);
                    }
                    else if (ch == 0)
                    {
                        return;
                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                    }
                } while (ch != 1 && ch != 0);
            }
            else if (temp->productName > name)
            {
                // left
                temp = temp->left;
            }
            else
            {
                // right
                temp = temp->right;
            }
        }
        cout << "No Product Found Of Name :" << name << endl;
    }
}


bool ConsoleMart::searchByName(string name)
{
    if (root == NULL)
    {
        cout << "No Product added" << endl;
        return false;
    }
    Product* temp = root;
    Product* temp1;
    temp1 = searchByNameHelper(temp, name);
    if (temp1 == NULL)
    {
        cout << "Product Not Found" << endl;
        return false;
    }
    else
    {
        cout<<"\n--------------------------------------------";
        cout << "Product Name : " << temp1->productName << endl;
        cout << "Product Price : " << temp1->productPrice << endl;
        cout << "Product Description : " << temp1->productDescription << endl;
        cout << "Product Available Stock : " << temp1->productStock << endl;
        cout << "Product Rating : " << temp1->productRating;
        cout<<"\n---------------------------------------------\n";
        temp->occurrence += .70;
        return true;
    }
}

Product* ConsoleMart::searchByNameHelper(Product* prod, string n)
{
    Product* temp = prod;
    if (temp == NULL)
    {
        return temp;
    }

    if (temp->productName == n)
    {
        return temp;
    }

    temp = searchByNameHelper(prod->left, n);
    if (temp != NULL)
    {
        return temp;
    }
    else
    {

        return searchByNameHelper(prod->right, n);
    }
}

Product* removeItemHelper(Product* node, string name) {
    if (node == nullptr) {
        cout << "\nProduct not found in the store.";
        return nullptr;
    }

    if (name < node->productName) {
        node->left = removeItemHelper(node->left, name);
    } else if (name > node->productName) {
        node->right = removeItemHelper(node->right, name);
    } else {

        if (node->left == nullptr) {
            Product* temp = node->right;
//            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Product* temp = node->left;
            delete node;
            return temp;
        }

        Product* temp = findMinPriceRecursive(node->right);
        node->productName = temp->productName;
        node->right = removeItemHelper(node->right, name);
    }

    return node;
}


void ConsoleMart::removeItem(string name) {
    root = removeItemHelper(root, name);

    if (root == nullptr) {
        cout << "\nTree is now empty.";
    }
}

//void ConsoleMart::printSortedByOccurrence(Product* root) {
//    if (root == nullptr) {
//        return;
//    }
//
//    printSortedByOccurrence(root->left);
//    
//    if(root->occurrence > 0) {
//        cout << "Product Name: " << root->productName << endl;
//        cout << "Product Category: " << root->productCategory << endl;
//        cout << "Product Price: " << root->productPrice << endl;
//        cout << "---------------------------" << endl;
//    }
//
//    printSortedByOccurrence(root->right);
//}
//
//
//void ConsoleMart::printRecommendations() {
//    printSortedByOccurrence(root);
//}

void ConsoleMart::printSearchHistory(Product* root) {
    if (root == nullptr) {
        return;
    }

    printSearchHistory(root->left);
    
    if(root->searched == true) {
        cout << "Product Name: " << root->productName << endl;
        cout << "Product Category: " << root->productCategory << endl;
        cout << "Product Price: " << root->productPrice << endl;
        cout << "---------------------------" << endl;
    }

    printSearchHistory(root->right);
}

void ConsoleMart::displaySearchHistory() {
    printSearchHistory(root);
}

void ConsoleMart::printPurchaseHistory(Product* root) {
    if (root == nullptr) {
        return;
    }

    printPurchaseHistory(root->left);
    
    if(root->purchased == true) {
        cout << "Product Name: " << root->productName << endl;
        cout << "Product Category: " << root->productCategory << endl;
        cout << "Product Price: " << root->productPrice << endl;
        cout << "---------------------------" << endl;
    }

    printPurchaseHistory(root->right);
}

void ConsoleMart::displayPurchaseHistory() {
    printPurchaseHistory(root);
}

void ConsoleMart::BSTToArray(Product* root, Product* arr[], int &index) {
    if (root == nullptr) {
        return;
    }

    BSTToArray(root->left, arr, index);
    arr[index++] = root;
    BSTToArray(root->right, arr, index);
}

Product** ConsoleMart::BSTToArray() {///
    if (root == nullptr) {
        return nullptr;
    }

    int size = itemCount;
    Product** productArray = new Product*[size];
    int index = 0;

    BSTToArray(root, productArray, index);

    return productArray;
}

void ConsoleMart::sortProductsByOccurrence(Product* arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j]->occurrence < arr[j + 1]->occurrence) {
               
                Product* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ConsoleMart::printSortedProducts(Product* arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if(arr[i]->occurrence > 0) {
            cout << "Product Name: " << arr[i]->productName << endl;
            cout << "Product Price: " << arr[i]->productPrice << endl;
            cout<<"\nCategory: "<<arr[i]->productCategory;
            cout << "--------------------------------------" << endl;
        }
    }
}

void ConsoleMart::recommendations() {
    Product** pr = BSTToArray();
    
    sortProductsByOccurrence(pr, itemCount);
    printSortedProducts(pr, itemCount);
}


void ConsoleMart::ShowCategory(Product* root, string cate)
{
    if (root == NULL)
    {
        return;
    }
    ShowCategory(root->left, cate);
    if (root->productCategory == cate)
    {
        cout << root->productName << " ";
        cout << "Rs. " << root->productPrice << " Only " << endl;
    }
    ShowCategory(root->right, cate);
}

void ConsoleMart::CategoryCall(string cate)
{
    if (root == NULL)
    {
        cout << "No Data Found!" << endl;
        return;
    }
    cout << "----------------------------\n";
    ShowCategory(root, cate);
    cout << "----------------------------\n";

}
//
//void ConsoleMart::calculateTotal(Product* root, Product* byS, Product* byP, int& searchCount, int& purchaseCount)
//{
//    if (root == NULL || (purchaseCount > 2 && searchCount >4))
//        return;
//
//    calculateTotal(root->left, byS, byP, searchCount, purchaseCount);
//    if (root->productCategory == byP->productCategory && purchaseCount <= 1)
//    {
//        cout << root->productName << " ";
//        cout << "Rs. " << root->productPrice << " Only " << endl;
//        //cout << root->category << " \n";
//        purchaseCount++;
//    }
//    else if (root->productCategory == byS->productCategory && searchCount <= 3)
//    {
//        cout << root->productName << " ";
//        cout << "Rs. " << root->productPrice << " Only " << endl;
//        //cout << root->category << " \n";
//        searchCount++;
//    }
//    calculateTotal(root->right, byS, byP, searchCount, purchaseCount);
//}
//void ConsoleMart::calculateTotalCall(Product* bySearch, Product* byPurchase)
//{
//    int c1 = 1, c2 = 1;
//    if (bySearch != NULL && byPurchase != NULL) // this is the case user both searched and purchased
//        calculateTotal(root, bySearch, byPurchase, c1, c2);
//}

