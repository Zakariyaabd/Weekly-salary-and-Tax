using namespace std;

class Employee
{
private:
    string firstName;
    string lastName;
    char middleName;
    double federalTax;
    double stateTax;

public:
    void setInfo(string, string, char, double, double);
    double grossPay(int *, double *);
    double grossPay(int *, double *, double *);
    double grossPay(int *, int *, double *, double *);
    double grossPay(int *, int *, int *, double *, double *);
    void display(string f_name, string l_name, char m_name, double f_tax, double s_tax, double gross_pay);
    double federal_tax(double f_tax, double gross_pay);
    double state_tax(double s_tax, double gross_pay);
    double total_tax(double f_tax, double s_tax);
    double netPay(double t_tax, double gross_pay);
};
