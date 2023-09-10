public class Arqueologo {
    private static final int PLAYING=1;
    private static final int KICKED=0;
    
    private String name;
    private int merit;
    private int status;
    private int position;


    public Arqueologo(String nome,int initial,int startingPoint){

        name= nome;
        merit=initial;
        status=PLAYING;
        position=startingPoint;


    }

    public void setPlayerStatus(int newstatus){

        this.status=newstatus;
    }
    
    public void addMerit(int ammount){
        this.merit+=ammount;
    }
    public void movePlayer(int distance){

        this.position+=distance;
    }
    public int getPlayerMerit(){

        return this.merit;
    }
    public String getPlayerName(){

        return this.name;
    }
    public int getPlayerStatus(){

        return this.status;
    }
    public int getPlayerPos(){
        return this.position;
    }

    public void kickPlayer(){

        this.status=KICKED;
    }
    public boolean isKicked(){
        return this.status==KICKED;
    }
}
