import java.util.*;

class point{
    int x, y;
    Scanner in = new Scanner(System.in);
    point(){
        x = in.nextInt();
        y = in.nextInt();
    }
    public static double dis( point p1, point p2 ){
        return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
    }
}

public class distance {
    public static void main( String args[] ){
        Scanner in = new Scanner(System.in);
        point p1 = new point();
        point p2 = new point();
        System.out.println(point.dis(p1, p2));
    }
}
