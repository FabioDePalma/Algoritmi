
import java.util.*;

class Graph{
    private Map<Integer, ArrayList<Pair>> mappa = new HashMap<>();
    private int totalNode;

    public Graph(Map<Integer, ArrayList<Pair>> mappa){
        this.mappa = mappa;
        this.totalNode = 0;
    }

    /*Creazione del grafo*/
    public void createGraph(int source, Pair edge){
        addNode(source, edge);
        Pair contrario = new Pair(source, edge.getWeight());
        addNode(edge.getAdj(), contrario);
    }
    /*Aggiunta dei nodi nella hashmap*/
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
                        return true;
                    }

                }
            }
            temp.add(edge);
            return true;
        }else{
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


    public String query(int source, int destination, int newWeight, Map<Integer, NodeParent> pred){

        if(source == destination){
          return "NO\n";
        }

        if(destination == 1 ){
            return querySupp(destination, source, newWeight, pred, 1);
        }



        int root = findRoot(source, destination, pred);
        int tornoIndietro = destination;


        while(pred.get(tornoIndietro) != null && tornoIndietro != root ){
            ArrayList<Pair> temp = mappa.get(tornoIndietro);

            tornoIndietro = pred.get(tornoIndietro).getParent();
            for(Pair i : temp){
                if(i.getAdj() == tornoIndietro){
                    int wei = i.getWeight();
                    if(wei > newWeight){
                        return "YES\n";
                    }
                }
            }
        }

        if(tornoIndietro == 1 || tornoIndietro == root){
            return querySupp(destination, source, newWeight, pred, root);
        }
        return "NO\n";


    }

    public String querySupp(int source, int destination, int newWeight, Map<Integer, NodeParent> pred, int root){
        int tornoIndietro = destination;
        while(pred.get(tornoIndietro) != null && tornoIndietro != root){
            ArrayList<Pair> temp = mappa.get(tornoIndietro);
            tornoIndietro = pred.get(tornoIndietro).getParent();

            for(Pair j : temp){
                if(j.getAdj() == tornoIndietro){

                    int wei = j.getWeight();
                    if(wei > newWeight){
                        return "YES\n";
                    }
                }
            }
        }
        return "NO\n";
    }

    public int findRoot(int source, int destination, Map<Integer, NodeParent> pred){
        int tornoIndietro = destination;
        boolean flag = true;
        if(pred.get(tornoIndietro)==null || source  == 1){
            return 1;
        }else if(pred.get(source).getParent() == destination){
            return destination;
        }else if(source == pred.get(destination).getParent()){
            return source;
        }


        while(pred.get(tornoIndietro) != null && flag){
            if(pred.get(tornoIndietro).getParent() == source){
                pred.get(tornoIndietro).setColor(true);
                flag = false;
            }
            pred.get(tornoIndietro).setColor(true);
            tornoIndietro = pred.get(tornoIndietro).getParent();

        }

        int versoAlto = source;
        while(pred.get(versoAlto) != null && !pred.get(versoAlto).getColor() && flag){
            if(pred.get(versoAlto).getParent() == destination){
                break;
            }
            versoAlto = pred.get(versoAlto).getParent();
        }
        tornoIndietro = destination;
        while(pred.get(tornoIndietro) != null && pred.get(tornoIndietro).getColor()){

            pred.get(tornoIndietro).setColor(false);
            tornoIndietro = pred.get(tornoIndietro).getParent();
        }
        if(!flag){
            return source;
        }
        return pred.get(versoAlto) == null ? 1: pred.get(versoAlto).getParent();
    }

    public void BFS(int source,int dest, int n, Map<Integer,NodeParent> pred){
        LinkedList<Integer> queue = new LinkedList<Integer>();
        boolean visited[] = new boolean[n+1];

        visited[source] = true;
        queue.add(source);

        while(!queue.isEmpty()){
            NodeParent u = new NodeParent(queue.remove());

            ArrayList<Pair> temp = mappa.get(u.getParent());
            for(int i = 0; i < temp.size() ; i++){
                int node = temp.get(i).getAdj();
                if(visited[node] == false){
                    visited[node] = true;
                    pred.put(node, u);
                    queue.add(node);
                }
            }
        }
    }

}
