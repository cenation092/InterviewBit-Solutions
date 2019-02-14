import java.util.*;

public class producerConsumer {

    static class Buffer{
        private Queue<Integer> have;
        private int size;

        Buffer( int size ){
            this.size = size;
            this.have = new LinkedList<>();
        }

        public synchronized void produce() throws InterruptedException {
            int value = 0;
            while(true){
                while (have.size() == size) {
                    // wait for consume
                    wait();
                }
                have.add(value);
                System.out.println("Produce : " + value);
                value++;
                // notify the consumer
                notify();
                Thread.sleep(1000);
            }
        }

        public synchronized void consume() throws InterruptedException {
            while(true){
                if( have.size() == 0 ){
                    // wait for produce
                    wait();
                }
                int value = have.poll();
                System.out.println("consume : " + value);
                // notify the producer
                notify();
                Thread.sleep(1000);
            }
        }
    }



    public static void main( String args[] ) throws InterruptedException {
        Buffer b = new Buffer(5);
        Thread PThread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    b.produce();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        Thread CThread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    b.consume();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        PThread.start();
        CThread.start();
        PThread.join();
        CThread.join();
    }
}
