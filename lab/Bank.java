import java.util.*;

public class Bank {
    static class Account{
        int balance;
        int Must;
        Account( int balance, int Must){
            this.balance = balance;
            this.Must = Must;
        }
        synchronized void credit(int req){
            System.out.println(Thread.currentThread().getName());
            System.out.println("current Balance before: " + balance );
            balance += req;
            System.out.println("current Balance : " + balance );
            notify();
        }
        synchronized void debit( int req ) throws InterruptedException {
            System.out.println(Thread.currentThread().getName());
            while ( balance-req < Must){
                System.out.println("Not enough :(");
                wait();
            }
            System.out.println("current Balance before: " + balance );
            balance -= req;
            System.out.println("current Balance : " + balance );
        }
    }

    public static void main( String args[] ) {
        Account A = new Account(1000, 500);
        Scanner in = new Scanner(System.in);

        while(true){
            int credit = in.nextInt();
            int debit = in.nextInt();
            Thread T1 = new Thread(new Runnable() {
                @Override
                public void run() {

                    A.credit(credit);
                }
            });
            Thread T2 = new Thread(new Runnable() {
                @Override
                public void run() {

                    try {
                        A.debit(debit);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            });
            T1.start();
            T2.start();
        }
    }
}
