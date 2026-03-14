public class Branchfast {
    static final int size = 1024 * 1024 * 256; // big array!
    static int A[] = new int[size];
    static long prevTime;

    static void startTimer() {
        prevTime = System.currentTimeMillis();
    }

    static void stopPrintTimer() {
        System.out.println("Elapsed time: " + (System.currentTimeMillis() - prevTime));
    }

    public static void main(String[] args) {
        java.util.Random rand = new java.util.Random();
        for (int i = 0; i < size ; i++) {
            A[i] = rand.nextInt(100); // fill with random number between 0-100
        }

        int large = 0;
        int small = 0;
        int k = 50;
        startTimer();
        for (int i = 0 ; i < size ; i++) {
            int pred = (A[i] - k) >> 31;
            small -= pred;
            large += 1 + pred;
        }
        stopPrintTimer();

        System.out.println("There were " + (small / 1000) + " things less than "   + k); 
        System.out.println("       and " + (large / 1000) + " things larger than " + k);
    }
}
