#include <iostream>
using namespace std;
#include <ctime>
#include <fstream>

const float priceList[20] = {865, 2.25, 44, 10, 20, 7710, 33.33, 48.97, 8, .5, 0.001, 88, 999, 25000, 87, 4, 22, 200, 20, 150};

class PO;
class requisition
{
    static int reqNO;
    int itemCode;
    string deliveryDate;
    int quantity;

public:
    void getData();
    void display();
    friend void generate(requisition, PO);
};
int requisition::reqNO = 0;

void requisition::getData()
{
    reqNO++;
    cout << "Enter Item Code: " << endl;
    cin >> itemCode;
    cout << "Quantity: \n";
    cin >> quantity;
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Delivary Date: ";
    getline(cin, deliveryDate);
}

void requisition::display()
{
    cout << "Requisition Number: " << reqNO << endl;
    cout << "Item code: " << itemCode << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Delivary Date: " << deliveryDate << endl;
}

class PO
{
    static int po_no;

public:
    PO()
    {
        po_no++;
    }
    friend void generate(requisition, PO);
};
int PO::po_no = 0;

void generate(requisition r, PO p)
{
    ofstream fout;
    time_t current = time(NULL);
    char *dt = ctime(&current);

    fout.open("Current_PO.txt");
    fout << "\t\t\t        Purchase Order : " << p.po_no << endl;

    fout << "\t\t\t-------------------------------\n\n";
    fout << "Requisition : " << r.reqNO << "\t\t\t\tIssue Date : " << dt << "\n\n";

    if (r.itemCode >= 1 && r.itemCode <= 10)
        fout << "Supplier : SKS Inc."
             << "\n\n";
    else if (r.itemCode > 10 && r.itemCode <= 20)
        fout << "Supplier : KC Spare Parts Ltd."
             << "\n\n";
    else
        fout << "Supplier : Other(______________________________________________)"
             << "\n\n";

    fout << "Delivery Date: " << r.deliveryDate << endl;
    fout << "--------------------------------------------------------------------------------" << endl;
    fout << "                            Line Items\n";
    fout << "--------------------------------------------------------------------------------" << endl;
    fout << "Item Code\t\t\t\tQuantity\t\t\t\t\tPrice\t\t\t\tTotal\n";
    fout << "\t" << r.itemCode << "\t\t\t\t\t\t" << r.quantity << "\t\t\t\t\t\t " << priceList[r.itemCode] << "\t\t\t\t     " << r.quantity * priceList[r.itemCode] << "\n\n";
    fout << "--------------------------------------------------------------------------------" << endl;

    ifstream fin;
    string read;
    fin.open("po_term.txt");

    while (fin)
    {
        getline(fin, read);
        fout << read;
        fout << "\n";
    }
    fout << "\n";

    fout << "Signature:\t\t\t\t\t\t\t\tTotal:________" << endl;
}
int main()
{
    requisition r;
    int selection, flag = 0;
loop:
    cout << "\t\t\t\t\t\t\t\t   PR2PO" << endl;
    cout << "\t\t\t\t\t\t\t\t------------" << endl;
    cout << "\t\t\t\t\t1 - Create New Requisition" << endl;
    cout << "\t\t\t\t\t2 - Display Requisition" << endl;
    cout << "\t\t\t\t\t3 - Generate PO" << endl;
    cout << "\t\t\t\t\t4 - Exit" << endl;
    cin >> selection;

    switch (selection)
    {
    case 1:
        flag++;
        r.getData();
        break;
    case 2:
        if (flag == 0)
            cout << "Requisition details not entered yet!!!" << endl;
        else
        {
            r.display();
        }
        break;
    case 3:
        if (flag == 1)
        {
            PO po;
            generate(r, po);
            cout << "PR has been converted into PO" << endl;
        }
        else
            cout << "Requisition details not entered yet!!!" << endl;
        break;

    case 4:
        exit(1);

    default:
        cout << "Enter a Vaild selection " << endl;
        break;
    }
    goto loop;
    return 0;
}