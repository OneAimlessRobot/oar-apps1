

class gridObject{

SDL_Color color;
int height,
    width,
    thickness,
    horizontalSpacing,
    verticalSpacing,
    margin;

char fontPath[1280];

public:
    gridObject(int height,int width,int thickness,int horizontalSpacing,int verticalSpacing,int margin,int r,int g,int b, int a,const char*fontPath);

    void renderGrid(SDL_Renderer* renderer,int xOrigin,int yOrigin);


};
