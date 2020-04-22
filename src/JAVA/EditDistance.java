
class EditDistance{
    public static String rest(String s){
        return s.substring(1);
    }

    public static int min(int a, int b, int c){
        int min = Math.min(a,b);
        return Math.min(min,c);
    }

    public static int distance(String s1, String s2){
        int dNoop;
        int dCanc;
        int dIns;
        if(s1.length() == 0){
            return s2.length();
        }else if(s2.length() == 0) {
            return s1.length();
        }else{
            if(s1.charAt(0)== s2.charAt(0)){
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



    public static void main(String[] args) {
        String s1 = "tassa";
        String s2 = "passato";
        System.out.println(distance(s1,s2));
    }
}
