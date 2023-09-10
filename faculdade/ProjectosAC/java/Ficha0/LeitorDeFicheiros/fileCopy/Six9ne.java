import java.util.*;
import java.io.*;


public class Six9ne{

public static void main(String[] args) throws IOException{

Scanner input=new Scanner(System.in);
String fname=input.nextLine();
int size=input.nextInt();
input.nextLine();
FileInputStream fread= new FileInputStream(fname);
File ficheiro =new File(fname+" (2)");
FileOutputStream fwrite=new FileOutputStream(ficheiro);

byte[] array=new byte[size];

fread.read(array);
fwrite.write(array,0,size);


input.close();
fread.close();
fwrite.close();
}

}
