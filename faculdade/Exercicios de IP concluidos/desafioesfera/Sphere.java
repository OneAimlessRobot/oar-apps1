
public class Sphere{
private double a,b,c,radius;
private int value;

    public Sphere(double x,double y,double z,double r){

        a=x;
        b=y;
        c=z;
        radius=r;


    }

    public double GetVolume(){

        return (4*Math.PI* Math.pow(radius,3))/3;
    }

    public boolean GetPointLocation(Point p1){

        if(Math.sqrt(Math.pow(this.GetAbcissa()-p1.getX(),2)+Math.pow(this.GetOrdenada()-p1.getY(),2)+Math.pow(this.GetCota()-p1.getZ(),2))<=this.GetRadius()){
            return true;
        }
        else{
            return false;
        }

    }
    public int GetSphereLocation(Sphere s2){

     if(Math.sqrt(Math.pow(this.GetAbcissa()-s2.GetAbcissa(),2)+Math.pow(this.GetOrdenada()-s2.GetOrdenada(),2)+Math.pow(this.GetCota()-s2.GetCota(),2))<=(Math.abs(this.GetRadius()-s2.GetRadius()))&&(this.GetRadius()<s2.GetRadius())){
        value= 3;
    }
        else if((Math.sqrt(Math.pow(this.GetAbcissa()-s2.GetAbcissa(),2)+Math.pow(this.GetOrdenada()-s2.GetOrdenada(),2)+Math.pow(this.GetCota()-s2.GetCota(),2))<=(Math.abs(this.GetRadius()-s2.GetRadius())))&&(this.GetRadius()>s2.GetRadius())){
            value =2;
        }
        else if((Math.sqrt(Math.pow(this.GetAbcissa()-s2.GetAbcissa(),2)+Math.pow(this.GetOrdenada()-s2.GetOrdenada(),2)+Math.pow(this.GetCota()-s2.GetCota(),2))<=(this.GetRadius()+s2.GetRadius()))&&(Math.sqrt(Math.pow(this.GetAbcissa()-s2.GetAbcissa(),2)+Math.pow(this.GetOrdenada()-s2.GetOrdenada(),2)+Math.pow(this.GetCota()-s2.GetCota(),2))>(Math.abs(this.GetRadius()-s2.GetRadius())))){
            value= 1;
        }
        else if(Math.sqrt(Math.pow(this.GetAbcissa()-s2.GetAbcissa(),2)+Math.pow(this.GetOrdenada()-s2.GetOrdenada(),2)+Math.pow(this.GetCota()-s2.GetCota(),2))>(this.GetRadius()+s2.GetRadius())){
            value =4;
        }
        return value;

    }

    public double GetRadius(){

        return radius;
    }

    public double GetAbcissa(){


        return a;
    }

    public double GetOrdenada(){

        return b;
    }
    public double GetCota(){

        return c;
    }
    public double GetSurfaceArea(){


        return Math.PI*4*Math.pow(radius,2);
    }


}