public class complex {
    double real;
    double imz;

    complex( double real, double imz ){
        this.imz = imz;
        this.real = real;
    }

    public  static complex add( complex c1, complex c2 ){
        complex c = new complex(0,0);
        c.real = c1.real + c2.real;
        c.imz = c1.imz + c2.imz;
        return c;
    }

    public static void main(String args[]){
        complex c1 = new complex(2.3, 4.5);
        complex c2 = new complex(2.3, 4.5);
        complex c = add(c1, c2);
        System.out.println(c.real + "+i" + c.imz);
    }
}
