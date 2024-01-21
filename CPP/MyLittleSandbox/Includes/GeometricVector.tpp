

template<typename T>
        GeometricVector<T>::GeometricVector(T startX,T startY,T deltaX,T deltaY,Direction directionInit,T length){
            this->length=length;
            this->start=(SDL_FPoint){startX,startY};
            this->deltaX=deltaX;
            this->deltaY=deltaY;
            this->direction=directionInit;
            this->calculateTip();

        }

template<typename T>
        void GeometricVector<T>::setTip(SDL_FPoint point){

            this->tip=point;
        }

template<typename T>
        void GeometricVector<T>::setStart(SDL_FPoint point){
            this->start=(SDL_FPoint){point.x,point.y};
            this->calculateTip();
            }

template<typename T>
        void GeometricVector<T>::calculateTip(){

            int sign=this->getDirection();
            this->tip.x=this->start.x+sign*round(this->getLength()*cos(atan2(this->getDy() , this->getDx())));
            this->tip.y=this->start.y+sign*round(this->getLength()*sin(atan2(this->getDy() , this->getDx())));


        }

template<typename T>
        void GeometricVector<T>::setDirection(Direction direction){

            this->direction=direction;
        }
template<typename T>
        SDL_FPoint GeometricVector<T>::getTip(){

            return this->tip;
        }
template<typename T>
        SDL_FPoint GeometricVector<T>::getStart(){

            return this->start;
        }

template<typename T>
        void GeometricVector<T>::setLength(T value){
            this->length=value;
            this->calculateTip();

        }

template<typename T>
        void GeometricVector<T>::setDx(T value){
            this->deltaX=value;
            this->calculateTip();

        }
template<typename T>
        void GeometricVector<T>::setDy(T value){
            this->deltaY=value;
            this->calculateTip();
        }
template<typename T>
        T GeometricVector<T>::getLength(){
            return this->length;

        }
template<typename T>
        void GeometricVector<T>::render(SDL_Renderer* renderer,SDL_Color color){

                SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,255);
                float arrowWidth=this->getLength()*0.25;
                SDL_FRect rect=(SDL_FRect){this->getTip().x-arrowWidth*0.5,this->getTip().y-arrowWidth*0.5,arrowWidth,arrowWidth};
                SDL_RenderDrawLineF(renderer,this->getStart().x,this->getStart().y,this->getTip().x,this->getTip().y);
                SDL_RenderFillRectF(renderer,&rect);
        }
template<typename T>
        int GeometricVector<T>::getDirection(){

            if(this->direction==positive){
                return 1;
            }
            else if(this->direction==negative){

                return -1;

            }
            else{
                return 0;
            }
        }
template<typename T>
        T GeometricVector<T>::getDx(){
            return this->deltaX;

        }
template<typename T>
        T GeometricVector<T>::getDy(){

            return this->deltaY;
        }
template<typename T>
        GeometricVector<T>* GeometricVector<T>::add(GeometricVector* other){
            other->setStart(this->getTip());
            SDL_FPoint start=this->getStart();
            SDL_FPoint tip=other->getTip();
            T deltaXv=other->getTip().x-this->getStart().x;
            T deltaYv=other->getTip().y-this->getStart().y;
            GeometricVector<T> * result=new GeometricVector<T>(this->getStart().x,this->getStart().y,deltaXv,deltaYv,positive,aux::distBetPoints(&start,&tip));
            return result;


        }
template<typename T>
        GeometricVector<T>* GeometricVector<T>::neutralVector(T x,T y){

            return new GeometricVector<T>(x,y,1,1,positive,0);
        }
template<typename T>
        GeometricVector<T>* GeometricVector<T>::getXComp(){
            float angle1=atan2((float)this->getDy(),(float)this->getDx()),
                    length= sin(angle1)*this->getLength();
            return new GeometricVector<T>(0,0,1,0,positive,length);


        }
template<typename T>
        GeometricVector<T>* GeometricVector<T>::getYComp(){
            float angle1=atan2((float)this->getDy(),(float)this->getDx()),
                    length= cos(angle1)*this->getLength();
            return new GeometricVector<T>(0,0,0,1,positive,length);


        }
template<typename T>
        float GeometricVector<T>::getXLength(){
            return this->getXComp()->getLength();

        }
template<typename T>
        float GeometricVector<T>::getYLength(){
            return this->getYComp()->getLength();

        }
template<typename T>
        float GeometricVector<T>::angleOf2Vectors(GeometricVector* vec1,GeometricVector* vec2){
            float angle1=atan2((float)vec1->getDy(),(float)vec1->getDx());
            float angle2=atan2((float)vec2->getDy(),(float)vec2->getDx());
            return angle1-angle2;


        }

