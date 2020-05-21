
import java.util.*;

class Graph{
    private Map<Integer, ArrayList<Pair>> mappa = new HashMap<>();
    //private long totalSum;
    private int totalNode;

    public Graph(Map<Integer, ArrayList<Pair>> mappa){
        this.mappa = mappa;
        //this.totalSum = 0;
        this.totalNode = 0;
    }

    public String query(ArrayList<Integer> path, int quertyWeight){
        //String answer = null;
        //int max = 0;
        for(int i = 0; i<path.size()-1; i++){
            int source = path.get(i);
            int dest = path.get(i+1);
            ArrayList<Pair> adjacent = mappa.get(source);
            for(int j = 0; j<adjacent.size(); j++){
                if(adjacent.get(j).getAdj() == dest){
                    //max = adjacent.get(j).getWeight();
                    if(adjacent.get(j).getWeight() > quertyWeight){
                        return "YES";
                    }else{
                        break;
                    }
                }
            }
        }
        return "NO";


        //return answer;
    }

    public void createGraph(int source, Pair edge){
        addNode(source, edge);
        Pair contrario = new Pair(source, edge.getWeight());
        addNode(edge.getAdj(), contrario);
        //this.totalSum = this.totalSum + edge.getWeight();
    }

    public boolean addNode(int source, Pair edge){
        if(mappa.containsKey(source)){
            ArrayList<Pair> temp = mappa.get(source);
            for(int i = 0; i < temp.size(); i++){
                if(edge.getAdj() == temp.get(i).getAdj()){
                    if(edge.getWeight() != temp.get(i).getWeight()){
                        //errore tento di collegare un adiacente uguale con peso diverso
                        System.err.println("adjacent exist");
                        return false;
                    }else{
                        System.err.println("Pair <adj weight> alredy exist");
                        return true;//pair identica ad adj gia presente
                    }

                }//altrimenti nulla
            }//fine controlli preliminari
            temp.add(edge);
            return true;
        }else{//source NON ESISTE
            ArrayList<Pair> adj = new ArrayList<>();
            adj.add(edge);
            mappa.put(source, adj);
            this.totalNode++;
            return true;
        }
    }

    public int numOfNode(){
        return mappa.size();
    }


