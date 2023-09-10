public class Rect {
    private double left;
    private double right;
    private double top;
    private double bottom;

    public Rect(double xMin, double xMax, double yMin, double yMax){

    left=xMin;
    right=xMax;
    top=yMax;
    bottom= yMin;
    }

    public double GetPerimeter() {

        return 2 * (this.GetWidth(left,right) + this.GetHeight(bottom,top));
    }

    public double GetWidth(double xMin, double xMax) {
        return (right - left);
    }

    public double GetHeight(double yMin, double yMax) {
        return  (top - bottom);
    }

   public Rect GetHull(Rect other){
        double xMin = Math.min(left,other.GetLeft());
        double xMax= Math.max(right,other.GetRight());
        double yMax= Math.max(top,other.GetTop());
        double yMin= Math.min(bottom, other.GetBottom());
        return new Rect(xMin, xMax, yMin, yMax);
    }
    public double GetLeft(){

        return left;
    }

    public double GetRight(){

        return right;

    }
    public double GetTop(){

        return top;
    }
    public double GetBottom(){
        return bottom;
    }
public boolean isSquare(){

    if(this.GetWidth(left, right) == this.GetHeight(top,bottom)){
        return true;
        
    }
    else{ 
        return false;
    }
}

        /*Ok, o que é que eu já consigo fazer? Consigo, na class Main, invocar um retângulo, através de um cons-
        trutor, um retângulo que tem como dimensões as que eu meter na consola, quando o programa iniciar.
        Depois, na classe Rect, o retângulo em si, tendo os valores que eu meti como ponto de partida, vai atribui-los a variáveis
        só usaveis pela classe Rect em si. Depois criei os métodos GetWidth, que subtrai o xmin do xmáx para obter a largura
        e o métido get Height que subtrai o ymin do ymax para obter a altura. ymin e ymax são as inputs do utilizador*/
}