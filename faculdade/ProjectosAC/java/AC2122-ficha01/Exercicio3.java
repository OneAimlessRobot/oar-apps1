
public class Exercicio3 {
  public static void main( String[] args) {
    System.out.print("short: ");
    // pode usar Short.SIZE/8
    System.out.print("size= " + Short.BYTES + " Bytes. ");
    System.out.println("Range = " + Short.MIN_VALUE + ".." + Short.MAX_VALUE);
    System.out.print("integer: ");
    System.out.print("size= " + Integer.BYTES + " Bytes. ");
    System.out.println("Range = " + Integer.MIN_VALUE + ".." + Integer.MAX_VALUE);
    System.out.print("long: ");
    System.out.print("size= " + Long.BYTES + " Bytes. ");
    System.out.println("Range = " + Long.MIN_VALUE + ".." + Long.MAX_VALUE);
    System.out.print("float: ");
    System.out.print("size= " + Float.BYTES + " Bytes. ");
    System.out.println("Range = " + Float.MIN_VALUE + ".." + Float.MAX_VALUE);
    System.out.print("double: ");
    System.out.print("size= " + Double.BYTES + " Bytes. ");
    System.out.println("Range = " + Double.MIN_VALUE + ".." + Double.MAX_VALUE);
  }

/*
Output:
short: size= 2 Bytes. Range = -32768..32767
integer: size= 4 Bytes. Range = -2147483648..2147483647
long: size= 8 Bytes. Range = -9223372036854775808..9223372036854775807
float: size= 4 Bytes. Range = 1.4E-45..3.4028235E38
double: size= 8 Bytes. Range = 4.9E-324..1.7976931348623157E308
*/
}
