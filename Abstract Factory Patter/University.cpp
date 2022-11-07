#include<iostream>
using namespace std;

class Degree{
public:
    virtual string Name()=0;
};

class Ba:public Degree{
public:
    string Name(){
        return "BA";
    }
};
class BSc:public Degree{
public:
    string Name(){
        return "BSc";
    }
};


class Course{
public:
    virtual string Name()=0;
};
class DBMS: public Course{
public:
    string Name(){
        return "DBMS";
    }
};


class Ethics: public Course{
public:
    string Name(){
        return "Ethics";
    }
};

class DepartmentFactory{
public:
    enum Department_Factories{
        CSE,
        LAW
    };

    virtual Degree* GetDegree()=0;
    virtual Course* GetCourse()=0;
    static DepartmentFactory* CreateFactory(Department_Factories factory);
};


class CseFactory: public DepartmentFactory{
public:
    Degree* GetDegree(){
        return new BSc();
    }
    Course* GetCourse(){
        return new DBMS();
    }

};
class LawFactory: public DepartmentFactory{
public:
    Degree* GetDegree(){
        return new Ba();
    }
    Course* GetCourse(){
        return new Ethics();
    }
};
DepartmentFactory* DepartmentFactory::CreateFactory(Department_Factories factory){
    if(factory == Department_Factories::CSE){
        return new CseFactory();
    }
    else if(factory == Department_Factories::LAW){
        return new LawFactory();
    }
}


int main(){
    DepartmentFactory* factory = DepartmentFactory::CreateFactory(DepartmentFactory::Department_Factories::CSE);
    cout<<"CSE offering Degree: "<<factory->GetDegree()->Name()<<endl;
    delete factory->GetDegree();
    cout<<"CSE offering Course: "<<factory->GetCourse()->Name()<<endl;
    delete factory->GetCourse();
    delete factory;

    factory = DepartmentFactory::CreateFactory(DepartmentFactory::Department_Factories::LAW);
    cout<<"Law offering Degree: "<<factory->GetDegree()->Name()<<endl;
    delete factory->GetDegree();
    cout<<"Law offering Course: "<<factory->GetCourse()->Name()<<endl;
    delete factory->GetCourse();

}
