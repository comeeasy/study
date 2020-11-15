public class AutoBoxingUnBoxing {
    public static void main(String[] args) {
        int i = 10;
        Integer intObject = i;
        //auto boxing
        System.out.println("intObject = "+intObject);

        //auto unboxing
        i = intObject + 10;
        System.out.println("i = "+i);
    }
}
