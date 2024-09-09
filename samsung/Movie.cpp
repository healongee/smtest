// Movie.cpp
#include "Movie.h"

const int Movie::CHILDRENS;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;

// add example_genre
const int Movie::EXAMPLE_GENRE;

// add get genre by moviePriceCode
std::string Movie::getGenre() const {
    switch (moviePriceCode) {
        case REGULAR: return "REGULAR";
        case NEW_RELEASE: return "NEW_RELEASE";
        case CHILDRENS: return "CHILDRENS";
        case EXAMPLE_GENRE: return "EXAMPLE_GENRE";
        default: return "UNKNOWN_GENRE";
    }
}
