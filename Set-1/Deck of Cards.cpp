//Problem Name : Deck of Cards

/****************************************/
#include<bits/stdc++.h>
using namespace std;

enum class Suit{
    CLUBS, DIAMONDS, HEARTS, SPADES,
};

enum class CardName{
    ACE = 1, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, 
    JACK, KING, QUEEN 
};

struct Card{
    CardName name;
    Suit suit;
    int value;
    void PrintValue(){
        if(name == CardName:: JACK ||name == CardName:: QUEEN || name == CardName:: KING)
            cout << 10;
        else
            cout << value;
    }
    
    void PrintSuit(){
        if(suit == Suit::CLUBS) cout <<"clubs";
        else if (suit == Suit::DIAMONDS) cout <<"diamonds";
        else if(suit == Suit::HEARTS)cout <<"hearts";
        else if(suit == Suit::SPADES)cout <<"spades";
    }
    
    void PrintCard(){
        PrintValue();
        cout << " of ";
        PrintSuit();
        cout <<endl;
    }
};

struct Deck{
    Card allCards[52];
    
    void PrintAll(){
         for(int col = (int)Suit::CLUBS; col <= (int) Suit::SPADES; col++){
            for(int row = (int)CardName::ACE; row <= (int)CardName::KING; row++){
                int index = (col * 13) + row - 1;
                allCards[index].PrintCard();
            }
         cout << endl;
         }
    }
    
    void SetupCards(){
        for(int col = (int)Suit::CLUBS; col <= (int) Suit::SPADES; col++){
            for(int row = (int)CardName::ACE; row <= (int)CardName::KING; row++){
                Card c;
                c.suit = (Suit)col;
                c.name = (CardName)row;
                
                if(c.name == CardName::JACK || c.name == CardName::QUEEN || c.name == CardName::KING){
                    c.value = 10;
                }else{
                    c.value = (int)c.name;
                }
                int index = (col * 13) + row - 1;
                allCards[index] = c;
            }
        }
    }
};

int main(){
    Deck deck;
    deck.SetupCards();
    deck.PrintAll();
}

/*
OUTPUT:

1 of clubs
2 of clubs
3 of clubs
4 of clubs
5 of clubs
6 of clubs
7 of clubs
8 of clubs
9 of clubs
10 of clubs
11 of clubs
10 of clubs
10 of clubs

1 of diamonds
2 of diamonds
3 of diamonds
4 of diamonds
5 of diamonds
6 of diamonds
7 of diamonds
8 of diamonds
9 of diamonds
10 of diamonds
11 of diamonds
10 of diamonds
10 of diamonds

1 of hearts
2 of hearts
3 of hearts
4 of hearts
5 of hearts
6 of hearts
7 of hearts
8 of hearts
9 of hearts
10 of hearts
11 of hearts
10 of hearts
10 of hearts

1 of spades
2 of spades
3 of spades
4 of spades
5 of spades
6 of spades
7 of spades
8 of spades
9 of spades
10 of spades
11 of spades
10 of spades
10 of spades

*/