
import java.io.*;
import java.util.*;
class Es4{

    public static void main(String[] args) {


        Map<Integer, ArrayList<Pair>> mappa = new HashMap<>();
        Map<Integer,NodeParent> path = new HashMap<>();
        Graph grafo = new Graph(mappa);

        Scanner sc = new Scanner(System.in);

        int numbOfSource = sc.nextInt();
        sc.nextLine();
        int i = 0;
        while(i < numbOfSource-1){
            String s = sc.nextLine();
            String[] parts = s.split("\\s+");
            int source = Integer.parseInt(parts[0]);
            int adj = Integer.parseInt(parts[1]);
            int weight = Integer.parseInt(parts[2]);
            Pair p = new Pair(adj, weight);
            grafo.createGraph(source, p);
            i++;
        }

        grafo.BFS(1,numbOfSource,numbOfSource,path);


        int numbOfQuery = sc.nextInt();
        sc.nextLine();
        while(sc.hasNext()){
            String s = sc.nextLine();
            String[] parts = s.split("\\s+");
            int source = Integer.parseInt(parts[0]);
            int adj = Integer.parseInt(parts[1]);
            int weight = Integer.parseInt(parts[2]);
            System.out.print(grafo.query(source,adj,weight,path));

        }
        sc.close();


    }



}
