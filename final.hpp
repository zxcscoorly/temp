#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

enum CardSuit // Перечисление мастей карт
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};
enum CardRank // Перечисление значений карт
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ACE
};

struct Card // Карта
{
    CardSuit suit;
    CardRank rank;
    string symbol;
    vector<string> look;

    Card(CardSuit suit, CardRank rank) : suit(suit), rank(rank)
    {
        switch (suit)
        {
        case HEARTS:
            symbol = "H"; //"♥";
            break;
        case DIAMONDS:
            symbol = "D"; //"♦";
            break;
        case CLUBS:
            symbol = "C"; //"♣";
            break;
        case SPADES:
            symbol = "S"; //"♠";
            break;
        default:
            break;
        }
        look = doCard(*this);
    }
    vector<string> doCard(Card card)
    {
        vector<string> result;
        string suit;
        switch (card.suit)
        {
        case HEARTS:
        {
            suit = "H";
            break;
        }
        case DIAMONDS:
        {
            suit = "D";
            break;
        }
        case CLUBS:
        {
            suit = "D";
            break;
        }
        default:
        {
            suit = "S";
            break;
        }
        }
        switch (card.rank)
        {
        case 0:
        {
            result.push_back(" _____ ");
            result.push_back("|2    |");
            result.push_back("|  ^  |");
            result.push_back("|     |");
            result.push_back("|  ^  |");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 1:
        {
            result.push_back(" _____ ");
            result.push_back("|3    |");
            result.push_back("| ^ ^ |");
            result.push_back("|     |");
            result.push_back("|  ^  |");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 2:
        {
            result.push_back(" _____ ");
            result.push_back("|4    |");
            result.push_back("| ^ ^ |");
            result.push_back("|     |");
            result.push_back("| ^ ^ |");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 3:
        {
            result.push_back(" _____ ");
            result.push_back("|5    |");
            result.push_back("| ^ ^ |");
            result.push_back("|  ^  |");
            result.push_back("| ^ ^ |");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 4:
        {
            result.push_back(" _____ ");
            result.push_back("|6    |");
            result.push_back("| ^ ^ |");
            result.push_back("| ^ ^ |");
            result.push_back("| ^ ^ |");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 5:
        {
            result.push_back(" _____ ");
            result.push_back("|7    |");
            result.push_back("| ^ ^ |");
            result.push_back("|^ ^ ^|");
            result.push_back("| ^ ^ |");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 6:
        {
            result.push_back(" _____ ");
            result.push_back("|8    |");
            result.push_back("|^ ^ ^|");
            result.push_back("| ^ ^ |");
            result.push_back("|^ ^ ^|");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 7:
        {
            result.push_back(" _____ ");
            result.push_back("|9    |");
            result.push_back("|^ ^ ^|");
            result.push_back("|^ ^ ^|");
            result.push_back("|^ ^ ^|");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 8:
        {
            result.push_back(" _____ ");
            result.push_back("|10 ^ |");
            result.push_back("|^ ^ ^|");
            result.push_back("|^ ^ ^|");
            result.push_back("|^ ^ ^|");
            result.push_back("|____" + suit + "|");
            break;
        }
        case 9:
        {
            result.push_back(" _____ ");
            result.push_back("|A ^  |");
            result.push_back("| / \\ |");
            result.push_back("| \\ / |");
            result.push_back("|  .  |");
            result.push_back("|____" + suit + "|");
            break;
        }
        }
        return result;
    }
};

class Player // Игрок
{
public:
    string name;
    int balance;
    vector<Card> hand;

    Player(string name, int balance) : name(name), balance(balance) {}

    void addCard(Card card) // Добавление карт
    {
        hand.push_back(card);
    }

    void printCards(Player &player)
    {
        cout << "\n";
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < player.hand.size(); j++)
            {
                cout << player.hand[j].look[i] << " ";
            }
            cout << "\n";
        }
    }

    void displayHand() // Показать карты игрока
    {
        cout << "Player " << name << " 's hand: ";
        // for (const auto &card : hand)
        // {
        //     cout << getCardSymbol(card.rank) << " ";
        // }
        printCards(*this);
        cout << endl;
    }
    int calculateScore() // Вычисляет счет в руке игрока
    {
        int score = 0;
        int aceCount = 0;

        for (const auto &card : hand)
        {
            if (card.rank == ACE)
            {
                aceCount++;
            }
            else
            {
                score += card.rank + 2;
            }
        }

        while (aceCount > 0 && score <= 11)
        {
            score += 10;
            aceCount--;
        }
        return score;
    }

    bool HitOrStand() // Взять или остаться
    {
        char choice;
        cout << "Player " << name << " , do you want to hit or stand? (h/s)" << endl;
        cin >> choice;
        while (choice != 'h' && choice != 's')
        {
            cout << "Invalid choice. Please, enter 'h' to hit, or enter 's' to stand." << endl;
            cin >> choice;
        }
        return choice == 'h';
    }

private:
    string getCardSymbol(CardRank rank) // Символ для значения
    {
        switch (rank)
        {
        case TWO:
            return "2";
        case THREE:
            return "3";
        case FOUR:
            return "4";
        case FIVE:
            return "5";
        case SIX:
            return "6";
        case SEVEN:
            return "7";
        case EIGHT:
            return "8";
        case NINE:
            return "9";
        case TEN:
            return "10";
        case ACE:
            return "A";
        default:
            return "?";
        }
    }
};



Card getRandomCard() // Рандомная карта
{

    CardSuit suit = static_cast<CardSuit>(rand() % 4);
    CardRank rank = static_cast<CardRank>(rand() % 10);
    return Card(suit, rank);
}

class Dealer
{
public:
    vector<Card> hand;

    void addCard(Card card) // Добавление карты
    {
        hand.push_back(card);
    }

    void displayHand() // Показать карты дилера
    {
        cout << "Dealer's hand: ";
        for (const auto &card : hand)
        {
            cout << getCardSymbol(card.rank) << " ";
        }
        cout << endl;
    }
    int calculateScore() // Счет в руке дилера
    {
        int score = 0;
        int aceCount = 0;

        for (const auto &card : hand)
        {
            if (card.rank == ACE)
            {
                aceCount++;
            }
            else
            {
                score += card.rank + 2;
            }
        }
        while (aceCount > 0 && score <= 11)
        {
            score += 10;
            aceCount--;
        }
        return score;
    }

private:
    string getCardSymbol(CardRank rank) // Символ для значения
    {
        switch (rank)
        {
        case TWO:
            return "2";
        case THREE:
            return "3";
        case FOUR:
            return "4";
        case FIVE:
            return "5";
        case SIX:
            return "6";
        case SEVEN:
            return "7";
        case EIGHT:
            return "8";
        case NINE:
            return "9";
        case TEN:
            return "10";
        case ACE:
            return "A";
        default:
            return "?";
        }
    }
};

void playLocalGame(Player &player1, Player &player2) // Локальная игра
{
    cout << "Local game started!" << endl;

    // Ход первого игрока
    player1.addCard(getRandomCard()); // Добавление рандомной карты
    player1.addCard(getRandomCard()); // Добавление рандомной карты
    player1.displayHand();
    while (player1.HitOrStand() && player1.calculateScore() < 21)
    {
        player1.addCard(getRandomCard()); // Добавление рандомной карты при взятии
        player1.displayHand();
    }
    cout << "Player 1's score: " << player1.calculateScore() << endl;

    // Ход второго игрока
    player2.addCard(getRandomCard()); // Добавление рандомной карты
    player2.addCard(getRandomCard()); // Добавление рандомной карты
    player2.displayHand();
    while (player2.HitOrStand() && player2.calculateScore() < 21)
    {
        player2.addCard(getRandomCard()); // Добавление рандомной карты при взятии
        player2.displayHand();
    }
    cout << "Player 2's score: " << player2.calculateScore() << endl;

    if (player1.calculateScore() > 21)
    {
        cout << "Player 2 wins!!";
    }
    else if (player2.calculateScore() > 21)
    {
        cout << "Player 1 wins!!";
    }
    else if (player1.calculateScore() > player2.calculateScore())
    {
        cout << "Player 1 wins!!";
    }
    else if (player1.calculateScore() < player2.calculateScore())
    {
        cout << "Player 2 wins!!";
    }
    else
    {
        cout << "It's a tie!!";
    }
}

void playDealerGame(Player &player, Dealer &dealer) // Игра с ботом
{
    cout << "Dealer game started!" << endl;

    // Ход игрока
    player.addCard(getRandomCard()); // Добавление рандомной карты
    player.addCard(getRandomCard()); // Добавление рандомной карты
    player.displayHand();
    while (player.HitOrStand() && player.calculateScore() < 21)
    {
        player.addCard(getRandomCard()); // Добавление рандомной карты при взятии
        player.displayHand();
    }
    cout << "Player 1's score: " << player.calculateScore() << endl;
}
