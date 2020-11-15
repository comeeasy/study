public class Student extends Person {
    void set(String name, int height, int weight) {
        this.name = name;
        this.height = height;
        setWeight(weight);
    }

    public static void main(String[] args) {
        Student s = new Student();
        s.set("joonho", 180, 70);
        s.print();
    }
}
