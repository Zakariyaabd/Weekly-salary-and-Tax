#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Employee.h"

int main()
{
    string firstName;
    string lastName;
    char middleName;
    double gross_pay = 0.0;
    double federalTax = 0.0;
    double stateTax = 0.0;
    

    int salaryType = 0;
    double weeklySalary = 0.0;
    double annualSalary = 0.0;
    double payRate = 0.0;
    double hoursWorked = 0.0;
    int employeeNumber;

    double fed_calcs;
    double st_calc;
    double tt_tax;
    double net_pay = 0.0;

    cout << "STARTING THE EMPLOYEE SALARY SYSTEM\n"
         << "Type the end-of-file indicator to terminate input:\n"
         << "   On UNIX/Linux/Mac OS X type <Ctrl> d then press Enter\n"
         << "   On Windows type <Ctrl> z then press Enter\n";

    cout << "\n Enter your federal tax rate: ";
    cin >> federalTax;
    cout << "Enter your state tax rate: ";
    cin >> stateTax;
    double totalTax = federalTax + stateTax;
    cout << "\n ENTER TYPE OF SALARY YOU WANT TO PROCCESS."
         << "\n Enter 1 for Annual, Enter 2 for Hourly, Enter 3 for Intern, "
         << " or Enter 4 for Contract. ";

    Employee employee;
    while (cin >> salaryType)
    {
        switch (salaryType)
        {
        case 1: // Salary pay
            cout << "Annual employee program. \n";
            cout << "Enter your annual salary: ";
            cin >> annualSalary;

            cout << "\nEnter your last name: ";
            cin >> lastName;
            cout << "Enter your first name: ";
            cin >> firstName;
            cout << "Enter your middle initial: ";
            cin >> middleName;
            cout << "Enter your Employee Number: ";
            cin >> employeeNumber;

            employee.setInfo(firstName, lastName, middleName, federalTax, stateTax);
            gross_pay = employee.grossPay(&employeeNumber, &annualSalary);
            employee.display(firstName, lastName, middleName, federalTax, stateTax, gross_pay);

            fed_calcs = employee.federal_tax( federalTax, gross_pay);
            st_calc = employee.state_tax ( stateTax,  gross_pay); 
            tt_tax = employee.total_tax (fed_calcs, st_calc); 
            net_pay  = employee.netPay (tt_tax, gross_pay); 

            cout << "Weekly net Pay: " << fixed << setprecision(2) << net_pay << endl;

            
            break;

        case 2: // Hourly pay
            cout << "Hourly Employee Program. \n";
            cout << "Enter your Pay rate: ";
            cin >> payRate;
            cout << "Enter the hours you worked: ";
            cin >> hoursWorked;

            while (hoursWorked > 50)
            {
                cout << "The total hours cannot exceed 50 ";
                cout << "Enter the hours you worked (must be between 0 to 50): ";
                cin >> hoursWorked;
            }

            cout << "\nEnter your last name: ";
            cin >> lastName;
            cout << "Enter your first name: ";
            cin >> firstName;
            cout << "Enter your middle initial: ";
            cin >> middleName;
            cout << "Enter your Employee Number:  ";
            cin >> employeeNumber;

            employee.setInfo(firstName, lastName, middleName, federalTax, stateTax);
            gross_pay = employee.grossPay(&employeeNumber, &hoursWorked, &payRate);
            employee.display(firstName, lastName, middleName, federalTax, stateTax, gross_pay);
            

            fed_calcs = employee.federal_tax( federalTax, gross_pay);
            st_calc = employee.state_tax ( stateTax,  gross_pay); 
            tt_tax = employee.total_tax (fed_calcs, st_calc); 
            net_pay  = employee.netPay (tt_tax, gross_pay); 

            cout << "Weekly net Pay: " << fixed << setprecision(2) << net_pay << endl;


            break;

        case 3: // Intern pay
            cout << "Intern Employee Program. \n";
            cout << "Enter your pay rate: ";
            cin >> payRate;
            cout << "Enter the hours you worked: ";
            cin >> hoursWorked;

            while (hoursWorked > 20)
            {
                cout << "The total hours cannot exceed 20\n ";
                cout << "Enter the hours you worked (must be between 0 to 20): ";
                cin >> hoursWorked;
            }

            int departmentCode;
            cout << "what's your department code: ";
            cin >> departmentCode;

            int institutionCode;
            cout << "what's your Institution Code ";
            cin >> institutionCode;

            cout << "\nIntern Department code: " << departmentCode << endl;
            cout << "Intern Istitution Code: " << institutionCode << endl;

            cout << "\nEnter your last name: ";
            cin >> lastName;
            cout << "Enter your first name: ";
            cin >> firstName;
            cout << "Enter your middle initial: ";
            cin >> middleName;
            employee.setInfo(firstName, lastName, middleName, federalTax, stateTax);
            gross_pay = employee.grossPay(&departmentCode, &institutionCode, &hoursWorked, &payRate);
            employee.display(firstName, lastName, middleName, federalTax, stateTax, gross_pay); 
            
            break;

        case 4: // Contract pay
            cout << "Contract Employee Program. \n";
            cout << "Enter your pay rate: ";
            cin >> payRate;
            cout << "Enter the hours you worked: ";
            cin >> hoursWorked;

            while (hoursWorked > 40)
            {
                cout << "The total hours cannot exceed 40\n";
                cout << "Enter the hours you worked (must be between 0 to 40): ";
                cin >> hoursWorked;
            }

            cout << "what's your employee number: ";
            cin >> employeeNumber;

            int companyNumber;
            cout << "what's your company number, ";
            cin >> companyNumber;

            int projectNumber;
            cout << "what's the project number: ";
            cin >> projectNumber;
            cout << "\nEnter your last name: ";
            cin >> lastName;
            cout << "Enter your first name: ";
            cin >> firstName;
            cout << "Enter your middle initial: ";
            cin >> middleName;

            cout << "\nContractor Employee Number: " << employeeNumber << endl;
            cout << "Contractor Company Number: " << companyNumber << endl;
            cout << "Contractor Project Number: " << projectNumber << endl;
            cout << "Contractor weekly Gross Pay: " << gross_pay << fixed << setprecision(2) << endl;
            employee.setInfo(firstName, lastName, middleName, federalTax, stateTax);
            gross_pay = employee.grossPay(&companyNumber, &projectNumber, &employeeNumber, &hoursWorked, &payRate);
            employee.display(firstName, lastName, middleName, federalTax, stateTax, gross_pay); 
            
            break;
        }

        cout << "\n ENTER TYPE OF SALARY YOU WANT TO PROCCESS."
             << "\n Enter 1 for Annual, Enter 2 for Hourly, Enter 3 for Intern, "
             << " or Enter 4 for Contract: ";
    }

    return 0;
}