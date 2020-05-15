import java.util.*;
import java.io.*;

class Esercizio2{
    public static final int dimCitazione = 49;

    private static String[] readCorrectme(String[] a){
        File file = new File("../../../test/test2/correctme.txt");
        try{
            Scanner sc = new Scanner(file);
            String line;
            String replace;
            int i = 0;
            while(sc.hasNext()){
                line = sc.next();
                //replace = line.replace(" ","").replace(",", "").replace(".", "").replace(":","");
                replace = line.replaceAll("[ .:,]","");
                a[i] = replace.toLowerCase();
                i++;
            }
            sc.close();

        }catch(FileNotFoundException e){
            System.out.println(e.getMessage());
            System.exit(-1);
        }
        return a;
    }

    private static ArrayList<String> readDictionary(){
        ArrayList<String> dictionary = new ArrayList<>();
        File file = new File("../../../test/test2/dictionary.txt");
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

    public static void main(String[] args) {
        EditDistanceDyn editDistance = new EditDistanceDyn();
        long start = System.nanoTime();
        String[] citazione = new String[dimCitazione];
        ArrayList<String> dictionary = new ArrayList<String>();

        readCorrectme(citazione);
        dictionary = readDictionary();
        int edit;
        String s1;
        String s2;
        int s1Size;// i
        int s2Size;// j
        ArrayList<ArrayList<String>> minEditDistance = new ArrayList<ArrayList<String>>(dimCitazione);
        ArrayList<String> insert = null;
        for(int i = 0; i < citazione.length; i++){
            int min = Integer.MAX_VALUE;
            for(int j = 0; j < dictionary.size(); j++){
                s1 = citazione[i];
                s2 = dictionary.get(j);
                s1Size = s1.length();
                s2Size = s2.length();
                int [][] matrix = new int[s1Size][s2Size];
                edit = editDistance.distanceDyn(s1, s2, s1Size, s2Size, matrix);
                if(edit == 0){
                    insert = new ArrayList<>();
                    j = dictionary.size()+1;
                }else if(edit < min){
                    insert = new ArrayList<>();
                    insert.add(0, dictionary.get(j));
                    min = edit;
                }else if(edit == min){
                    insert.add(0, dictionary.get(j));
                }
            }
            minEditDistance.add(i, insert);
        }
        for (int i = 0; i < citazione.length; i++) {
            System.out.print(citazione[i] + ": ");
            for (int j = 0; j < minEditDistance.get(i).size(); j++) {
                System.out.print(" " + minEditDistance.get(i).get(j));
            }
            System.out.println("");
        }
        long end = System.nanoTime();
        System.out.println((double)(end-start) / 1000000000 + " sec");

    }

}
