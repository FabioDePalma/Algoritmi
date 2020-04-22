import java.io.*;
import java.util.*;

class EditDistanceDyn{

    private static int min(int a, int b, int c){
        int min = Math.min(a,b);
        return Math.min(min, c);
    }

    public int distanceDyn(String s1, String s2, int i, int j, int[][] distance){
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

    public String[] readCorrectme(String[] a){
        File file = new File("../../test/test2/correctme.txt");
        try{
            Scanner sc = new Scanner(file);
            String line;
            String replace;
            int i = 0;
            while(sc.hasNext()){
                line = sc.next();
                //replace = line.replace(" ","").replace(",", "").replace(".", "").replace(":","");
                replace = line.replaceAll("[ .:,]","");
                a[i] = replace;
                i++;
            }
            sc.close();

        }catch(FileNotFoundException e){
            System.out.println(e.getMessage());
            System.exit(-1);
        }
        return a;
    }

    public ArrayList<String> readDictionary(){
        ArrayList<String> dictionary = new ArrayList<>();
        File file = new File("../../test/test2/dictionary.txt");
        try{
            Scanner sc = new Scanner(file);
            while(sc.hasNext()){
                dictionary.add(sc.nextLine());
            }
            sc.close();
        }catch(FileNotFoundException e){
            System.out.println(e.getMessage());
            System.exit(-1);
        }
        return dictionary;
    }

}
