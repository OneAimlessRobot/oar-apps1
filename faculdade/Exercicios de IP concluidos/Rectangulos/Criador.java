import java.util.Scanner;

public class Criador {

    public static void main(String[] args) {
        System.out.print("Olá! Vamos resolver o problema do Retângulo:\n");
        System.out.println("Insere aqui os dados do retângulo (x min, xmax, y min, y max):");
        Scanner input = new Scanner(System.in);
        double left = input.nextDouble();
        double right = input.nextDouble();
        double bottom = input.nextDouble();
        double top = input.nextDouble();
        input.nextLine();
        Rect r1 = new Rect(left, right, bottom, top);
        System.out.println("Insere aqui os dados do OUTRO retângulo (x min, xmax, y min, y max):");
        left = input.nextDouble();
        right = input.nextDouble();
        bottom = input.nextDouble();
        top = input.nextDouble();
        input.nextLine();
        Rect r2 = new Rect(left, right, bottom, top);
        Rect hull = r1.GetHull(r2);
        input.close();

        System.out.println(r1.GetPerimeter());
        System.out.println(r2.GetPerimeter());
        System.out.println(hull.GetPerimeter());

        if (hull.isSquare()) {
            System.out.println("the hull is a square");
            System.out.println(hull.isSquare());
        }
        else
        {
            System.out.println(hull.isSquare());
        }
    }

}
