public class CurrencyConverter {
    private static double rate;

    public static void setRate(int _rate) {rate = _rate;}
    public static String toDollor(int won) {return String.valueOf(won / rate);}
    public static String toKWR(int dollor) {return String.valueOf(dollor * rate);}
}