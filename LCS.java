import java.util.Scanner;

public class LCS {

    public static void main(String[] args) {

        String text1 = "";
        String text2 = "";
        System.out.println("Enter both the strings");
        Scanner sc = new Scanner(System.in);
        text1 = sc.nextLine();
        text2 = sc.nextLine();

        int[][] dp = new int[text1.length() + 1][text2.length() + 1];

        // Fill the matrix
        for (int i = 0; i < text1.length() + 1; i++) {
            for (int j = 0; j < text2.length() + 1; j++) {
                dp[i][j] = 0;
            }
        }

        int max = 0;

        // Start looping throught the text1 and text2
        for (int i = 1; i < text1.length() + 1; i++) {
            for (int j = 1; j < text2.length() + 1; j++) {

                // If characters match
                // fill the current cell by adding one to the diagonal value
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    System.out.print("Curr element is matched so cheking for substrings     : " );
                    System.out.println(text1.substring(i-1) + " and " + text2.substring(j-1));
                } else {
                    // If characters do not match
                    // Fill the cell with max value of previous row and column
                    System.out.print("Curr element is not matched so cheking for substrings : ");
                    System.out.println(text1.substring(i-1) + " and " + text2.substring(j) +" or " + text1.substring(i) +" and " + text1.substring(j-1));
                    

                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }

                // Keep track of the MAXIMUM value in the matrix
                max = Math.max(max, dp[i][j]);
            }
        }
        

        String ans = "";
        int i = text1.length(), j = text2.length();
        while (i > 0 && j > 0) {
            // If current character in both the strings are same, then current character is
            // part of LCS
            if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                ans += text1.charAt(i - 1);
                i--;
                j--;
            }
            // If current character in X and Y are different & we are moving upwards
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            // If current character in X and Y are different & we are moving leftwards
            else {
                j--;
            }
        }

        
        String revAns = "";

        
        

        System.out.print("\n\nMax length of subsequence is-->");
        System.out.println(max);
        System.out.print("subsequence is-->");
        
        for (int k = 0; k < ans.length(); k++) {
            revAns = ans.charAt(k) + revAns;
        }
        System.out.println(revAns);



    }

}