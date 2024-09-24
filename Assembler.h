#include <bits/stdc++.h>

using namespace std;

string opcode(string ins)
{
    if (ins == "LOAD")
        return "00000001";
        
    else if (ins == "STOR")
        return "00100001";
    
    else if (ins == "TRUN")
        return "00100011";
        
    else if (ins == "DIVI")
        return "00001100";
        
    else if (ins == "ADDD")
        return "00000101";
        
    else if (ins == "JUMP")
        return "00001101";
        
    else if (ins == "POWR")
        return "00100010";
    else
        return "0";
}

string binary(int n)
{
    if (n==0)
        return "0";
        
    else if (n==1)
        return "01";
    
    else
    {
        if (n%2 == 0)
            return (binary(n/2) + "0");
            
        else
            return (binary(n/2) + "1");
    }
}

string add0(string x)
{
    int n;
    n = 12 - x.size();
    for (int i=0; i<n; i++)
        x = '0' + x;
    return x;
}

string ctos(char x) // converts char to string
{
    string s(1, x);
    return s;   
}

string * input(string* m)
{
    cout<< "Enter instructions:"<< endl;
    int i = 250;
    
    while (1)
    {
        char a[25];
        cin.getline(a, 25, '\n');
        string x = a;
        
        if (x == "EXIT")
            break;
            
        else
        {
            string y;
            string bin;
            
            if (x.substr(0,4) == "JUMP")
            {
                y = "00000000000000000000";
                y = y + opcode(x.substr(0,4));
                bin = binary(stoi(x.substr(7,10)));
                bin = add0(bin);
                y = y + bin;
            }
            
            else if (x.size() == 19)
            {
                if (x.substr(0,9) == "LOAD (MQ)")
                {
                    y = "00001010000000000000";
                    y = y + opcode(x.substr(10, 4));
                    bin = binary(stoi(ctos(x[17])));
                    bin = add0(bin);
                    y = y + bin;
                }
                
                else
                {
                    y = opcode(x.substr(0,4));
                    bin = binary(stoi(ctos(x[7])));
                    bin = add0(bin);
                    y = y + bin;
                    y = y + opcode(x.substr(10, 4));
                    bin = binary(stoi(ctos(x[17])));
                    bin = add0(bin);
                    y = y + bin;
                }
            }
            
            else if (x.size() == 9)
            {
                y = "00000000000000000000";
                y = y + opcode(x.substr(0,4));
                bin = binary(stoi(ctos(x[7])));
                bin = add0(bin);
                y = y + bin;
            }
            
            else if (x.size() == 14)
            {
                y = opcode(x.substr(0,4));
                bin = binary(stoi(ctos(x[7])));
                bin = add0(bin);
                y = y + bin;
                y = y + opcode(x.substr(10, 14));
                y = y + "000000000000";
            }
            
            m[i++] = y;
            
        }
    }

    cout<<'\n';
    cout<< "Machine Language Program:"<< endl;
    for (int i=250; i<257; i++)
        cout<<m[i]<<endl;
    cout<<'\n';

    return m;
}