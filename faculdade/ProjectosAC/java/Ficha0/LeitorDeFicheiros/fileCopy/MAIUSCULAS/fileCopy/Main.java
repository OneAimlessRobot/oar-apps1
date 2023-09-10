import java.util.*;
import java.io.*;


public class Main{

public static void main(String[] args) throws IOException{

try{
Scanner input=new Scanner(System.in);
String fname=input.nextLine(),copyName=input.nextLine();
FileInputStream fin= new FileInputStream(fname);
FileOutputStream fout=new FileOutputStream(new File(copyName));

while(fin.available()>0){

char c=(char)fin.read();
fout.write(Character.toUpperCase(c));
}

input.close();
fin.close();
fout.close();
}
catch(FileNotFoundException e){

System.out.println("Ficheiro nao encontrado");
}

}

}
