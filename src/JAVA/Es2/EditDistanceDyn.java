import java.util.*;

/**
* The edit distance program is used to calculate the edit distance between
* two strings
*
*
* @author  Fabio De Palma
* @version 2.0
*/

class EditDistanceDyn{
    /**
    * @param a
    * @param b
    * @param c
    * @return int: This return will be the minimum number of a, b and c
    */
    public static int min(int a, int b, int c){
        int min = Math.min(a,b);
        return Math.min(min, c);
    }
    /**
    * This method return the number of operations request to transform
    * one String ( s1 ) into the other String ( s2 ). (EditDistance)
    *
    * this method was implemented with dynamic programming, then use the matrix
    * to store results of subproblems
    * @param s1 this is a String
    * @param s2 this is a String
    * @return int: Return edit distance betwen s1 and s2
    */
    public static int distanceDyn(String s1, String s2, int i, int j, int[][] distance){
        if(s1 == null || s2 == null){
            return -1;
        }
        int dNoop;
        int dCanc;
        int dIns;
        if(i == 0)
            return j;
        else if(j == 0)
            return i;
        else if(distance[i-1][j-1] != 0)
            return distance[i-1][j-1];
        else{
            if(s1.charAt(i-1) == s2.charAt(j-1)){
                dNoop = distance[i-1][j-1] = distanceDyn(s1, s2, i-1, j-1, distance);
            }else{
                dNoop = Integer.MAX_VALUE;
            }
            dCanc = 1 + distanceDyn(s1, s2, i-1, j, distance );
            dIns   = 1 + distanceDyn(s1, s2, i,j-1, distance );
            distance[i-1][j-1] = min(dNoop, dCanc,dIns);
        }
        return distance[i-1][j-1];
    }



}
