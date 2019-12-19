#include <map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Trace{
    public:
        static map<string, vector<string> > debug_data;
        static vector<string>               total_debug_data;
        static void put(string tag, string debug_data);
        static void put(string tag);
        static void put();
};

map<string, vector<string> > 
Trace::debug_data;
vector<string> 
Trace::total_debug_data;

void Trace::put(string tag, string data)
{
    debug_data[tag].push_back(data);
    total_debug_data.push_back(data);
}

void Trace::put(string tag)
{
    cout<< "-Printing " << tag << "s debugging data-" << endl;
    for(int i=0;i<debug_data[tag].size();i++)
    {
        cout << debug_data[tag][i]<<endl;
    }
}

void Trace::put()
{
    cout << "-total debugging data-" << endl;
    for(int i=0;i<total_debug_data.size();i++)
    {
        cout << total_debug_data[i] <<endl;
    }

}

void f()
{
    int a,b,c;
    cout << "Input two numbers: ";
    cin >> a >> b;
    Trace::put("f()","Getting integers");
    c = a+b;
    Trace::put("f()","Summation");
    cout << "Sum is " << c << endl;
}

int main(void)
{
    Trace::put("main","Starting Program!");
    f();
    Trace::put("main", "Terminate");

    Trace::put("f()");
    Trace::put();
}