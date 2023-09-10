public class Coupon {

    private static final int MAX_VALUE=10000;
    public int currentValue;

    public Coupon(int initial){

        currentValue=initial;
    }

    public int getCouponValue(){
        return this.currentValue;
    }
    public void deductValue(int subtractive){

        this.currentValue-=subtractive;


    }

    
    
}
