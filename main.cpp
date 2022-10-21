
#include "readport.h"

using namespace std;
string dec2hex(int i)
{
    auto mulnus=i<0;
    if (mulnus)
        i= abs(i);
    if (i==0)
    {
        return "0";
    }
    string result;
    string tmp="";
    auto last=i;
    while (i>0)
    {
        last=i/16;
        if (i%16>=10)
        {
            tmp='A'+(i%16-10);
            result=tmp+result;
        }
        else result= to_string(i%16)+result;
        i=last;
    }
    result=mulnus?"-"+result:result;
        return result;
}


int main() {
    //cout<<dec2hex(-25551)<<endl;
    std::cout << "Hello, World!" << std::endl;
    WZSerialPort wzSerialPort;

    cout<<wzSerialPort.open("COM3",9600)<<endl;
    while (1)
    {
        auto a=wzSerialPort.hex_recv();
        cout<<a<<endl;
        cout<<dec2hex(a)<<endl;//F8 248 0011 0100
        //system("pause");
    }

    return 0;
}

