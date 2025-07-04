#include <bits/stdc++.h>
#include<Product.cpp>
using namespace std;
const int CurrenYear = 2025 ;

class ShippingService {
    int costPerKilo= 10;
    vector < pair < Product  , int >  >  items ;

public :

    ShippingService( vector < pair < Product  , int >  >  items )  {
        this->items = items;
    }

    string getName(int idx)  {
            return items[idx].first.getName() ;
    }

    double getWeight(int idx)  {
            return items[idx].first.getWeight() ;
    }

    long double getCost()  {
        double costShiping = 0 , totalWeight = 0 ; ;
        for (int  i  =  0 ;  i  < items.size() ;  ++i)  {
            int cnt = items[i].second ;
            costShiping+= cnt  *items[i].first.getPrice()  * items[i].first.getWeight();  ;

        }
        return costShiping;
   }

    void display()  {       // return ship cost
        double totalWeight = 0 ; ;

        for (int  i  =  0 ;  i  < items.size() ;  ++i)  {
            int cnt = items[i].second ;
            if(getWeight(i)  == 0 )continue ;

            cout<<cnt <<"X " <<getName(i) <<" "<<cnt  * getWeight(i) <<"\n " ;
            totalWeight+= cnt*getWeight(i) ;
        }

        cout<<"Total package weight "<<  totalWeight <<"\n";
    }


};
