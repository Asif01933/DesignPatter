#include<bits/stdc++.h>
using namespace std;
//Component
class Shop{
public:
    virtual string Products()=0;
    virtual double Cost()=0;
    virtual ~Shop(){}
};
//Concrete Component
class Shampoo:public Shop{
public:
    string Products(){
        return "Product Shampoo";
    }
    double Cost(){
        return 90.00;
    }

};



//Decorator
class ShopDecorator: public Shop{
protected:
    Shop *O_Shop;
public:
    ShopDecorator(Shop *Shampoo):O_Shop(Shampoo){}
    string Product(){
        return O_Shop->Products();
    }
    double Cost(){
        return O_Shop->Cost();
    }
};

//Concrete Decorator
class Vats: public ShopDecorator{
public:
    Vats(Shop *Shampoo):ShopDecorator(Shampoo){}
    string Products(){
        return O_Shop->Products()+"Adding vat";
    }
    double CurrentCost = O_Shop->Cost();
    double WithVat = CurrentCost + ((15/CurrentCost)*100);
    double Cost(){
        return WithVat;
    }

};

class Shipping: public ShopDecorator{
public:
    Shipping(Shop * Shampoo):ShopDecorator(Shampoo){}
    string Products(){
        return O_Shop->Products()+"Add shipping";
    }
    double CurrentCost = O_Shop->Cost();
    double distance = 14.4;
    double WithShipping = CurrentCost + (distance*3);
    double Cost(){
        return WithShipping;
    }

};

class Discount: public ShopDecorator{
public:
    Discount(Shop * Shampoo):ShopDecorator(Shampoo){}
    string Products(){
        return O_Shop->Products()+"Add Discount";
    }
    double CurrentCost = O_Shop->Cost();
    double WithDiscount = CurrentCost - ((5/CurrentCost)*100);
    double Cost(){
        return WithDiscount;
    }

};

class Tax: public ShopDecorator{
public:
    Tax(Shop * Shampoo):ShopDecorator(Shampoo){}
    string Products(){
        return O_Shop->Products()+"Add Tax";
    }

    double Cost(){
        return O_Shop->Cost()+5;
    }

};
class Free: public ShopDecorator{
public:
    Free(Shop * Shampoo):ShopDecorator(Shampoo){}
    string Products(){
        return O_Shop->Products()+"Add Free";
    }
    double Cost(){
        return 0;
    }

};

int main(){
    Shop *shampoo = new Shampoo();

    cout<<shampoo->Products()<<endl;
    cout<<"Actual Price of Shampoo: ";
    cout<<shampoo->Cost()<<endl;

    cout<<"With Vats, Shipping and Tax(Without Discount): ";
    Shop *decorated_shop1 = new Vats(new Shipping(new Tax(new Shampoo()))) ;

    cout<<decorated_shop1->Cost()<<endl;
    cout<<"During Eid total Cost: ";
    Shop *decorated_shop2 = new Free(new Shampoo());
    cout<<decorated_shop2->Cost()<<endl;
    cout<<"With Vat, Tax, Shipping and Discount: ";
    Shop *decorated_shop3 = new Discount(new Vats(new Shipping(new Tax(new Shampoo())))) ;
    cout<<decorated_shop3->Cost()<<endl;

}
