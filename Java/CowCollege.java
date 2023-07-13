import java.util.*;
import java.io.*;

public class CowCollege {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        int[] tuitions = new int[N];
        for (int i = 0; i < N; i++) {
            tuitions[i] = scanner.nextInt();
        }

        Arrays.sort(tuitions);

        long totalMoney = 0;
        int optimalTuition = 0;

        for (int i = 0; i < N; i++) {
            int currentTuition = tuitions[i];
            long revenue = (long) currentTuition * (N - i);

            if (revenue > totalMoney) {
                totalMoney = revenue;
                optimalTuition = currentTuition;
            }
        }

        System.out.println(totalMoney + " " + optimalTuition);
    }
}
