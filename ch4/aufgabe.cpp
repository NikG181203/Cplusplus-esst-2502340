// C++ implementation​​​​​​‌‌‌‌​​​‌‌​‌​‌​​‌​‌‌​‌‌‌‌​ below
#include <iostream>

enum class CustomerState {
    New,
    Standard,
    Premium
};

enum class CreditCardState {
    New,
    Valid,
    TransferInProgress,
    Invalid,
    Error
};


struct CreditCard {
    CreditCardState mState = CreditCardState::New;
    int mBalance = 100;
};

struct Customer {
    CustomerState mState = CustomerState::New;
    CreditCard mCreditcard;
};

bool verifyStatus(const Customer &cust)
{
	// TODO: Alle Karten müssen gültig (valid) sein.
    if(cust.mCreditcard.mState != CreditCardState::Valid){
        return false;
    }
	// TODO: Premium-Kund:innen dürften sich weiterhin verschulden, Standard-Kund:innen hingegen nicht
    if(cust.mState == CustomerState::Standard){
        if(cust.mCreditcard.mBalance > 0){
            return true;
        }
        return false;
    }else if(cust.mState == CustomerState::Premium){
        return true;
    }
    return true;
}

void withdrawMoney(Customer &cust, const int amnt)
{
	// TODO: Prüfen ob Kund:in überhaupt Geld abheben darf; Fehler melden, falls nicht.
	if(!verifyStatus(cust)){
        std::cout << "Dieser Kunde darf kein Geld abheben!" << std::endl;
    }else{// TODO: Dann Geld abheben
        cust.mCreditcard.mBalance = cust.mCreditcard.mBalance - amnt;
    }
}

void showBalance(const CreditCard &card)
{
	// TODO: Anzeigen, wieviel Geld noch auf der Kreditkarte ist
    std::cout << card.mBalance << std::endl;
}





// So wird Ihr Code aufgerufen.
// Für eigene Tests können Sie gerne weiteren Code hinzufügen.
// Achten Sie aber darauf, dass der Prozess inkl. Zahlen gleich bleibt.
// Bitte auch die Objekte peter und john nicht umbenennen.

Customer peter;
Customer john;

peter.mState = CustomerState::Premium;
john.mState = CustomerState::Standard;
peter.mCreditcard.mState = CreditCardState::Valid;
john.mCreditcard.mState = CreditCardState::Valid;

std::cout << "Peter:"  << std::endl;
showBalance(peter.mCreditcard);
std::cout << "John:"  << std::endl;
showBalance(john.mCreditcard);

std::cout << "Each is going to withdraw some Money: First 50, then 100 and finally 200."  << std::endl;
withdrawMoney(john, 50);
withdrawMoney(peter, 50);

withdrawMoney(john, 100);
withdrawMoney(peter, 100);

withdrawMoney(john, 200);
withdrawMoney(peter, 200);

std::cout << "Balance after withdrawing:" << std::endl;
std::cout << "Peter:"  << std::endl;
showBalance(peter.mCreditcard);
std::cout << "John:"  << std::endl;
showBalance(john.mCreditcard);

