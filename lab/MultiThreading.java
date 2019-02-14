
class myRunnable implements Runnable{
    @Override
    synchronized public void run(){
        for( int i = 0; i < 100; i++ ){
            System.out.print("******"+Thread.currentThread().getName());
            System.out.println("########");
            notify();
        }
    }
}

public class MultiThreading {
    public static void main( String args[] ){
        Runnable threadJob = new myRunnable();
        Thread T1 = new Thread(threadJob);
        Thread T2 = new Thread(threadJob);
        T1.setName("Mohit");
        T2.setName("Go code");
        T1.start();
        T2.start();

    }
}
