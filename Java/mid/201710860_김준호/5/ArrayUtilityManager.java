public class ArrayUtilityManager {
    public static void main(String[] args) {
        int[] s1 = {1, 2, 3, 4};
        int[] s2 = {3, 4, 5, 6};

        int[] result = ArrayUtility.concat(s1, s2);
        System.out.print("concat의 결과 :");
        for(int i: result) System.out.printf(" %d", i);
        System.out.println();

        result = ArrayUtility.remove(s1, s2);
        System.out.print("remove의 결과 :");
        for(int i: result) System.out.printf(" %d", i);
        System.out.println();
    }
}
