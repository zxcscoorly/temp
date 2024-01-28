#include "final.hpp"

int main()
{
    srand(time(0));

    Player p1("A", 12), p2("B", 14);
    playLocalGame(p1, p2);
    system("pause");
}