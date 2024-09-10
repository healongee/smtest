// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie {
public:
  
  //manage priceCode by enum
  enum PriceCode {
    REGULAR = 0,
    NEW_RELEASE = 1,
    CHILDRENS = 2,
    EXAMPLE_GENRE = 3
  };
    
  //static const int CHILDRENS   = 2;
  //static const int REGULAR     = 0;
  //static const int NEW_RELEASE = 1;

  // add example_genre, price code is 3
  //static const int EXAMPLE_GENRE = 3;
    
  Movie( const std::string& title, int priceCode = REGULAR );

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;

  std::string getGenre() const; // add get genre

private:
  std::string movieTitle;
  int moviePriceCode;
};

inline Movie::Movie( const std::string& title, int priceCode ):
  movieTitle( title ),
  moviePriceCode( priceCode )
{}

inline int Movie::getPriceCode() const { return moviePriceCode; }

inline void Movie::setPriceCode( int arg ) { moviePriceCode = arg; }

inline std::string Movie::getTitle() const { return movieTitle; }

// add get genre by moviePriceCode
inline std::string Movie::getGenre() const {
    switch (moviePriceCode) {
        case REGULAR: return "REGULAR";
        case NEW_RELEASE: return "NEW_RELEASE";
        case CHILDRENS: return "CHILDRENS";
        case EXAMPLE_GENRE: return "EXAMPLE_GENRE";
        default: return "UNKNOWN_GENRE";
    }
}

#endif // MOVIE_H
