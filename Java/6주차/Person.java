public class Person {
    int age;
    public String name;
    protected int height;
    private int weight;

    public void setWeight(int w) {this.weight = w;}
    public int getWeight() {return weight;}
    public void print() {
        System.out.println("name  : "+name);
        System.out.printf("height: %d\n", height);
        System.out.printf("weight: %d\n", getWeight());
    }
}
