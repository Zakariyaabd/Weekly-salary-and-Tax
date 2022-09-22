#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Employee.h"

void Employee::setInfo(string f_name, string l_name, char m_name, double f_tax, double s_tax)
{
    firstName = f_name;
    lastName = l_name;
    middleName = m_name;
    federalTax = f_tax;
    stateTax = s_tax;
}

double Employee::grossPay(int *employeeNumber, double *yearlySalary)
{
    return (*yearlySalary / 52);
}

double Employee::grossPay(int *employeeNumber, double *hoursWorked, double *payRate)
{
    double hrs_worked = *hoursWorked;
    double pay_rate = *payRate;

    if (hrs_worked <= 40)
    {
        return (hrs_worked * pay_rate);
    }
    else
    {
        return (hrs_worked - 40) * 1.5 * pay_rate + (40 * pay_rate);
    }
}

double Employee::grossPay(int *institutionCode, int *departmentCode, double *hoursWorked, double *payRate)
{
    double pay_rate = *payRate;

    if (*hoursWorked <= 15)
    {
        return *hoursWorked * pay_rate;
    }
    else
    {
        return (*hoursWorked - 15) * 1.25 * pay_rate + (15 * pay_rate);
    }
}

double Employee::grossPay(int *companyNumber, int *projectNumber, int *employeeNumber, double *hoursWorked, double *payRate)
{
    return (*hoursWorked * (*payRate));
}

double Employee::federal_tax(double f_tax, double gross_pay)
{
    return (f_tax / 100) * gross_pay;
}

double Employee::state_tax(double s_tax, double gross_pay)
{
    return (s_tax / 100) * gross_pay;
}
double Employee::total_tax(double f_tax, double s_tax)
{
    return (f_tax + s_tax);
}
double Employee::netPay(double t_tax, double gross_pay)
{
    return (gross_pay - t_tax);
}

void Employee::display(string f_name, string l_name, char m_name, double f_tax, double s_tax, double gross_pay)
{
    cout << "\nEMPLOYEE NAME: " << l_name << " " << f_name << " " << m_name << endl;
    cout << "Federal Tax Rate: " << f_tax << endl;
    cout << "State Tax Rate:" << s_tax << endl;
    cout <<  "Total tax rate: " << f_tax + s_tax << endl; 
    cout << "Weekly Gross Pay: " << fixed << setprecision(2) << gross_pay << endl;
}
