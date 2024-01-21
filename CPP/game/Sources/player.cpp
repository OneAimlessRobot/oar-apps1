#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Includes/entity.hpp"
#include "../Includes/projectile.hpp"
#include "../Includes/projIterator.hpp"
#include "../Includes/volleyGen.hpp"
#include "../Includes/player.hpp"

    Player::Player(float xInit, float yInit, float size)
    {

 	this->body = (SDL_FRect *)malloc(sizeof(SDL_FRect));
        this->body->x = xInit;
        this->body->y = yInit;
        this->size = size;
        this->body->w = this->size;
        this->body->h = this->size;
    }

    void Player::movePlayerX(float dist)
    {

        this->body->x += dist;
    }
    void Player::movePlayerY(float dist)
    {

        this->body->y += dist;
    }

    void Player::growPlayer(float increment)
    {

        this->body->h += increment;
        this->body->w += increment;
    }

    void Player::shrinkPlayer(float increment)
    {

        if (this->body->w != 0)
        {
            this->body->h -= increment;
            this->body->w -= increment;
        }
    }
    float Player::getSize()
    {
        return this->body->h;
    }
    float Player::getPlayerX()
    {

        return this->body->x;
    }
    float Player::getPlayerY()
    {

        return this->body->y;
    }

    SDL_FRect *Player::keepPlayerVisible(SDL_Renderer *someRend, int *mousex, int *mousey)
    {

        SDL_SetRenderDrawColor(someRend, 100, 100, 100, 255);

        SDL_RenderFillRectF(someRend, body);

        SDL_GetMouseState(mousex, mousey);

        drawCrossHairF(someRend, 4,(float) *mousex,(float) *mousey);
        return this->body;
    }

    void Player::destroyPlayer()
    {
        free(this->body);
    }
