package com.Tecladochen;

import java.util.ArrayList;
import java.util.List;

public class HeapOverFlow {
    public static void main(String[] args) {
        List<Example> list = new ArrayList<>();
        try {
            while (true) {
               list.add(new Example());
            }
        }catch (OutOfMemoryError ex){
            list = new ArrayList<>();
            System.out.println("The exception has been solved ");
        }
    }
}
class Example{

}