package Tang;

import java.io.IOException;
import java.io.RandomAccessFile;

public class four {
    public static void main(String[] args) throws IOException {
        RandomAccessFile inout = new RandomAccessFile("Exercise17_08.dat","rw");
        inout.seek(0);
        int num=inout.readInt();
        inout.seek(0);
        inout.writeInt(1+num);
        inout.seek(0);
        System.out.println("The number of program runs is " + inout.readInt());
        inout.close();
    }
}
