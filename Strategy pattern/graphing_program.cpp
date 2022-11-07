#include<iostream>
using namespace std;

class Graph{
public:
    virtual void draw() const =0;
};

class BarChart: public Graph{
public:
    virtual void draw() const{
        cout<<"Bar Chart has been created"<<endl;
    }
};

class LineGraph: public Graph{
public:
    virtual void draw() const{
        cout<<"Line Graph has been created"<<endl;
    }
};

class Context{
private:
    Graph* graph;

public:
    Context(){}
    void set_graph(Graph* gr){
        graph = gr;
    }
    void draw() const{
        graph->draw();
    }
};

int main(){
    BarChart barchart;
    LineGraph linegraph;

    Context op;
    op.set_graph(&barchart);
    op.draw();

    op.set_graph(&linegraph);
    op.draw();


}
