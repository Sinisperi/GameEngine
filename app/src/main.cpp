#include <eng.hpp>
#include "TestGame.hpp"
int main()
{
    eng::Game* game = new TestGame;
    game->Run();
    delete game;
    return 0;
}
