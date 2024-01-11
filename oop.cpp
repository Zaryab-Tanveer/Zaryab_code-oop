#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

class Asset{
protected:
    string name;
    double value;

public:
    Asset(const string& name, double value)
        : name(name), value(value) {}

    virtual ~Asset() {}

    virtual void display() const {
        cout << "\n\t\t\t\t\tCurrency Name : " << name << ", Value : " << value << endl;
    }

    virtual double getValue() const {
        return value;
    }
};

class Currency : public Asset{
public:
    Currency(const string& code, double exchangeRate)
        : Asset(code, exchangeRate) {}

    double convert(double amount) const {
        return amount * value;
    }
};

class BankWallet{
private:
    double balance;
    string username;
    string password;
    bool loggedIn;
    vector<Asset*> assets;

public:
    BankWallet(const string& username, const string& password)
        : balance(0.0), username(username), password(password), loggedIn(false) {}
    string getUsername() const {
        return username;
    }
      void resetPassword(const string& username1,const string& newPassword1) {
        username=username1;
        password = newPassword1;
        return;
    }
    bool login(const string& enteredPassword) {
        if (!loggedIn && enteredPassword == password) {
            loggedIn = true;
            cout << "\n\t\t\t\t\tLogin successful!" << endl;
            Sleep(3000);
            return true;
        } else {
            cout << "\n\t\t\t\t\tLogin failed! Invalid password or already logged in." << endl;
            Sleep(4000);
            return false;
        }
    }

    void logout() {
        if (loggedIn) {
            loggedIn = false;
            cout << "\n\t\t\t\t\tLogout successful!" << endl;
            Sleep(3000);
        } else {
            cout << "\n\t\t\t\t\tNot logged in." << endl;
            Sleep(3000);
        }
    }

    bool isLoggedIn() const {
        return loggedIn;
    }

    void deposit(double amount) {
        if (loggedIn) {
            balance += amount;
            cout << "\n\t\t\t\t\tDeposited : " << amount << endl;
            Sleep(4000);
        } else {
            cout << "\n\t\t\t\t\tLogin required to perform transactions." << endl;
            Sleep(3000);
        }
    }

    void withdraw(double amount) {
        if (loggedIn) {
            if (amount <= balance) {
                balance -= amount;
                cout << "\n\t\t\t\t\tWithdrawn : " << amount << endl;
                Sleep(4000);
            } else {
                cout << "\n\t\t\t\t\tInsufficient funds!" << endl;
                Sleep(4000);
            }
        } else {
            cout << "\n\t\t\t\t\tLogin required to perform transactions." << endl;
            Sleep(3000);
        }
    }

    double checkBalance() const {
        if (loggedIn) {
            return balance;
        } else {
            cout << "\n\t\t\t\t\tLogin required to check balance." << endl;
            Sleep(4000);
            return 0.0;
        }
    }

    void addAsset(Asset* asset) {
        assets.push_back(asset);
    }

    void displayAssets() const {
        cout << "\n\t\t\t\t\tAssets in Bank Wallet : " << endl;
        for (size_t i = 0; i < assets.size(); ++i) {
            assets[i]->display();
        }
        Sleep(4000);
    }

    // Destructor to clean up allocated memory
    ~BankWallet() {
        for (size_t i = 0; i < assets.size(); ++i) {
            delete assets[i];
        }
        assets.clear();
    }
};

class CurrencyCalculator {
public:
    template <typename T>
    static double convert(const Currency& from, const Currency& to, T amount) {
        return to.convert(from.convert(static_cast<double>(amount)));
    }
};

