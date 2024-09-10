// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

//separate statement()
//std::string Customer::statement(){
//  double totalAmount = 0.;
//  int frequentRenterPoints = 0;
//
//  std::vector< Rental >::iterator iter = customerRentals.begin();
//  std::vector< Rental >::iterator iter_end = customerRentals.end();
//
//  // result will be returned by statement()
//  std::ostringstream result;
//  result << "Rental Record for " << getName() << "\n";
//
//  // add new receipt
//  std::ostringstream newReceiptFormat;
//  newReceiptFormat << "\n \n";
//
//  // Loop over customer's rentals
//  for ( ; iter != iter_end; ++iter ) {
//
//    double thisAmount = 0.;
//    Rental each = *iter;
//
//    // Determine amounts for each rental
//    switch ( each.getMovie().getPriceCode() ) {
//
//      case Movie::REGULAR:
//        thisAmount += 2.;
//        if ( each.getDaysRented() > 2 )
//          thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
//        break;
//
//      case Movie::NEW_RELEASE:
//        thisAmount += each.getDaysRented() * 3;
//        break;
//
//      case Movie::CHILDRENS:
//        thisAmount += 1.5;
//        if ( each.getDaysRented() > 3 )
//          thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
//        break;
//
//      // add example_genre amount
//      case Movie::EXAMPLE_GENRE:
//        thisAmount += each.getDaysRented() * 4; // 4 per day
//        break;
//    }
//
//    // Add frequent renter points
//    frequentRenterPoints++;
//
//    // Add bonus for a two day new release rental
//    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
//         && each.getDaysRented() > 1 ) frequentRenterPoints++;
//
//    // Show figures for this rental
//    result << "\t" << each.getMovie().getTitle() << "\t"
//           << thisAmount << std::endl;
//
//    // add new receipt format ex) 장르 제목 대여기간 가격
//    newReceiptFormat << each.getMovie().getGenre() << " "
//                     << each.getMovie().getTitle() << " "
//                     << each.getDaysRented() << "일 "
//                     << std::fixed << std::setprecision(2) << thisAmount << "\n";
//
//    totalAmount += thisAmount;
//  }
//
//  // Add footer lines
//  result << "Amount owed is " << totalAmount << "\n";
//  result << "You earned " << frequentRenterPoints
//         << " frequent renter points";
//
//  // add new receipt after origin receipt
//  result << newReceiptFormat.str();
//
//  return result.str();
//}

//calculate rental amount
double Customer::calculateAmount(const Rental& rental) const {
    double amount = 0.0;
    switch (rental.getMovie().getPriceCode()) {
        case Movie::REGULAR:
            amount += 2.;
            if (rental.getDaysRented() > 2)
                amount += (rental.getDaysRented() - 2) * 1.5;
            break;
        case Movie::NEW_RELEASE:
            amount += rental.getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            amount += 1.5;
            if (rental.getDaysRented() > 3)
                amount += (rental.getDaysRented() - 3) * 1.5;
            break;
        case Movie::EXAMPLE_GENRE:
            amount += rental.getDaysRented() * 4;
            break;
    }
    return amount;
}

//calculate renter points
int Customer::calculateFrequentRenterPoints(const Rental& rental) const {
    int points = 1;  // basic point
    if ((rental.getMovie().getPriceCode() == Movie::NEW_RELEASE) && rental.getDaysRented() > 1) {
        points++;
    } // Add bonus for a two day new release rental
    return points;
}

std::string Customer::oldRentalStatement(const Rental& rental, double amount) const {
    std::ostringstream result;
    result << "\t" << rental.getMovie().getTitle() << "\t" << amount << std::endl;
    return result.str();
}

std::string Customer::newRentalStatement(const Rental& rental, double amount) const {
    std::ostringstream result;
    result << rental.getMovie().getGenre() << " "
           << rental.getMovie().getTitle() << " "
           << rental.getDaysRented() << "일 "
           << std::fixed << std::setprecision(2) << amount << "\n";
    return result.str();
}

std::string Customer::statement() {
    double totalAmount = 0.;
    int frequentRenterPoints = 0;
    std::ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    std::ostringstream newReceiptFormat;
    newReceiptFormat << "\n \n";

    for (const Rental& each : customerRentals) {
        double thisAmount = calculateAmount(each);  // calculate amount
        frequentRenterPoints += calculateFrequentRenterPoints(each);  // calculate points
        result << oldRentalStatement(each, thisAmount);  // old statement
        newReceiptFormat << newRentalStatement(each, thisAmount);  // new statement
        totalAmount += thisAmount;
    }

    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints << " frequent renter points\n";
    result << newReceiptFormat.str();  //append new receipt
    return result.str();
}
