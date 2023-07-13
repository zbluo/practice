package USACO;

public class DevideAndConquer_MaxSubarraySum {
    public static void test(String[] args) {
        int arr[] = { -2, -5, 6, -2, -3, 1, 5, -6 };
        int n = arr.length;

        int maxSum = USACO.DevideAndConquer_MaxSubarraySum.maxSubarraySum(arr, 0, n - 1);
        System.out.println("Maximum subarray sum: " + maxSum);
    }

    public static int maxCrossingSum(int arr[], int low, int mid, int high) {
        int leftSum = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = mid; i >= low; i--) {
            sum += arr[i];
            if (sum > leftSum)
                leftSum = sum;
        }

        int rightSum = Integer.MIN_VALUE;
        sum = 0;
        for (int i = mid + 1; i <= high; i++) {
            sum += arr[i];
            if (sum > rightSum)
                rightSum = sum;
        }

        return leftSum + rightSum;
    }

    public static int maxSubarraySum(int arr[], int low, int high) {
        if (low == high)
            return arr[low];

        int mid = (low + high) / 2;

        int leftSum = maxSubarraySum(arr, low, mid);
        int rightSum = maxSubarraySum(arr, mid + 1, high);
        int crossingSum = maxCrossingSum(arr, low, mid, high);

        return Math.max(Math.max(leftSum, rightSum), crossingSum);
    }
}
