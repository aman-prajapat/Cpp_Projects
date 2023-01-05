#include <iostream>
using namespace std;
#include<fstream>

class applicant
{
    int score;
    int age;
    int liability;
    int cheque_bounce;
    string address;
    string name;
    int home_lone;
    int personal_lone;
    char own_house;
    char spouse_working;
    char dependent_parents;
    int company_tier;
    int monthly_salary;

public:
    applicant(){
        score = 0;
    }
    void get_data();
    void calc_liability();
    void display_score();
};

void applicant::get_data()
{
    cin.clear();
    cin.ignore(1000, '\n');
cout<<"\n----------------------------------------- \n";
cout<<"\n----------------------------------------- \n";
    cout << "Enter Name of Applicant: ";
    getline(cin, name);
    cout << "Permanent Address: ";
    getline(cin, address);

    cout << "Enter Age of Applicant: ";
    cin >> age;
    cout << "Enter home loan EMI: ";
    cin >> home_lone;
    cout << "Enter Personal loan EMI: ";
    cin >> personal_lone;
    cout << "Monthly Salary: ";
    cin >> monthly_salary;
    cout << "Company tier (1,2 or 3): ";
    cin >> company_tier;
    cout << "Number of cheque bounce in last six months: ";
    cin >> cheque_bounce;
    cout << "Own house(y or n): ";
    cin >> own_house;
    cout << "Spouse working(y or n): ";
    cin >> spouse_working;
    cout << "Dependent Parent(y or n): ";
    cin >> dependent_parents;
cout<<"\n-------------------------------------------------- \n";
cout<<"\n-------------------------------------------------- \n";
}

void applicant::calc_liability()
{
    if (age >= 22 && age < 30)
        score += 2;
    else if (age >= 30 && age <= 35)
        score += 1;
    else if (age > 30)
        score -= 1;

    int sum = home_lone + personal_lone;

    if (sum <= monthly_salary / 4)
        score += 5;
    else if (sum > monthly_salary / 4 && sum <= monthly_salary / 3)
        score += 3;
    else if (sum > monthly_salary / 3 && sum <= monthly_salary / 2)
        score += 1;
    else if (sum > monthly_salary / 2)
        score -= 1;

    if (cheque_bounce >= 2)
        score -= 2;
    else if (cheque_bounce == 1)
        score -= 1;
    else
        score += 1;

    if (home_lone >= personal_lone)
        score += 1;
    else
        score -= 1;

    if (own_house == 'y')
        score += 1;
    else
        score -= 1;

    if (spouse_working == 'y')
        score += 1;
    else
        score -= 1;

    if (dependent_parents == 'y')
        score -= 1;
    else
        score += 1;

    if (company_tier == 1)
        score += 3;
    else if (company_tier == 2)
        score += 2;
    else
        score += 1;
}

void applicant::display_score()
{
    cout << "\n\n"
         << "--------------------------------------------------------" << endl;
    if (score > 9)
    {
        cout << "Applicant Name: " << name << endl;
        cout << "Creadit Score: " << score << endl;
        cout << "At low Risk" << endl;
    }
    else if (score > 5 && score <= 9)
    {
        cout << "Applicant Name: " << name << endl;
        cout << "Creadit Score: " << score << endl;
        cout << "At Average Risk" << endl;
    }
    else
    {
        cout << "Applicant Name: " << name << endl;
        cout << "Creadit Score: " << score << endl;
        cout << "At High Risk" << endl;
    }
        cout << "--------------------------------------------------------" << endl;
}

int main()
{

    int choise, flag;
    applicant obj;
    flag = 0;
data:

    cout.width(50);
    cout << "\n\n"
         << "Credit CalC" << endl;
    cout << "1 - Enter for loan Applicant's Details" << endl;
    cout << "2 - Display Credit score" << endl;
    cout << "3 - Exit" << endl;
    cin >> choise;

    switch (choise)
    {
    case 1:
        obj.get_data();
        flag++;
        break;
    case 2:
        if (flag == 0)
            cout << "\n-------------------- \n First enter details \n-------------------- \n" << endl;
        else
        {
            obj.calc_liability();
            obj.display_score();
        }
        break;
    case 3:
        exit(1);

    default:
        cout << "Enter a vailed selection" << endl;
        break;
    }
    goto data;

    return 0;
}
