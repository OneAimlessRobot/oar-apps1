import java.util.*;

public class Main {

    private static final String 
                                EXIT= "SAIR",
                                SEARCH="CA",
                                PRINT_LIST="LC",
                                CHECK_SONGS_FROM_AUTHOR="LAA",
                                PRINT_LIST_BY_YEAR ="LCO",
                                ADD_ALBUM="RA",
                                PRINT_SONGS_FROM_AUTHOR_SORTED="LAO",
                                KILL="AA";
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);

        Manager j=new Manager();
        String status;
        do{
        String option=in.next();
        status=commandInterpreter(in,j,option);
        }while(status!=EXIT);


        in.close();


        /*Pergunta: como separamos o titulo do nome do autor? Com um enter obrigatorio? Resposta: sim. */

    }

    public static String commandInterpreter(Scanner in,Manager a,String option){

        String state=null;

        if(option.equals(SEARCH)){

            in.nextLine();
            String author=in.nextLine();
            String title=in.nextLine();
            if(a.searchForAlbumRemote(author.trim(), title.trim())==1){
                System.out.printf("Album existente\n");
            }
            else{

                System.out.printf("Album inexistente\n");
            }

        }
        else if(option.equals(PRINT_LIST)){

            ColectionIterator it=a.gimmeAnIterator();

            while(it.hasNext()){
                Record o=it.next();
                System.out.printf("%s ; %s ; %d\n",o.getAuthor(),o.getTitle(),o.getYear());
            }

        }
        else if(option.equals(CHECK_SONGS_FROM_AUTHOR)){

            in.nextLine();
            String pickedAuthor=in.nextLine();
            FilteredIterator it=a.getFilteredIteratorRemote(pickedAuthor);
            while(it.hasNext()){

                Record o =it.next();
                System.out.printf("%s ; %s ; %d\n",o.getAuthor(),o.getTitle(),o.getYear());

            }

        }
        else if(option.equals(PRINT_SONGS_FROM_AUTHOR_SORTED)){

            in.nextLine();
            String pickedAuthor=in.nextLine();
            ColectionIterator it=a.superIterator(pickedAuthor);
            while(it.hasNext()){

                Record o =it.next();
                System.out.printf("%s ; %s ; %d\n",o.getAuthor(),o.getTitle(),o.getYear());

            }

        }
        else if(option.equals(ADD_ALBUM)){

            in.nextLine();
            String author=in.nextLine();
            String title=in.nextLine();
            int year=in.nextInt();

            a.addRecordRemote(author.trim(), title.trim(), year);
            System.out.printf("Album inserido\n");

        }
        else if(option.equals(KILL)){


            in.nextLine();
            String author=in.nextLine();
            String title=in.nextLine();

            a.removeRecordRemote(author.trim(), title.trim());
            System.out.printf("Album removido\n");


        }
        else if(option.equals(PRINT_LIST_BY_YEAR)){

            ColectionIterator it=a.gimmeASortedIterator();

            while(it.hasNext()){
                Record o=it.next();

                System.out.printf("%s ; %s ; %d\n",o.getAuthor(),o.getTitle(),o.getYear());
            }



        }
        else if(option.equals(EXIT)){


            System.out.printf("A colecao tem %d albuns\n",a.getColectionSizeRemote());

            state=EXIT;



        }
        else{
            System.out.printf("Comando invalido\n");
        }

        return state;



    }
    
}