int main() {
    // Create Bank Wallet with security
    string username;
	string password,password1;
	cout<<"\n\t\t\t\t----- WELCOME TO YOUR BANK ACCOUNT -----\n";
	cout<<"\n\t\t\t\t\tSet the user name : ";
	cin>>username;
	cout<<"\n\t\t\t\t\tSet the user password : ";
	cin>>password; 
    BankWallet userWallet(username, password);
    Sleep(3000);
    system("CLS");
	cout<<"\n\t\t\t\t\tEnter the password for login : ";
	cin>>password1;

    // Perform login
  userWallet.login(password1);
      	 system("CLS");
            while (true) {
            	 system("CLS");
    std::cout << "\n\t\t\t\t\t===================================\n";
    std::cout << "\t\t\t\t\t|            ***********           |\n";
    std::cout << "\t\t\t\t\t|*        BANK WALLET MENU        *|\n";
    std::cout << "\t\t\t\t\t|            ***********           |\n";
    std::cout << "\t\t\t\t\t|*                                *|\n";
    std::cout << "\t\t\t\t\t|* 1.  Display User Information   *|\n";
    std::cout << "\t\t\t\t\t|* 2.  Reset Username & Password  *|\n";
    std::cout << "\t\t\t\t\t|* 3.  Deposit an Amount          *|\n";
    std::cout << "\t\t\t\t\t|* 4.  Withdraw an Amount         *|\n";
    std::cout << "\t\t\t\t\t|* 5.  View Balance               *|\n";
    std::cout << "\t\t\t\t\t|* 6.  Add Assets                 *|\n";
    std::cout << "\t\t\t\t\t|* 7.  View Assets                *|\n";
    std::cout << "\t\t\t\t\t|* 8.  Use Currency Calculator    *|\n";
    std::cout << "\t\t\t\t\t|* 9.  Logout                     *|\n";
    std::cout << "\t\t\t\t\t|* 10. Login Again                *|\n";
    std::cout << "\t\t\t\t\t|* 11. Exit                       *|\n";
    std::cout << "\t\t\t\t\t|*                                *|\n";
    std::cout << "\t\t\t\t\t|            ***********           |";
    std::cout << "\n\t\t\t\t\t====================================\n";
    std::cout << "\t\t\t\t\tEnter your choice : ";


       

        int choice;
        cin >> choice;
            if(choice==1){
			
                cout << "\n\t\t\t\t\tUsername : " << userWallet.getUsername() ;
                Sleep(4000);
                }
		    else if(choice==2){
			    
                cout << "\n\t\t\t\t\tEnter new password : ";
                string newPassword;
                cin >> newPassword;
                cout << "\n\t\t\t\t\tEnter new Username : ";
                string newUsername;
                cin >> newUsername;
                
                userWallet.resetPassword(newUsername,newPassword);
                cout << "\n\t\t\t\t\tPassword and Username reset successfully!";
                Sleep(4000);
            
            }
            else if(choice==3)
            {
			
                cout<< "\n\t\t\t\t\tEnter deposit amount : ";
                double depositAmount;
                cin >> depositAmount;
                userWallet.deposit(depositAmount);
                
    	    }
			else if(choice==4){
			
                cout << "\n\t\t\t\t\tEnter withdrawal amount : ";
                double withdrawalAmount;
                cin >> withdrawalAmount;
                userWallet.withdraw(withdrawalAmount);
            
            }
            else if(choice==5)
            {
			
                   cout << "\n\t\t\t\t\tRemaining Balance in Account : " << userWallet.checkBalance() << endl;
                     Sleep(5000);
                }
            else if(choice==6)
			    {// Add currencies as assets to the Bank Wallet
    			
    			int x;
    			while(x!=1)
    			{
				
    			string cod;
    			double Value;
    			cout<<"\n\t\t\t\t\tEnter the code for new currency";
    			cin>>cod;
    			cout<<"\n\t\t\t\t\tEnter the Value for new currency";
    			cin>>Value;
    			userWallet.addAsset(new Currency(cod,Value));
    		
    			cout<<"\n\t\t\t\t\tHit 1 to stop adding more currencies to your Assets";
    			cin>>x;
    				
    		}
		 	}
    		else if(choice==7)
    		{
			
    			    // Display assets in the Bank Wallet
    		userWallet.displayAssets();
    		}
            else if(choice==8)
            {
			string X,Y;
			float x,y;
			int amount;
              cout<<"\n\t\t\t\t\tEnter the Currency Name and Exchange Rate to convert  C1 into C2";
              cout<<"\n\t\t\t\t\tC1 name : ";
			  cin>>X;
			  cout<<"\n\t\t\t\t\tC1 exchangerate : ";
			  cin>>x;
			  cout<<"\n\t\t\t\t\tC2 name : ";
              cin>>Y;
              cout<<"\n\t\t\t\t\tC2 exchangerate : ";
			  cin>>y;
			  cout<<"\n\t\t\t\t\tEnter the amount for"<< X <<" to convert in"<< Y;
			  cin>>amount;
    		double newamount = CurrencyCalculator::convert(Currency(Y,y), Currency(X,x), amount);
    		cout<<"\n\t\t\t\t\t"<<amount<<"in"<<" "<< X <<" is equal to "<<" "<< newamount<<" "<<Y<<endl;
    		Sleep(6000);
    		
        	}
            else if(choice==9)
            {
			
                userWallet.logout();
        	}
            else if(choice==10)
            {
				cout<<"\n\t\t\t\t\tEnter the user name and password for login : ";
	cin>>password1;

    // Perform login
  userWallet.login(password1);
                
            }
               else if(choice==11){
               	exit(0);
			   }   
            else
            {
                cout << "\n\t\t\t\t\tInvalid choice! Please try again.";
                Sleep(3000);
        }
}
	}