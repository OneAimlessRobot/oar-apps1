import java.util.Scanner;
import java.io.*;


public class Main{
public static void main(String[] args) throws IOException{


try{
Scanner in =new Scanner(System.in);
String filename=in.nextLine();
FileInputStream fread=new FileInputStream(filename);
File ficheiro=new File(filename.toUpperCase());
FileOutputStream fwrite= new FileOutputStream(ficheiro.getName());
ByteVec vec=new ByteVec();

while(fread.available()>0){


byte tmp=(byte)fread.read();
vec.insertByte(tmp);
/*System.out.println("Próximo slot a ser enchido "+ vec.getFillSlot());
System.out.println("Próximo slot a ser devolvido "+ vec.getReturnSlot());*/


}
while(vec.hasNext()){

byte tmp= vec.getNextByte();
fwrite.write(tmp);
/*
System.out.println("Próximo slot a ser enchido "+ vec.getFillSlot());
System.out.println("Próximo slot a ser devolvido "+ vec.getReturnSlot());
*/

}
in.close();
fread.close();
fwrite.close();

}
catch(FileNotFoundException e){

System.out.printf("Erro na abertura do ficheiro\n");

}


}
}
