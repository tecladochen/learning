package Tang;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class one {
    public static void main(String[] args) throws IOException {
        File file = new File("Exercise17_01.txt");
        if(file.exists()) {
            PrintWriter output = new PrintWriter(file);
            for(int i=1;i<=100;i++) {
                output.print((int)(Math.random()*1000));
                output.print(" ");
                if(i % 10 == 0)
                    output.println();
            }
            output.close();
        }
        else {
            file.createNewFile();
        }
    }
}
