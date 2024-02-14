//
//  main.cpp
//  Console Mart
//
//  Created by Macbook on 31/01/2024.
//

#include <iostream>
#include <chrono>
#include <thread>
#include "Console Mart.hpp"

ConsoleMart mart;

void insertion() {
    string names[] = {"Laptop", "Smartphone", "Headphones", "Coffee Maker", "Fitness Tracker",
                         "Bluetooth Speaker", "Digital Camera", "External Hard Drive", "Wireless Mouse", "Printer",
                         "Gaming Console", "Tablet", "Fitness Equipment", "Smartwatch", "Air Purifier",
                         "Robot Vacuum", "Coffee Grinder", "E-book Reader", "Portable Charger", "Home Theater System"};

       int prices[] = {1200, 800, 100, 60, 90, 70, 500, 150, 30, 200,
                       400, 300, 900, 250, 180, 300, 40, 80, 120, 50, 800};

       int quantities[] = {50, 100, 200, 30, 40, 80, 15, 60, 120, 25,
                           10, 40, 15, 50, 20, 10, 75, 35, 60, 100, 5};

       string categories[] = {"Electronics", "Electronics", "Audio", "Kitchen Appliances", "Wearable Tech",
                              "Audio", "Photography", "Storage", "Computer Accessories", "Office",
                              "Gaming", "Tablets", "Fitness", "Wearable Tech", "Home Appliances",
                              "Home Appliances", "Kitchen Appliances", "Electronics", "Accessories", "Home Theater"};

    string ids[] = {"P001", "P002", "P003", "P004", "P005",
                       "P006", "P007", "P008", "P009", "P010",
                       "P011", "P012", "P013", "P014", "P015",
                       "P016", "P017", "P018", "P019", "P020"};
    string descriptions[] = {
        "High-performance laptop with the latest technology and sleek design.",
        "Feature-packed smartphone with a stunning display and powerful camera.",
        "Premium headphones for an immersive audio experience with noise cancellation.",
        "Versatile coffee maker for brewing your favorite coffee at home.",
        "Advanced fitness tracker to monitor your health and track workouts.",
        "Wireless Bluetooth speaker with crystal-clear sound and long battery life.",
        "Professional-grade digital camera for capturing high-quality photos and videos.",
        "External hard drive for secure storage and fast data transfer.",
        "Ergonomic wireless mouse for precise and comfortable navigation.",
        "All-in-one printer for efficient printing, scanning, and copying tasks.",
        "Latest gaming console with cutting-edge graphics and gaming features.",
        "Sleek tablet for work and entertainment on the go.",
        "Fitness equipment for a full-body workout at home or the gym.",
        "Smartwatch with health tracking and smart features.",
        "Air purifier for cleaner and healthier indoor air.",
        "Smart robot vacuum for automated floor cleaning.",
        "Coffee grinder for freshly ground coffee beans.",
        "E-book reader for a convenient digital reading experience.",
        "Portable charger for keeping your devices powered on the move.",
        "Home theater system for an immersive entertainment experience."
    };
    
    double ratings[] = {4.5, 4.2, 4.0, 3.8, 4.1, 4.3, 4.6, 3.9, 4.8, 4.0,
                        4.7, 4.0, 4.2, 4.5, 3.7, 4.4, 3.5, 4.0, 4.6, 4.2};

    for (int i = 0; i < 20; ++i) {
        Product* product = new Product();
        
        product->productName = names[i];
        product->productPrice = prices[i];
        product->productStock = quantities[i];
        product->productRating = ratings[i];
        product->productCategory = categories[i];
        product->productDescription = descriptions[i];
        
        mart.insertProduct(product);
       
    }
//    Product* newProduct = new Product();
//    newProduct->productName = "Laptop";
}

