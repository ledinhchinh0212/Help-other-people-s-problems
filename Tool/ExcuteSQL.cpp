#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

enum TypeDate
{
    VARCHAR,
    INT,
    DOUBLE
};

int DemCau(const string &s)
{
    string empty;
    vector<string> v;
    stringstream ss(s);
    while(ss >> empty)
    {
        v.push_back(empty);
    }
    return v.size();
}

void ViTriCacChuoi(const string &raw)
{
    int n = raw.length();
    for(int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++)
    {
        if(i > 10)
        {
            cout << " " << raw[i] << " ";
        }
        else if(i > 100)
        {
            cout << "  " << raw[i] << "  ";
        }
        else cout << raw[i] << " ";
    }
}

string trim(const string &s)
{
    string out2 = "";
    stringstream ss(s);
    string empty;
    vector<string> v;
    while(ss >> empty)
    {
        v.push_back(empty);
    }
    for(const string &x : v)
    {
        out2 = out2 + x + " ";
    }
    return out2;
}

vector<string> tachChuoi(vector<string> dongSQL[], vector<int> dataType, int batDauCau, int ketThucCau)
{
    
}

int main()
{
    vector<int> dataType;
    cout << "Nhap so dong: ";
    int soDong; cin >> soDong;
    cout << "Nhap so cot: ";
    int soCot; cin >> soCot;
    cout << "Nhap kieu du lieu cua tung cot:\n";
    for(int i = 0; i < soCot; i++)
    {
        cout << "0. VARCHAR, 1. INT, 2.DOUBLE/FLOAT: ";
        int type; cin >> type;
        if(type == INT) dataType.push_back(INT);
        if(type == VARCHAR) dataType.push_back(VARCHAR);
        if(type == DOUBLE) dataType.push_back(DOUBLE);
    }
    int testCase = soDong;
    vector<string> dongSQL[soDong];
    vector<string> containsSQL(soDong);
    int batDauCau = -1, ketThucCau = -1;
    bool chinhCau = false;
    cin.ignore();
    while(testCase > 0)
    {
        string inputSQL;
        getline(cin, inputSQL);

        if(DemCau(inputSQL) > soCot)
        {
            cout << "So tu trong cau lon hon so cot\n";
            ViTriCacChuoi(inputSQL);
            cout << "\nNhap vi tri bat dau va ket thuc de gop thanh mot kieu du liet:\n";
            int start, end; cin >> start >> end; cin.ignore();
            int count = 1;
            inputSQL = trim(inputSQL);
            string temp = "";
            
            for(int i = 0; i  < inputSQL.length(); i++)
            { 
                char ch = inputSQL[i];
                if(ch == ' ')
                {   
                    if(batDauCau == -1)
                    {
                        batDauCau = i;
                    }
                    else ketThucCau = i;
                    dongSQL[soDong - testCase + 1].push_back(temp);
                    count++;
                    temp = "";
                }
                else
                {
                    temp += ch;
                }
            }
        }

        testCase--;
    }

    return 0;
}