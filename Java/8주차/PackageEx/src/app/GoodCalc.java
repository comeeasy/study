package app;

import lib.Calculator;

public class GoodCalc extends Calculator {
    public int add(int a, int b) {return a + b;}
    public int substract(int a, int b) {return a - b;}
    public double average(int[] a) {
        int sum = 0;
        for(int i : a) {sum += i;}
        return (double)sum / a.length;
    }

    public static void main(String[] args) {
        Calculator c = new GoodCalc();

        System.out.println(c.add(2, 3));
        System.out.println(c.substract(2, 3));
        System.out.println(c.average(new int[] {2, 3, 4}));
    }
}
