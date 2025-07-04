
class Product {
    string name ;
    double price  ;
    int quantity ;
    int ExpirationYear;         //0  :  may expire ,  the real expiration date
    double weight ;             // 0 not shippable  , more is shippable and represent the W
public :

    Product(string name  ,  double price ,  double quantity  ,  int ExpirationYear = 0  , double weight = 0  ) {
        this-> name  = name ;
        this->price = price ;
        this->quantity   =quantity;
        this->ExpirationYear = ExpirationYear  ;
        this->weight = weight ;
    }

    string getName()  {
        return name;
    }
    double getPrice()  {
        return price;
    }

    int  getQuantity () {
        return quantity  ;
    }

    int getExpirationYear() {
        return ExpirationYear ;
    }

    double getWeight () {
        return weight ;
    }

    void take (double quantity)  {
        this->quantity-= quantity ;
    }

    void Return (double quantity)  {
        this->quantity+= quantity ;
    }


    bool operator <  (const Product &other)  const {   // to support using map on it
         return name  < other.name ;
    }

};
