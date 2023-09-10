public class Lamp {

    private int lampIsOn;

    public Lamp() {

        lampIsOn = 0;

    }

    public void TurnOn() {

        lampIsOn = 1;
    }

    public void TurnOff() {

        lampIsOn = 0;
    }

    public int IsOn() {

        return lampIsOn;
    }

}