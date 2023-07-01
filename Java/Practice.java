
/**
 javac Practice.java
 java Practice (case sensitive)
 **/
import java.util.*;
import java.io.*;

public class Practice {
    public static void main(String[] args) throws FileNotFoundException {
        // Scanner scan = new Scanner(System.in);
        Scanner scan = new Scanner(new File("shell.in"));
        int n = scan.nextInt();
        int[] p1 = new int[3];
        int[] guess = new int[3];
        for (int i = 0; i < 3; i++) {
            guess[i] = 0;
            p1[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            int g = scan.nextInt();

            int tmp = p1[a - 1];
            p1[a - 1] = p1[b - 1];
            p1[b - 1] = tmp;

            guess[p1[g - 1]]++;

        }

        int sum = 0;
        for (int i = 0; i < 3; i++) {
            if (guess[i] > sum) {
                sum = guess[i];
            }
        }
        PrintWriter pw = new PrintWriter(new File("shell.out"));

        // System.out.println(sum);
        pw.print(sum);
        pw.close();
        scan.close();
    }

}
