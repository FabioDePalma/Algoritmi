import java.util.*;

class MainEditDistanceDyn{

    public static void main(String[] args) {
        EditDistanceDyn editDistance = new EditDistanceDyn();
        long start = System.nanoTime();
        String[] citazione = new String[49];
        ArrayList<String> dictionary = new ArrayList<String>();

        editDistance.readCorrectme(citazione);
        dictionary = editDistance.readDictionary();
        int edit;
        String s1;
        String s2;
        int s1Size;
        int s2Size;
        ArrayList<ArrayList<String>> minEditDistance = new ArrayList<ArrayList<String>>(49);
        ArrayList<String> insert = null;
        for(int i = 0; i < citazione.length; i++){
            int min = Integer.MAX_VALUE;
            for(int j = 0; j < dictionary.size(); j++){
                s1 = citazione[i];
                s2 = dictionary.get(j);
                s1Size = citazione[i].length();
                s2Size = dictionary.get(j).length();
                int [][] matrix = new int[s1Size][s2Size];
                edit = editDistance.distanceDyn(s1, s2, s1Size, s2Size, matrix);
                if(edit < min){
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
        System.out.println((end-start) / 1000000000 + "sec");

    }

}
