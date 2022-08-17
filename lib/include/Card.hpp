#include "CardType.hpp"
#include "CardSymbol.hpp"


public Card {
    private:
        CardType cardType;
        CardSymbol cardSymbol;

    public:
        Card(CardType,CardSymbol);
};