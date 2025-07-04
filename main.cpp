#include <bits/stdc++.h>
#include<Product.cpp> 
#include<Cart.cpp>
#include<Customer.cpp>
using namespace std;
const int CurrenYear = 2025 ;


int32_t main() {




      Product Cheese( "Cheese" ,  10 ,  100  ,  2026  ,  1  ) ;
      Product Biscuits( "Biscuits" ,  10 ,  100  ,  2026  ,  1  ) ;
      Product TV( "TV" ,  1000 ,  10 ) ;
      Product Mobile( "TV" ,  500 ,  30 ) ;

    vector < Product >  products =  {Cheese , Biscuits , TV , Mobile};


      Customer customer("Hisham" , 1000) ;

      while(true)  {
             cout<<"Hi  " << customer.getName() <<" Your balance is "<<customer.getBalance()<<" \n";
             cout<<"------------------------------how can i help you ^_^-- -------------------------\n" ;
             cout<<"Enter 1 for check out  || 2 for clear screen ||  3 for adding product   || 4 for return Product\n"  ;

             int q ;
             cin >> q ;

             if (q==2)  {
                     system("cls");
                     continue;
             }

             else if (q==1) {
                    customer.CheckOut() ;
             }else if (q == 3)   {
                 string name ;
                 int quantity ;
                 cout<<"Enter the product name and quantity you want to add\n" ;
                 cin >> name >> quantity ;

                 bool found = false ;
                 for (int i = 0 ; i < products.size() ;  ++i)  {
                     if (products[i].getName() == name)  {
                         customer.addProduct(products[i] , quantity) ;
                         found = true ;
                         break ;
                     }
                 }
                 if (!found)    cout<<"Product not found\n" ;
                 else cout<<"\n" ;
             }else  {
                 string name ;
                 int quantity ;
                 cout<<"Enter the product name and quantity you want to return\n" ;
                 cin>> name >> quantity ;
                 bool found = false ;
                 for (int i = 0 ; i < products.size() ;  ++i)  {
                     if (products[i].getName() == name)  {
                         customer.Return(products[i] , quantity) ;
                         found = true ;
                         break ;
                     }
                 }
                 if (!found)    cout<<"Product not found\n" ;
                 else cout<<"\n" ;
             }
      }


}
