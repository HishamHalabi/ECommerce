#include <bits/stdc++.h>
#include<Product.cpp>
#include <Cart.cpp>
using namespace std;
const int CurrenYear = 2025 ;

class Customer   {
    string name;
    double balance  ;
    Cart mycart ;
public  :

    Customer() {
        balance = 0 ;
    }

    Customer(string name  , double balance)  {
        this-> name=name ;
        this->balance = balance ;
    }

    double getBalance()  {
        return balance ;
    }

    string getName()  {
        return name ;
}

    void addProduct(Product &product , int quantity)  {
           mycart.add(product  ,  quantity) ;      //it will check for availability
    }

    void Return (Product&product ,  int quantity)  {
        mycart.Return(product  ,  quantity) ;
    }


    void CheckOut()  {
        cout<<"** Checkout receipt **\n";

        auto products   =  mycart.getProducts() ;
        if (products.empty())  {
                   cout<<"Cart is empty\n" ;
                   return  ;
        }

        ShippingService ship(products) ;
        long double totalCost  =  mycart.getTotalCost()   +   ship.getCost() ;

        if(balance <  totalCost)  {
              cout<<"insufficent balance\n" ;
              return  ;
        }

        for (int i = 0 ;  i <products.size() ;  ++i)  {
                 if (products[i].first.getExpirationYear()   <  CurrentYear)  {
                              cout<<"Product "<<products[i].first.getName() <<" is  expired u can return it again\n" ;
                               return ; 
                 }
        }

        balance-= totalCost ;


        ship.display() ;
        cout<<"\n_________________________\n\n" ;

        long double subtotal  = 0 ;
        for (int i = 0 ; i  < products.size() ;  ++i) {
            int cnt = products[i].second ;
            cout<<cnt <<"X " <<products[i].first.getName() <<" "<<cnt  * products[i].first.getPrice() <<"\n " ;
            subtotal+=cnt * products[i].first.getPrice() ;
        }
        cout<<"____________________\nSubtotal  "<<subtotal <<"\n";
        cout<<"Shippment  " << ship.getCost() <<"\n";
        cout<<"Amount  "<<subtotal  + ship.getCost() <<"\n";
    }



};
