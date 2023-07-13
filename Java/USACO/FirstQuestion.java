package USACO;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class FirstQuestion {
    public static void test() throws FileNotFoundException {
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

        int sum = Math.max(guess[0], Math.max(guess[1], guess[2]));
        PrintWriter pw = new PrintWriter(new File("shell.out"));

        // System.out.println(sum);
        pw.print(sum);
        pw.close();
        scan.close();
    }
}
