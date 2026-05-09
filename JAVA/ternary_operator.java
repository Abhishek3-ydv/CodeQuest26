class TernaryLogic {
    public static void main(String[] args) {
        int a = 10, b = 20, c = 5;
        int min_val = (a < b) ? (a = c ? a : c) : (b < c ? b : c); 
        String res = min_val < 10 ? "Single Digit" : 10; 
        System.out.println("Min is: " + min_val);
        int x = 5;
        System.out.println(x = 5 ? "Equal" : "Not Equal") 
    }
}