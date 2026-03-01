// C++ implementation​​​​​​‌‌‌‌​​​‌‌​‌‌‌‌‌​‌​‌‌​‌​​‌ below
#include <iostream>
#include <vector>

// Uncomment these macros to control whether you see
// the expected result and/or hints.
//#define showExpectedResult
//#define showHints


class CreditCard {
    public:
        enum class CreditCardState {
            New,
            Valid,
            TransferInProgress,
            Invalid,
            Error
        };

        CreditCardState getState() const{
            return mState;
        }
        void changeAmnt(const int amnt){
            mBalance += amnt;
        }
        void showBalance()
        {
            std::cout << "Balance: " << mBalance << std::endl;
        }
        int getBalance(){
            return mBalance;
        }

    private:
        CreditCardState mState = CreditCardState::Valid;
        int mBalance = 100;
};

class Customer {
    public:
        enum class CustomerState {
            New,
            Standard,
            Premium
        };

        Customer(const CustomerState state):
        mState(state)
        {}

        bool verifyStatus(){
            if(mCreditcard.getState() != CreditCard::CreditCardState::Valid)
                return false;

            if(mState == CustomerState::Premium)
                return true;

            if(mCreditcard.getBalance() < 0)
                return false;

            return true;
        }

        void withdrawMoney(const int amnt){
            if(!verifyStatus()){
                std::cout << "Die Transaktion kann leider nicht durchgefuehrt werden." << std::endl;
                return;
            }
            mCreditcard.changeAmnt(-amnt);
        }

        void showBalance(){
            mCreditcard.showBalance();
        }

    private: 
        CustomerState mState = CustomerState::New;
        CreditCard mCreditcard;
};





// --------- main.cpp -----------------
// So wird Ihr Code aufgerufen.
// Für eigene Tests können Sie gerne weiteren Code hinzufügen.
// Achten Sie aber darauf, dass der Prozess inkl. Zahlen gleich bleibt.
// Bitte auch die Objekte peter und john nicht umbenennen.

Customer peter(Customer::CustomerState::Premium);
Customer john(Customer::CustomerState::Standard);

std::cout << "Peter:"  << std::endl;    
peter.showBalance();
std::cout << "John:"  << std::endl;
john.showBalance();

std::cout << "Each is going to withdraw some Money: First 50, then 100 and finally 200."  << std::endl;
john.withdrawMoney(50);
peter.withdrawMoney(50);

john.withdrawMoney(100);
peter.withdrawMoney(100);

john.withdrawMoney(200);
peter.withdrawMoney(200);

std::cout << "Balance after withdrawing:" << std::endl;
std::cout << "Peter:"  << std::endl;
peter.showBalance();
std::cout << "John:"  << std::endl;
john.showBalance();

