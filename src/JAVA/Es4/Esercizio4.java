
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
        File file = new File("../../../test/test4/test1/input.txt");
        /*
        File file2 = new File("../../../test/test4/test2/input.txt");
        File file3 = new File("../../../test/test4/test3/input.txt");
        File file4 = new File("../../../test/test4/test4/input.txt");
        File file5 = new File("../../../test/test4/test5/input.txt");
        File file6 = new File("../../../test/test4/test6/input.txt");
        File file7 = new File("../../../test/test4/test7/input.txt");
        File file8 = new File("../../../test/test4/test8/input.txt");
        File file9 = new File("../../../test/test4/test9/input.txt");
        File file10 = new File("../../../test/test4/test10/input.txt");
        File file11 = new File("../../../test/test4/test11/input.txt");
        */
        //File file = new File("input3.txt");

        //File file = new File("input.txt");
        //File file = new File("test");
        //File file = new File("test2");
        //args[1] = "../../../test/test4/";


        Map<Integer, ArrayList<Pair>> mappa = new HashMap<>();
        Map<Integer,NodeParent> path = new HashMap<>();
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
                //int a[] = new int[3];
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
            //grafo.printMap();

            grafo.BFS(1,numbOfSource,numbOfSource,path);

            //grafo.DFS(1,numbOfSource,numbOfSource,path);


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
                    String[] parts = s.split("\\s+");
                    int source = Integer.parseInt(parts[0]);
                    int adj = Integer.parseInt(parts[1]);
                    int weight = Integer.parseInt(parts[2]);
                    grafo.findPath(source,adj,weight,path);
                    //scrivo.write(grafo.findPath(source,adj,weight,path));




                }
                long endQuery = System.nanoTime();
                System.out.println((double)(endQuery-startQuery) / 1000000000 + " sec");
                sc.close();
                scrivo.close();
                System.out.println();

            }catch(IOException e){
                e.printStackTrace();
            }

        }catch(FileNotFoundException e){
            e.printStackTrace();
        }
        //grafo.printMap();

    }




}
