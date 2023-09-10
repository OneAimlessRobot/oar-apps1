public class Record {
    private String title, authorName;
    private int year;

    public Record(String authorName, String title, int year) {
        this.title = title;
        this.authorName = authorName;
        this.year = year;
    }

    public String getAuthor() {
        return this.authorName;
    }

    public String getTitle() {

        return this.title;

    }

    public int getYear() {
        return this.year;
    }

    public int compareRecords(Record anotha){

        if(this.getYear()-anotha.getYear()>0){
            return 1;
        }
        else if(this.getYear()-anotha.getYear()<0){
            return -1;
        }
        else{
        if(this.getAuthor().compareTo(anotha.getAuthor())>0){

            return 2;
        }
        else if(this.getAuthor().compareTo(anotha.getAuthor())<0){

            return -2;


        }
        else{
            if(this.getTitle().compareTo(anotha.getTitle())>0){

                return 3;
            }
            else if(this.getTitle().compareTo(anotha.getTitle())<0){
                return -3;
            }
            else{
                return 0;
            }
        }
    }
            
        /*Numeros negativos se o objeto ao qual se aplica o metodo precede o objeto no parametro em 
        ordem alfabetica */
        
    }
}
