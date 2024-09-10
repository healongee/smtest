//  Statement.cpp
#include <stdio.h>
#include "Statement.h"

std::string Statement::generateStatement(const std::vector<Rental>& rentals, const std::string& customerName) const {
    double totalAmount = 0.0;
    int frequentRenterPoints = 0;
    std::ostringstream result;
    result << "Rental Record for " << customerName << "\n";
    std::ostringstream newReceiptFormat;
    newReceiptFormat << "\n \n";

    for (const Rental& each : rentals) {
        double thisAmount = calculateAmount(each);
        frequentRenterPoints += calculateFrequentRenterPoints(each);
        result << oldRentalStatement(each, thisAmount);
        newReceiptFormat << newRentalStatement(each, thisAmount);
        totalAmount += thisAmount;
    }

    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints << " frequent renter points\n";
    result << newReceiptFormat.str(); 

    return result.str();
}
