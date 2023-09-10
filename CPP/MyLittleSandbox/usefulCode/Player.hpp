
class Player : public Entity
{
private:
    SDL_Rect *body = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    int size;

public:
    Player(int xInit, int yInit, int size)
    {

        this->body->x = xInit;
        this->body->y = yInit;
        this->size = size;
        this->body->w = this->size;
        this->body->h = this->size;
    }

    void movePlayerX(int dist)
    {

        this->body->x += dist;
    }
    void movePlayerY(int dist)
    {

        this->body->y += dist;
    }

    void growPlayer(int increment)
    {

        body->h += increment;
        body->w += increment;
    }

    void shrinkPlayer(int increment)
    {

        if (body->w != 0)
        {
            body->h -= increment;
            body->w -= increment;
        }
    }
    int getSize()
    {
        return body->h;
    }
    int getPlayerX()
    {

        return this->body->x;
    }
    int getPlayerY()
    {

        return this->body->y;
    }

    SDL_Rect *keepPlayerVisible(SDL_Renderer *someRend, int *mousex, int *mousey)
    {

        SDL_SetRenderDrawColor(someRend, 100, 100, 100, 255);

        SDL_RenderFillRect(someRend, body);

        SDL_GetMouseState(mousex, mousey);

        drawCrossHair(someRend, 4, *mousex, *mousey);
        return body;
    }

    void destroyPlayer()
    {
        free(body);
    }
};
