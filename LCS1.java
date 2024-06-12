import java.util.Scanner;

/* A Naive recursive implementation of LCS problem in java*/
public class LCS1 {

  /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
  int lcs(String s1, String s2, int m, int n) {
    if (m >= s1.length() || n >= s2.length())
      return 0;
    if (s1.charAt(m) == s2.charAt(n))
      return 1 + lcs(s1, s2, m + 1, n + 1);
    else
      return max(lcs(s1, s2, m, n + 1), lcs(s1, s2, m + 1, n));
  }

  /* Utility function to get max of 2 integers */
  int max(int a, int b) {
    return (a > b) ? a : b;
  }

  public static void main(String[] args) {
    LCS1 lcs = new LCS1();
    String s1 = "";
    String s2 = "";
    System.out.println("Enter both the strings");
    Scanner sc=new Scanner(System.in);
    s1=sc.nextLine();
    s2=sc.nextLine();

    

   

    // int m = s1.length();
    // int n = s2.length();

    System.out.println("Length of LCS is" + " " +
        lcs.lcs(s1, s2, 0, 0));
  }

}
