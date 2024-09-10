//  Statement.h
#ifndef Statement_h
#define Statement_h

#include <vector>
#include <sstream>
#include <iomanip>
#include "Rental.h"

class Statement {
public:
    Statement() = default;
    std::string generateStatement(const std::vector<Rental>& rentals, const std::string& customerName) const;
    
private:
    double calculateAmount(const Rental& rental) const;
    int calculateFrequentRenterPoints(const Rental& rental) const;
    std::string oldRentalStatement(const Rental& rental, double amount) const;
    std::string newRentalStatement(const Rental& rental, double amount) const;
};

//calculate rental amount
inline double Statement::calculateAmount(const Rental& rental) const {
    double amount = 0.0;
    const double REGULAR_BASE_PRICE = 2.0;
    const double CHILDREN_BASE_PRICE = 1.5;
    const int REGULAR_BASIC_DAYS = 2;
    const int CHILDREN_BASIC_DAYS = 3;
    const double NEW_RELEASE_PRICE_PER_DAY = 3.0;
    const double EXAMPLE_GENRE_PRICE_PER_DAY = 4.0;
    const double EXTRA_DAYS_PRICE = 1.5;

    switch (rental.getMovie().getPriceCode()) {
        case Movie::REGULAR:
            amount += REGULAR_BASE_PRICE;
            if (rental.getDaysRented() > REGULAR_BASIC_DAYS)
                amount += (rental.getDaysRented() - REGULAR_BASIC_DAYS) * EXTRA_DAYS_PRICE;
            break;
        case Movie::NEW_RELEASE:
            amount += rental.getDaysRented() * NEW_RELEASE_PRICE_PER_DAY;
            break;
        case Movie::CHILDRENS:
            amount += CHILDREN_BASE_PRICE;
            if (rental.getDaysRented() > CHILDREN_BASIC_DAYS)
                amount += (rental.getDaysRented() - CHILDREN_BASIC_DAYS) * EXTRA_DAYS_PRICE;
            break;
        case Movie::EXAMPLE_GENRE:
            amount += rental.getDaysRented() * EXAMPLE_GENRE_PRICE_PER_DAY;
            break;
    }
    return amount;
}

//calculate renter points
inline int Statement::calculateFrequentRenterPoints(const Rental& rental) const {
    int points = 1;
    if ((rental.getMovie().getPriceCode() == Movie::NEW_RELEASE) && rental.getDaysRented() > 1) {
        points++;
    }
    return points;
}

inline std::string Statement::oldRentalStatement(const Rental& rental, double amount) const {
    std::ostringstream result;
    result << "\t" << rental.getMovie().getTitle() << "\t" << amount << std::endl;
    return result.str();
}

inline std::string Statement::newRentalStatement(const Rental& rental, double amount) const {
    std::ostringstream result;
    result << rental.getMovie().getGenre() << " "
           << rental.getMovie().getTitle() << " "
           << rental.getDaysRented() << "일 "
           << std::fixed << std::setprecision(2) << amount << "\n";
    return result.str();
}

#endif /* Statement_h */
