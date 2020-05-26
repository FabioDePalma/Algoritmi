
import java.io.*;
import java.util.*;
class Es4{

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
        Map<Integer, ArrayList<Pair>> mappa = new HashMap<>();
        Map<Integer,NodeParent> path = new HashMap<>();
        Graph grafo = new Graph(mappa);

        try{
            Scanner sc = new Scanner(file);

            int numbOfSource = sc.nextInt();
            sc.nextLine();
            int i = 0;
            while(i < numbOfSource-1){
                String s = sc.nextLine();
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

                long startQuery = System.nanoTime();
                int numbOfQuery = sc.nextInt();
                sc.nextLine();
                while(sc.hasNext()){
                    String s = sc.nextLine();
                    String[] parts = s.split("\\s+");
                    int source = Integer.parseInt(parts[0]);
                    int adj = Integer.parseInt(parts[1]);
                    int weight = Integer.parseInt(parts[2]);
                    System.out.print(grafo.findPath(source,adj,weight,path));
                    //scrivo.write(grafo.findPath(source,adj,weight,path));




                }
                sc.close();



        }catch(FileNotFoundException e){
            e.printStackTrace();
        }
        //grafo.printMap();

    }




}
