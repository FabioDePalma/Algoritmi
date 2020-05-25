class NodeParent{
    private int value;
    private boolean color;

    public NodeParent(int valore){
        this.value = valore;
        this.color = false;
    }

    public int getParent(){
        return value;
    }
    public void setParent(int value){
        this.value = value;
    }
    public boolean getColor(){
        return color;
    }
    public void setColor(boolean color){
        this.color = color;
    }


}