    public void printMap(){
        for(int source : mappa.keySet()){
            ArrayList<Pair> temp = mappa.get(source);
            System.out.print(source + " --> ");
            for(int i = 0; i < temp.size(); i++){
                System.out.print(temp.get(i).getAdj() + "|" + temp.get(i).getWeight() + " " );
            }
            System.out.println();
        }
    }
/*
    public ArrayList<Integer> dfs(int source, int destination){
        ArrayList<Integer> visited = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        visited.add(source);
        dfSupp(visited, destination,temp);
        return temp;
    }
    public void dfSupp(ArrayList<Integer> visited, int destination,ArrayList<Integer> save){
        ArrayList<Pair> nodes = mappa.get(visited.get(visited.size()-1));

        for(Pair node:nodes){


            if(visited.contains(node.getAdj())){
                continue;//saltiamo la condizione sotto e andiamo avanti con il for
            }
            if(node.getAdj() == destination){

                visited.add(node.getAdj());
                save.addAll(visited);
                visited.remove(visited.size()-1);
                break;
            }
        }
        for(Pair node : nodes){
            if(visited.contains(node.getAdj()) || node.getAdj() == destination){
                continue;
            }
            visited.add(node.getAdj());
            dfSupp(visited, destination,save);
            visited.remove(visited.size()-1);
        }
    }

*/

String findPath(int source, int destination, int newWeight){
    int n = this.totalNode;
    int pred[] = new int[n+1];
    BFS(source, destination, n, pred);

    //ArrayList<Integer> path = new ArrayList<>();
    int tornoIndietro = destination;
    //path.add(destination);
    while(pred[tornoIndietro] != -1){
        //path.add(pred[tornoIndietro]);
        ArrayList<Pair> temp = mappa.get(tornoIndietro);
        tornoIndietro = pred[tornoIndietro];
        for(Pair i : temp){
            int wei = i.getWeight();
            if(wei > newWeight){
                return "YES";
            }
        }
    }
    return "NO";
}
/*

public void depthFirstSearch(Node node) {
    node.visit();
    System.out.print(node.name + " ");

    LinkedList<Node> allNeighbors = adjacencyMap.get(node);
    if (allNeighbors == null)
        return;

    for (Node neighbor : allNeighbors) {
        if (!neighbor.isVisited())
            depthFirstSearch(neighbor);
    }
}
*/
/*
String findPath(int source, int destination, int newWeight){
    boolean visited[] = new boolean[totalNode+1];
    ArrayList<Integer> path = new ArrayList<>();
    DFS(source, destination, visited, path);
    return query(path, newWeight);



}
public  void DFS(int source, int dest, boolean visited[], ArrayList<Integer> path){
    //boolean visited[] = new boolean[totalNode];
    visited[source] = true;
    path.add(source);
    ArrayList<Pair> vicini = mappa.get(source);
    if(vicini == null || source == dest){
        return;
    }
    for(Pair vici : vicini){
        int node = vici.getAdj();
        if(visited[node] == false){
            DFS(node, dest, visited, path);
        }
    }

}
*/

boolean BFS(int source,int dest, int n, int pred[]){
    LinkedList<Integer> queue = new LinkedList<Integer>();
    boolean visited[] = new boolean[n+1];
    for(int i = 0; i < visited.length; i++){
        visited[i] = false;
        pred[i] = -1;
    }
    visited[source] = true;
    queue.add(source);

    while(!queue.isEmpty()){// finche la coda non è vuota
        int u = queue.remove();
        ArrayList<Pair> temp = mappa.get(u);
        for(int i = 0; i < temp.size(); i++){
            int node = temp.get(i).getAdj();
            if(visited[node] == false){
                visited[node] = true;
                pred[node] = u;
                queue.add(node);
                // in questo punto controllo se il peso del nodo è più grande del peso della domanda
                if(node == dest){
                    return true;
                }

            }
        }
    }
    return false;

}


/*
    public ArrayList<Edge> mergeSort(ArrayList<Edge> array){
        ArrayList<Edge> left = new ArrayList<>();
        ArrayList<Edge> right = new ArrayList<>();
        int center;
        if(array.size() == 1){
            return array;
        }else{
            center = array.size()/2;
            for(int i = 0; i<center; i++){
                left.add(array.get(i));
            }
            for(int i = center; i< array.size(); i++){
                right.add(array.get(i));
            }
            left = mergeSort(left);
            right = mergeSort(right);

            merge(left, right, array);
        }
        return array;
    }

    public void merge(ArrayList<Edge> left, ArrayList<Edge>right, ArrayList<Edge> array){
        int leftIndex=0, rightIndex=0, arrayIndex=0;
        while(leftIndex < left.size() && rightIndex> right.size()){
            if(left.get(leftIndex).getWeight() > right.get(rightIndex).getWeight()){
                array.set(arrayIndex, left.get(leftIndex));
                leftIndex++;
            }else{
                array.set(arrayIndex, right.get(rightIndex));
                rightIndex++;
            }
        }
    }

    public ArrayList<Edge> kruskal(ArrayList<Edge> archi){
        ArrayList<Edge> finito = new ArrayList<>();
        ArrayList<Integer> allSource = new ArrayList<>();
        allSource.addAll(mappa.keySet());
        mergeSort(archi);
        UnionFind set = new UnionFind();
        set.makeSet(allSource);
        for(Edge i : archi){
            int parentSource = set.findSet(i.getSource());
            int parentAdj = set.findSet(i.getAdj());
            if(parentSource != parentAdj){
                finito.add(i);
                set.union(parentSource,parentAdj);
            }
        }
        return finito;
    }
*/






}
