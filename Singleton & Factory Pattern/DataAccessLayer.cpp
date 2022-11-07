#include<iostream>
using namespace std;

enum DatabaseEngines{
    MSSQL, MySQL, Oracle
};

enum Create{
    Views, Commands, Tables, Adapters
};


class DataAccessLayer{
public:

    virtual void ConnectEngine()=0;
};


class mssql:public DataAccessLayer{
private:
    static bool check_mssql;
    static mssql *singleton_mssql;
    mssql(){
        cout<<"Private MSSQL constructor"<<endl;
    }
public:

    static mssql* getInstanceMSSQL(){
        if(!check_mssql){
            singleton_mssql = new mssql();
            check_mssql=true;
            return singleton_mssql;
        }
        else{
            return singleton_mssql;
        }
    }
    void ConnectEngine(){
        cout<<"Connected to MSSQL"<<endl;
    }


    ~mssql(){
        check_mssql=false;
    }
};
bool mssql::check_mssql=false;
mssql* mssql::singleton_mssql=NULL;

class mysql:public DataAccessLayer{
private:
    static bool check_mysql;
    static mysql *singleton_mysql;
    mysql(){
        cout<<"Private MySQL constructor"<<endl;
    }
public:
    static mysql* getInstanceMYSQL(){
        if(!check_mysql){
            singleton_mysql = new mysql();
            check_mysql=true;
            return singleton_mysql;
        }
        else{
            return singleton_mysql;
        }
    }
    void ConnectEngine(){
        cout<<"Connected to MySQL"<<endl;
    }

    ~mysql(){
        check_mysql=false;
    }
};
bool mysql::check_mysql=false;
mysql* mysql::singleton_mysql=NULL;

class oracle:public DataAccessLayer{
private:
    static bool check_oracle;
    static oracle *singleton_oracle;
    oracle(){
        cout<<"Private oracle constructor"<<endl;
    }
public:
    static oracle* getInstanceORACLE(){
        if(!check_oracle){
            singleton_oracle = new oracle();
            check_oracle=true;
            return singleton_oracle;
        }
        else{
            return singleton_oracle;
        }
    }
    void ConnectEngine(){
        cout<<"Connected to Oracle"<<endl;
    }

    ~oracle(){
        check_oracle=false;
    }
};
bool oracle::check_oracle=false;
oracle* oracle::singleton_oracle=NULL;

class DataAccessOperation{
public:
    virtual void SelectOperation()=0;
};
class views: public DataAccessOperation{
public:
    void SelectOperation(){
        cout<<"Create View Operation"<<endl;
    }
};
class commands: public DataAccessOperation{
public:
    void SelectOperation(){
        cout<<"Create Command Operation"<<endl;
    }
};
class tables: public DataAccessOperation{
public:
    void SelectOperation(){
        cout<<"Create Table Operation"<<endl;
    }
};
class adapters: public DataAccessOperation{
public:
    void SelectOperation(){
        cout<<"Create Adapter Operation"<<endl;
    }
};

class Factory{
public:
    Factory(){
        cout<<"This is Facotry"<<endl;
    }
    static DataAccessOperation* createOperation(Create opr){
        if(opr == Views){
            return new views();

        }
        else if(opr == Commands){

            return new commands();
        }
        else if(opr == Tables){

            return new tables();
        }
        else if(opr == Adapters){
            return new adapters();
        }
        else{
            return NULL;
        }
    }
    static DataAccessLayer* create(DatabaseEngines engine){
        if(engine == MSSQL){
            mssql *mssql_ptr = mssql::getInstanceMSSQL();
            return mssql_ptr;

        }
        else if(engine == MySQL){
            mysql *mysql_ptr = mysql::getInstanceMYSQL();
            return mysql_ptr;
        }
        else if(engine == Oracle){
            oracle *oracle_ptr = oracle::getInstanceORACLE();
            return oracle_ptr;
        }
        else{
            return NULL;
        }
    }


};


int main(){
    DataAccessLayer* MSSQL_Singleton_ptr = Factory::create(MSSQL);
    MSSQL_Singleton_ptr->ConnectEngine();


    DataAccessLayer* MySQL_Singleton_ptr = Factory::create(MySQL);
    MySQL_Singleton_ptr->ConnectEngine();

    DataAccessLayer* Oracle_Singleton_ptr = Factory::create(Oracle);
    Oracle_Singleton_ptr->ConnectEngine();
    cout<<"------------------"<<endl;
    DataAccessOperation* views_ptr = Factory::createOperation(Views);
    views_ptr->SelectOperation();

    DataAccessOperation* commands_ptr = Factory::createOperation(Commands);
    commands_ptr->SelectOperation();

    DataAccessOperation* tables_ptr = Factory::createOperation(Tables);
    tables_ptr->SelectOperation();

    DataAccessOperation* adapter_ptr = Factory::createOperation(Adapters);
    adapter_ptr->SelectOperation();



}
