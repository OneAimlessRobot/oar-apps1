
template<typename T>
       Iterator<T>::Iterator(std::vector<T> &vec){

            this->internalVec=vec;
            this->cursor=0;


        }

template<typename T>
        void Iterator<T>::increment(){

            cursor++;


        }

template<typename T>
        int Iterator<T>::isOver(){

           return this->cursor>=internalVec.size();

        }

template<typename T>
        T Iterator<T>::getCurrent(){

            return internalVec[cursor];
        }
template<typename T>
        T Iterator<T>::getNext(){

            return internalVec[cursor++];
        }

template<typename T>
        Iterator<T>::~Iterator(){



        }


