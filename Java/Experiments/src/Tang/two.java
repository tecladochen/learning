package Tang;

import java.io.*;

public class two {
    public static void main(String[] args) throws IOException {
        File file = new File("Exercise17_02.dat");
        if(file.exists()) {
            DataOutputStream output = new DataOutputStream(new FileOutputStream("Exercise17_02.dat"));
            for(int i=1;i<=5;i++) {
                int a=(int)(Math.random()*1000);
                System.out.println(a);
                output.writeInt(a);
            }
            output.close();
        }
        else {
            file.createNewFile();
        }

        DataInputStream input = new DataInputStream(new FileInputStream("Exercise17_02.dat"));
        int sum=0;
        for(int i=1;i<=3;i++)
            sum+=input.readInt();
        System.out.println(sum);
    }
}
