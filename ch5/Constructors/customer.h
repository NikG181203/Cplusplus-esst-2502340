#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
public:
    /**
     * @brief Customer Constructor
     */
    Customer();


    /**
     * @brief Customer Constructor
     * @param name Name of the customer
     */
    Customer(const std::string &name);

    /**
     * @brief Customer Constructor Initialiser List
     * @param initlist
     */
    /*Customer(const std::initializer_list<int> &initlist){
        auto it = initlist.begin();
        //Logik einbauen
    }
    */

    /**
     * @brief getName
     * @return returns the name of the customer
     */
    std::string getName();

    /**
     * @brief rename In case you want to rename the customer, use this methd
     * @param name New name to set
     */
    void rename(const std::string &name);

private:
    std::string mName;
};

#endif // CUSTOMER_H
