import java.util.*;
import java.io.*;

public class MooBuzz {
    public static void main(String[] args) throws FileNotFoundException {
        solution2();
    }
    
    public static void solution1() throws FileNotFoundException {
        Scanner in = new Scanner(new File("moobuzz.in"));
        int n = in.nextInt();
        int count = 0;
        int r = 1;
        while (count < n) {
            if (r % 3 != 0 && r % 5 != 0) {
                count++;
            }
            r++;
        }

        PrintWriter pw = new PrintWriter(new File("moobuzz.out"));
        pw.print(r - 1);
        pw.close();
    }

    public static void solution2() throws FileNotFoundException {
        Scanner in = new Scanner(new File("moobuzz.in"));
        int n = in.nextInt();

        int left = 1;
        int right = Integer.MAX_VALUE;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int divisibleCount = mid / 3 + mid / 5 - mid / 15;
            int notDivisibleCount = mid - divisibleCount;

            if (notDivisibleCount < n) {
                left = mid + 1;
            } else if (notDivisibleCount > n) {
                right = mid - 1;
            } else {
                ans = mid;
                while (ans % 3 == 0 || ans % 5 == 0)
                    ans--;
                break;
            }
        }

        PrintWriter pw = new PrintWriter(new File("moobuzz.out"));
        pw.print(ans);
        pw.close();
    }
}
