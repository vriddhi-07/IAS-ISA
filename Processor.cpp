#include <bits/stdc++.h>
#include "IMT2023611_IMT2023585_Assembler.h"
using namespace std;

string MAR, IR, IBR;
string* memory = new string[1000];
int PC = 250, MQ;
float AC, MBR, M[4] = { 1, 10, 2, 0 };
// M = {n, 10, 2, s} where n = number, s = sum of digits

void execute(string op, string add)
{
    // LOAD M(X)
    if (op == "00000001")
    {
        MBR = M[stoi(add,0,2)];
        AC = MBR;
        cout<<"PC :"<< PC<< endl;
        cout<<"AC: "<< AC << endl;
        cout<< "-----------------------" << endl;
    }
    
    // STOR M(X)
    else if (op == "00100001")
    {
        MBR = AC;
        M[stoi(add,0,2)] = MBR;
        cout<<"PC :"<< PC<< endl;
        cout<<"AC: "<< AC << endl;
        cout<< "-----------------------" << endl;
    }
    
    // ADD M(X)
    else if (op == "00000101")
    {
        MBR = M[stoi(add,0,2)];
        AC = AC + MBR;
        cout<<"PC :"<< PC<< endl;
        cout<<"AC: "<< AC << endl;
        cout<< "-----------------------" << endl;
    }
    
    // DIV M(X)
    else if (op == "00001100")
    {
        MBR = M[stoi(add,0,2)];
        MQ = AC / MBR;
        AC = (int)AC % (int)MBR;
        cout<<"PC :"<< PC<< endl;
        cout<<"AC: "<< AC << endl;
        cout<<"MQ: "<< MQ << endl;
        cout<< "-----------------------" << endl;
    }
    
    // LOAD MQ
    else if (op == "00001010")
    {
        MBR = MQ;
        AC = MBR;
        cout<<"PC :"<< PC<< endl;
        cout<<"AC: "<< AC << endl;
        cout<< "-----------------------" << endl;
    }
    
    // POW M(X) // AC = AC ** M(X)
    else if (op == "00100010")
    {
        MBR = M[stoi(add,0,2)];
        AC = pow(AC, MBR);
        cout<<"PC :"<< PC<< endl;
        cout<<"AC: "<< AC << endl;
        cout<< "-----------------------" << endl;
    }
    
    // TRUNC  // Truncates AC // AC = TRUNC AC
    else if (op == "00100011")
    {
        AC = (int)AC;
        cout<<"PC :"<< PC<< endl;
        cout<<"AC: "<< AC << endl;
        cout<< "-----------------------" << endl;
    }
    
    // JUMP M(X, 0:19)
    else if (op == "00001101")
    {
        PC = 252;
        cout<<"PC :"<< PC<< endl;
        cout<< "-----------------------" << endl;
    }
    
}

void decoder(string ins)
{
    
    // lhs = left instruction, rhs = right instruction
    // Lop = left opcode Rop = right opcode
    // Ladd = left address, Radd = right  address
    string lhs, rhs, Lop, Rop, Ladd, Radd;

    MAR = to_string(PC);
    string MBR = memory[stoi(MAR)];

    lhs = ins.substr(0,20);
    Lop = lhs.substr(0,8);
    Ladd = lhs.substr(8,20);
    
    rhs = ins.substr(20,40);
    Rop = rhs.substr(0,8);
    Radd = rhs.substr(8,20);
    
    MAR = Ladd;
    IR = Lop;
    IBR = rhs;
    PC++ ;
    
    execute(Lop, Ladd);
    
    MAR = Radd;
    IR = Rop;

    execute(Rop, Radd);

}


int main() {
    
    memory = input(memory);
    float n;
    cout<< "Enter a number:"<< endl;
    cin>>n;
    cout<< "-----------------------" << endl;
    M[0] = n;
    
    decoder(memory[250]);
    decoder(memory[251]);
    
    int N = 252;
    
    while (M[0]>0)
    {
        decoder(memory[N]);
        
        if (memory[N].substr(20,8) == "00001101")
            N = 252;
            
        else
            N++;
    }
    cout<< "The sum of squares of digits = "<< M[3]<< endl;
    return 0;
}