/**
* The edit distance program is used to calculate the edit distance between
* two strings
*
*
* @author  Fabio De Palma
* @version 1.0
*/

class EditDistance{
    /**
   * @param s the parameter is type String
   * @return String : Returns a new string that is a substring of this string.
   */
    public static String rest(String s){
        return s.substring(1);
    }
    /**
    * @param a
    * @param b
    * @param c
    * @return int: This return will be the minimum number of a, b and c
    */
    public static int min(int a, int b, int c){
        int min = Math.min(a,b);
        return Math.min(min,c);
    }

    /**
    * This method return the number of operations request to transform
    * one String ( s1 ) into the other String ( s2 ). (EditDistance)
    * then the minimum betwen three operations(dNoop, dCanc, dIns).
    * dNoop = No operation;
    * dCanc = cancellation
    * dIns = insertion
    * @param s1 this is a String
    * @param s2 this is a String
    * @return int: Return edit distance betwen s1 and s2
    */
    public static int distance(String s1, String s2){
        if(s1 == null || s2 == null){
            return -1;
        }
        int dNoop;
        int dCanc;
        int dIns;
        if(s1.length() == 0){
            return s2.length();
        }else if(s2.length() == 0) {
            return s1.length();
        }else{
            if(s1.charAt(0) == s2.charAt(0)){
                s1 = rest(s1);
                s2 = rest(s2);
                dNoop = distance(s1, s2);
                return dNoop;
            }else{
                dNoop = Integer.MAX_VALUE;
            }
            dCanc = 1 + distance(s1, rest(s2));
            dIns = 1 + distance(rest(s1), s2);
            return min(dNoop, dCanc,dIns);
        }

    }

}
