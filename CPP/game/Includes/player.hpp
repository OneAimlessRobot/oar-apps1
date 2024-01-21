#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player : public Entity
{
private:
    SDL_FRect *body;
    float size;

public:
    Player(float xInit, float yInit, float size);
    void movePlayerX(float dist);
    void movePlayerY(float dist);
    void growPlayer(float increment);
    void shrinkPlayer(float increment);
    float getSize();
    float getPlayerX();
    float getPlayerY();
    SDL_FRect *keepPlayerVisible(SDL_Renderer *someRend, int *mousex, int *mousey);
    void destroyPlayer();
};
#endif
