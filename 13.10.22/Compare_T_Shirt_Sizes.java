// https://codeforces.com/contest/1741/problem/A

import java.util.Scanner;
 
 
public class Compare_T_Shirt_Sizes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int x = 0; x < t; x++) {
            String s1 = sc.next();
            String s2 = sc.next();
            char l1 = s1.charAt(s1.length()-1);
            char l2 = s2.charAt(s2.length()-1);
 
            Double a1 = 0.0;
            Double a2 = 0.0;
 
            switch (l1) {
                case 'S':
                    a1 = Math.pow(0.5, s1.length());
                    break;
                case 'M':
                    a1 = 1.0;
                    break;
                case 'L':
                    a1 = Math.pow(2, s1.length());
                    break;
                default:
                    break;
            }
 
            switch (l2) {
                case 'S':
                    a2 = Math.pow(0.5, s2.length());
                    break;
                case 'M':
                    a2 = 1.0;
                    break;
                case 'L':
                    a2 = Math.pow(2, s2.length());
                    break;
                default:
                    break;
            }
 
            // System.out.println(a1);
            // System.out.println(a2);
 
            if (a1>a2) {
                System.out.println(">");
            } else if(a1<a2) {
                System.out.println("<");
            }else{
                System.out.println("=");
            }
        }
    }
}