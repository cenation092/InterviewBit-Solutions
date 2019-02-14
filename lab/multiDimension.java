import java.util.Scanner;

public class multiDimension {
    static int a1[][] = new int[5][5];
    static int a2[][] = new int[5][5];

    static void product(){
        for( int i = 0; i < 5; i++ ){
            for( int j = 0; j < 5; j++ ){
                int sum = 0;
                for( int k = 0; k < 5; k++ ){
                    sum += a1[i][k] * a2[k][j];
                }
                System.out.print(sum + " ");
            }
            System.out.println(" ");
        }
    }

    public static void main( String args[] ){
        Scanner in = new Scanner(System.in);
        for( int i = 0; i < 5; i++ ){
            for( int j = 0; j < 5; j++ ){
                a1[i][j] = in.nextInt();
            }
        }
        for( int i = 0; i < 5; i++ ){
            for( int j = 0; j < 5; j++ ){
                a2[i][j] = in.nextInt();
            }
        }
        product();
    }
}
