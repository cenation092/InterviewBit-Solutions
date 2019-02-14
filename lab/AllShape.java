import java.util.*;

class shape{
    double area = 0.0;
    Scanner in = new Scanner(System.in);
    void square(){
        double l = in.nextDouble();
        area = l * l;
    }
    void rectangle(){
        double l = in.nextDouble();
        double r = in.nextDouble();
        area = l * r;
    }
    void circle(){
        double r = in.nextDouble();
        area = r * r * Math.acos(0);
    }
}

public class AllShape {
    public static void  main( String args[]){
        shape S = new shape();
        S.square();
        System.out.println(S.area);
        S.rectangle();
        System.out.println(S.area);
    }
}
