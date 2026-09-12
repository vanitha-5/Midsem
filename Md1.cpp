#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
public:
    int AccountNumber;
    string name;
    double balance;

    BankAccount()
    {
        AccountNumber = 0;
        name = "";
        balance = 0.0;
    }

    void getData()
    {
        cout << "Holder name: ";cin >> name;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            return false;
        }

        balance = balance - amount;
        return true;
    }

    void display()
    {
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount a[25];

    int count = 0;
    int accountNo = 1001;
    int choice = 0;

    while (choice != 7)
    {
        cout << "\n>>>>>>>>>>>Bank Manager<<<<<<<<<<<" << endl;
        cout << "1. Open" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Balance" << endl;
        cout << "6. Display All" << endl;
        cout << "7. Exit" << endl;

        cout << "***Enter choice***: ";cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (count < 25)
            {
                a[count].AccountNumber = accountNo;

                a[count].getData();

                cout << "Account opened." << endl;
                cout << "Account Number: "<< a[count].AccountNumber << endl;

                count++;
                accountNo++;
            }
            else
            {
                cout << "Maximum 25 accounts reached." << endl;
            }

            break;
        }
        case 2:
        {
            int no;
            double amount;

            cout << "Account Number: ";cin >> no;

            for (int i = 0; i < count; i++)
            {
                if (a[i].AccountNumber == no)
                {
                    cout << "Amount: ";
                    cin >> amount;

                    a[i].deposit(amount);

                    cout << "Deposited. New balance: "
                         << a[i].balance << endl;

                    break;
                }
            }
            break;
        }
        case 3:
        {
            int no;
            double amount;

            cout << "Account Number: ";cin >> no;

            for (int i = 0; i < count; i++)
            {
                if (a[i].AccountNumber == no)
                {
                    cout << "Amount: ";
                    cin >> amount;

                    if (a[i].withdraw(amount))
                    {
                        cout << "Withdraw successful." << endl;
                        cout << "New balance: "
                             << a[i].balance << endl;
                    }
                    else
                    {
                        cout << "Insufficient balance" << endl;
                    }

                    break;
                }
            }
            break;
        }
        case 4:
        {
            int from;
            int to;
            double amount;

            cout << "From: ";
            cin >> from;

            cout << "To: ";
            cin >> to;

            if (from == to)
            {
                cout << "Cannot transfer to the same account" << endl;
                break;
            }

            int fromPosition = -1;
            int toPosition = -1;

            for (int i = 0; i < count; i++)
            {
                if (a[i].AccountNumber == from)
                {
                    fromPosition = i;
                }

                if (a[i].AccountNumber == to)
                {
                    toPosition = i;
                }
            }

            if (toPosition == -1)
            {
                cout << "Invalid destination account" << endl;
            }
            else if (fromPosition == -1)
            {
                cout << "Invalid source account" << endl;
            }
            else
            {
                cout << "Amount: ";
                cin >> amount;

                if (a[fromPosition].withdraw(amount))
                {
                    a[toPosition].deposit(amount);

                    cout << "Transfer successful." << endl;
                }
                else
                {
                    cout << "Insufficient balance" << endl;
                }
            }

            break;
        }
        case 5:
        {
            int no;

            cout << "Account Number: ";
            cin >> no;

            for (int i = 0; i < count; i++)
            {
                if (a[i].AccountNumber == no)
                {
                    cout << "Balance: "
                         << a[i].balance << endl;

                    break;
                }
            }
            break;
        }
        case 6:
        {
            for (int i = 0; i < count; i++)
            {
                cout << endl;
                a[i].display();
            }
            break;
        }
        case 7:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    }
    return 0;
}

