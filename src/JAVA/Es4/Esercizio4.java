
import java.io.*;
import java.util.*;
/*
6
1 2 2
1 3 3
3 4 5
3 5 4
2 6 4
4
1 4 4
4 5 6
2 3 8
1 6 3
*/
class Esercizio4{

    public static void main(String[] args) {
        //File file = new File("../../../test/test4/test2/input.txt");
        //File file = new File("input.txt");
        File file = new File("test");
        Map<Integer, ArrayList<Pair>> mappa = new HashMap<>();
        Graph grafo = new Graph(mappa);
        try{
            long startCreate = System.nanoTime();
            Scanner sc = new Scanner(file);
            int numbOfSource = sc.nextInt();
            sc.nextLine();
            System.out.println(numbOfSource);
            int i = 0;
            while(i < numbOfSource-1){
                String s = sc.nextLine();
                int a[] = new int[3];
                String[] parts = s.split("\\s+");
                int source = Integer.parseInt(parts[0]);
                int adj = Integer.parseInt(parts[1]);
                int weight = Integer.parseInt(parts[2]);
                //System.out.println(source + " " + adj +" " +weight);
                Pair p = new Pair(adj, weight);
                grafo.createGraph(source, p);
                i++;
            }
            long endCreate = System.nanoTime();
            System.out.println((double)(endCreate-startCreate) / 1000000000 + " sec");
            File apro = new File("answer");
            try{
                long startQuery = System.nanoTime();
                FileWriter scrivo = new FileWriter("answer");
                int numbOfQuery = sc.nextInt();
                sc.nextLine();
                System.out.println(numbOfQuery);
                while(sc.hasNext()){
                    String s = sc.nextLine();
                    int a[] = new int[3];
                    String[] parts = s.split("\\s+");
                    int source = Integer.parseInt(parts[0]);
                    int adj = Integer.parseInt(parts[1]);
                    int weight = Integer.parseInt(parts[2]);

                    //ArrayList<Integer> path = grafo.findPath(source,adj);
                    //System.out.println(grafo.query(path, weight));
                    //grafo.query(path,weight);
                    //grafo.findPath(source, adj, weight);
                    scrivo.write(grafo.findPath(source, adj, weight) + "\n");


                }
                long endQuery = System.nanoTime();
                System.out.println((double)(endQuery-startQuery) / 1000000000 + " sec");
                sc.close();
                scrivo.close();
                System.out.println();

                /*
                for(int z = 0; z<path.size();z++){
                    System.out.println(path.get(z));
                }
                */
            }catch(IOException e){
                e.printStackTrace();
            }





        }catch(FileNotFoundException e){
            e.printStackTrace();
        }
        //grafo.printMap();

    }




}
