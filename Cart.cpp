#include <bits/stdc++.h>
#include<Product.cpp>
using namespace std;
const int CurrenYear = 2025 ;

class Cart {
    double totalCost  = 0 ;
    map  <Product  , int >  Products;    //to support adding same product multi times with one key [Procut   , hw many times i take this product in cart]
public  :

    void add ( Product& product , int  quantity )  {
        if (product.getQuantity()  < quantity)  {
            cout <<" adding can't be completed  There are no enough " << product.getName() <<"\n" ;
            return ;
        }
        Products[product]+=quantity ;
        totalCost+= product.getPrice() * quantity ;
        product.take(quantity) ;
        cout<<"Added Successfully\n" ;
    }

    void Return ( Product& product , int  quantity )  {       //not required but it's logicaly
        if (Products[product]   <  quantity)  {
            cout <<" Return can't be completed  because the asked amount isn't in the cart  " << product.getName() <<"\n" ;
            return ;
        }
        Products[product]-=quantity ;
        totalCost-= product.getPrice() * quantity ;
        product.Return(quantity) ;
        cout<<"Returned Successfully\n" ;
    }



    vector <pair < Product , int > >  getProducts()  {
        vector<pair <Product  , int > >  ret;
        for (auto [product , freq]   : Products)  {
            if (freq)  {
                ret.push_back({product ,  freq}) ;
            }
        }
        return ret;
    }

    double getTotalCost()  {
            return totalCost ;
    }


};
