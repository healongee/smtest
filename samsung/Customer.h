// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

#include <iomanip>  // add iomanip for using std::setprecision

#include "Rental.h"

// The customer class represents the customer of the store

class Customer {
public:
  Customer();
  explicit Customer( const std::string& name );

  void addRental( const Rental& arg );
  std::string getName() const;

  // Generate a statement for the customer
  std::string statement();
    
private:
  std::string customerName;
  std::vector< Rental > customerRentals;

  double calculateAmount(const Rental& rental) const;
  int calculateFrequentRenterPoints(const Rental& rental) const;
  std::string oldRentalStatement(const Rental& rental, double amount) const;
  std::string newRentalStatement(const Rental& rental, double amount) const;
    
};

inline Customer::Customer() {}

inline Customer::Customer( const std::string& name ):
  customerName( name ) {}

inline void Customer::addRental( const Rental& arg ) { customerRentals.push_back( arg ); }

inline std::string Customer::getName() const { return customerName; }

#endif // CUSTOMER_H
