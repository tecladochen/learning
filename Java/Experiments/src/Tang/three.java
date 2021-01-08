package Tang;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;

public class three {
    public static void main(String[] args) throws IOException {
        int[] list=new int[5];
        for(int i=0;i<5;i++) {
            list[i]=i+1;
        }
        Date date=new Date();
        SimpleDateFormat simpleDateFormat=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String format=simpleDateFormat.format(date);

        File file = new File("Exercise17_05.dat");
        if(file.exists()) {
            DataOutputStream output = new DataOutputStream(new FileOutputStream("Exercise17_05.dat"));
            for(int i=0;i<list.length;i++)
                output.writeInt(list[i]);
            output.writeUTF(format);
            output.writeDouble(5.5);
            output.close();
        }
        else
            file.createNewFile();
        DataInputStream input = new DataInputStream(new FileInputStream("Exercise17_05.dat"));
        for(int i=0;i<5;i++) {
            System.out.println(input.readInt());
        }
        System.out.println(input.readUTF());
        System.out.println(input.readDouble());
    }
}