public class Particao {

    public static int DevolverParticoes(int number,int maxsize){
        int value=0;

        if(number==0&&maxsize>=0){
            value= 1;
        }
        else if(number>0&&maxsize==0){
            value= 0;
        }
        else if(number<maxsize&&maxsize>0){

            value= DevolverParticoes(number, maxsize-1);
        }
        else if(number >= maxsize&&maxsize >0){
            value= DevolverParticoes(number-maxsize,maxsize) + DevolverParticoes(number,maxsize -1);
        }
        return value;

    }
    
}