int main() {
    insertion();
    
    cout<<"\n\t------------------------------------------";
    cout<<"\n\t|         Welcome to Console Mart        |";
    cout<<"\n\t------------------------------------------\n";
    int choice;
    
    do {
        cout<<"\n\t\t--------------------------------";
        cout<<"\n\t\t|          Hot Products        |";
        cout<<"\n\t\t--------------------------------\n";
        mart.recommendations();
        cout<<"\n\t\t----------------------------------------\n";
        
        cout<<"\n\t\t---------------------------------";
        cout<<"\n\t\t* Press 1 for Login             *";
        cout<<"\n\t\t* Press 2 Admin Access          *";
        cout<<"\n\t\t* Press 3 for Browse Product    *";
        cout<<"\n\t\t* Press 4 for Exit              *";
        cout<<"\n\t\t---------------------------------";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;
        
        switch(choice) {
            case 1: {
                cin.ignore();
                string name,password;
                cout<<"\nEnter your name: ";
                getline(cin, name);
                cout<<"\nEnter Password: ";
                cin>>password;
                cout<<"\n\nChecking for information...";
                chrono::seconds duration(3);
                this_thread::sleep_for(duration);
                
                cout<<"\nLogin successfully.";
                
                chrono::seconds newDuration(2);
                this_thread::sleep_for(newDuration);
                
                cout<<"\nWelcome "<<name<<"\n";
                
                int ch;
                do {
                    cout<<"\n\t\t-----------------------------------------";
                    cout<<"\n\t\t* Press 1 for search product by name    *";
                    cout<<"\n\t\t* Press 2 for minimum price product     *";
                    cout<<"\n\t\t* Press 3 for maximum price product     *";
                    cout<<"\n\t\t* Press 4 to display all products       *";
                    cout<<"\n\t\t* Press 5 for Hot Products              *";
                    cout<<"\n\t\t* Press 6 for Browse History            *";
                    cout<<"\n\t\t* Press 7 for Purchase History          *";
                    cout<<"\n\t\t* Press 8 for back to main menu         *";
                    cout<<"\n\t\t-----------------------------------------";
                    cout<<"\n\nEnter your choice: ";
                    cin>>ch;
                    
                    switch(ch) {
                        case 1: {
                            cin.ignore();
                            string productName;
                            cout<<"\nEnter the name of the product: ";
                            getline(cin, productName);
                            mart.searchProduct(productName);
                            break;
                        }
                        case 2: {
                            Product* minPriceProduct = mart.findMinPrice();

                            if (minPriceProduct != nullptr) {
                                cout<<"\n\t------------------------------------------";
                                cout<<"\n\t|         Minimum Price Product          |";
                                cout<<"\n\t------------------------------------------";
                                cout << "\nName: " << minPriceProduct->productName;
                                cout << "\nCategory: " << minPriceProduct->productCategory;
                                cout << "\nPrice: " << minPriceProduct->productPrice;
                            } else {
                                cout << "\nNo products found in the store.";
                            }
                            break;
                        }
                        case 3: {
                            Product* maxPriceProduct = mart.findMaxPrice();

                            if (maxPriceProduct != nullptr) {
                                cout<<"\n\t------------------------------------------";
                                cout<<"\n\t|         Maximum Price Product          |";
                                cout<<"\n\t------------------------------------------";
                                cout << "\nName: " << maxPriceProduct->productName;
                                cout << "\nCategory: " << maxPriceProduct->productCategory;
                                cout << "\nPrice: " << maxPriceProduct->productPrice;
                            } else {
                                cout << "\nNo products found in the store.";
                            }

                            break;
                        }
                        case 4: {
                            mart.displayPreorder(mart.root);
                            break;
                        }
                        case 5: {
                            cout<<"\n\t\t--------------------------------";
                            cout<<"\n\t\t|          Recommendations      |";
                            cout<<"\n\t\t--------------------------------\n";
                            mart.recommendations();
                            cout<<"\n\t\t----------------------------------------\n";
                        }
                        case 6: {
                            mart.displaySearchHistory();
                            break;
                        }
                        case 7: {
                            mart.displayPurchaseHistory();
                            break;
                        }
                        default:
                            cout<<"\nInvalid choice.";
                            
                    }
                }while(ch != 8);
    
                break;
            }
            case 2: {
                cin.ignore();
                string name,password;
                cout<<"\nEnter name: ";
                getline(cin,name);
                cout<<"\nEnter your password: ";
                cin>>password;
                
                cout<<"\n\nChecking for information...";
                chrono::seconds duration(3);
                this_thread::sleep_for(duration);
                
                int ch;
                do {
                    cout<<"\n\t\t---------------------------------";
                    cout<<"\n\t\t* Press 1 for insert Product    *";
                    cout<<"\n\t\t* Press 2 for remove Product    *";
                    cout<<"\n\t\t* Press 3 for update Product    *";
                    cout<<"\n\t\t* Press 4 for search Product    *";
                    cout<<"\n\t\t* Press 5 for back to main menu *";
                    cout<<"\n\t\t---------------------------------";
                    cout<<"\n\nEnter your choice: ";
                    cin>>ch;
                    
                    switch(ch) {
                        case 1: {
                            cin.ignore();
                            int price,qunatity;
                            string name,category;
                            
                            cout<<"\nEnter the name of the product: ";
                            getline(cin,name);
                            cout<<"\nEnter the price of the product: ";
                            cin>>price;
                            cout<<"\nEnter the category of the product: ";
                            cin>>category;
                            cout<<"\nEnter the qunatity of the product: ";
                            cin>>qunatity;
                            
                            Product* product = new Product();
                            product->productName = name;
                            product->productStock = qunatity;
                            product->productCategory = category;
                            
                            mart.insertProduct(product);
                            delete product;
                            break;
                        }
                        case 2: {
                            cin.ignore();
                            string productName;
                            cout<<"\nEnter the name of the product: ";
                            getline(cin, productName);
                            
                            mart.removeItem(productName);
                            break;
                        }
                        case 3: {
                            cin.ignore();
                            string productName;
                            cout<<"\nEnter the name of the product: ";
                            getline(cin, productName);
                            
                            mart.updateProduct(productName);
                            break;
                        }
                        case 4: {
                            cin.ignore();
                            string productName;
                            cout<<"\nEnter the name of the product: ";
                            getline(cin, productName);
                            
                            mart.searchProduct(productName);
                            break;
                        }
                        default:
                            cout<<"\nInvalid choice.";
                    }
                }while(ch != 5);
                break;
            }
            case 3: {
                cin.ignore();
                string productName;
                cout<<"\nEnter the name of the product: ";
                getline(cin, productName);
                
                mart.searchProduct(productName);
                break;
            }
            case 4: {
                cout<<"\nThanks for shopping.\n";
                return 0;
            }
            default:
                cout<<"\nInvalid choice.";
        }
        
    }while(true);
        
        return 0;
}

