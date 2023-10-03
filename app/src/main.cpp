#include <eng.hpp>

int main()
{
    eng::Game* game = new eng::Game("My Game");
    game->Run();
    delete game;
    return 0;
}
