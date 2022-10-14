import java.util.Scanner;

public class oct_13 {

    public static boolean useLoop(int[] arr, int targetValue) {
        for (int s: arr) {
            if (s == targetValue)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int j = 0; j < t; j++) {
            int ans = 0;
            int a = sc.nextInt();
            int[] arr = new int[a];
            for (int i = 0; i < arr.length; i++) {
                int b = sc.nextInt();
                if (useLoop(arr, b)) {
                    ans = 1;
                    System.out.println("NO");
                    break;
                }
                arr[i]=b; 
            }
            // System.out.println(ans);
            if (ans==0) {
                System.out.println("YES");
            }
        }
    }
}
