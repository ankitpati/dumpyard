import java.io.IOException;

class ExecThing {
    public static void main(String args[]) {
        try {
            Runtime.getRuntime().exec("echo hello");
            Runtime.getRuntime().exec(new String[] { "echo", "hello" });
        } catch (IOException ioe) {
            System.err.println("Couldn’t exec!");
        }
    }
}
