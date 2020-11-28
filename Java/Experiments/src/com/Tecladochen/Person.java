package com.Tecladochen;

import javax.swing.plaf.synth.SynthTextAreaUI;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Person {
    private String name,address,number,email;
    public Person(String name, String address, String number, String email){
        this.name = name;
        this.address = address;
        this.number = number;
        this.email = email;
    }

    @Override
    public String toString() {
        return  "name='" + name + '\'' +
                ", address='" + address + '\'' +
                ", number='" + number + '\'' +
                ", email='" + email + '\'';
    }
}
class Student extends Person {
    private final String rank;
    public Student(String name, String address, String number, String email, String rank){
        super(name,address,number,email);
        this.rank = rank;
    }

    @Override
    public String toString() {
        return super.toString() + "Grade ='" + rank + '\'';
    }
}
class Employee extends Person {
    private String office;//办公室
    private int salary;//工资
    private MyDate employtime;
    public Employee(String name, String address, String number, String email,String office,
                    int salary,int year, int month, int day) {
        super(name, address, number, email);
        this.office = office;
        this.salary = salary;
        employtime = new MyDate(year, month, day);
    }

    @Override
    public String toString() {
        return  super.toString() +
                "office='" + office + '\'' +
                ", salary=" + salary +
                ", employtime=" + employtime.toString() ;
    }
}
class Faculty extends Employee {
    private double workstart;
    private double workend;
    private String rank;
    public Faculty(String name, String address, String number, String email,String office,
                   int salary,int year, int month, int day,double workstart,double workend,
                   String rank){
        super(name,address,number,email,office,salary,year,month,day);
        this.workstart = workstart;
        this.workend = workend;
        this.rank = rank;
    }

    @Override
    public String toString() {
        return  super.toString() +
                "workstart=" + workstart +
                ", workend=" + workend +
                ", rank='" + rank + '\'';
    }
}
class Staff extends Employee {
    private String call;
    public Staff(String name, String address, String number, String email,String office,
                 int salary,int year, int month, int day,String call){
        super(name,address,number,email,office,salary,year,month,day);
        this.call = call;
    }

    @Override
    public String toString() {
        return  super.toString() +
                "call='" + call + '\'';
    }
}
class MyDate {
    private int year, month, day;

    public MyDate() {
        java.util.GregorianCalendar now = new java.util.GregorianCalendar();
        year = now.get(GregorianCalendar.YEAR);
        month = now.get(GregorianCalendar.MONTH);
        day = now.get(GregorianCalendar.DAY_OF_MONTH);
    }

    public MyDate(Long i) {
        java.util.GregorianCalendar now = new java.util.GregorianCalendar();
        now.setTimeInMillis(i);
        year = now.get(GregorianCalendar.YEAR);
        month = now.get(GregorianCalendar.MONTH);
        day = now.get(GregorianCalendar.DAY_OF_MONTH);
    }

    public MyDate(int x, int y, int z) {
        year = x;
        month = y;
        day = z;
    }

    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    public void setDate(Long i) {
        java.util.GregorianCalendar now = new java.util.GregorianCalendar();
        now.setTimeInMillis(i);
        year = now.get(GregorianCalendar.YEAR);
        month = now.get(GregorianCalendar.MONTH);
        day = now.get(GregorianCalendar.DAY_OF_MONTH);
    }

    @Override
    public String toString() {
        return "Employment time is " +
                year + "年" +
                month + "月" +
                day + "日 ";
    }
}
class TestPerson{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter necessary name,address,Tel and email :");
        String name = input.next();
        String address = input.next();
        String numbers = input.next();
        String email = input.next();
        System.out.print("Please select (Student/Employee) :");
        String select1 = input.next();
        if(select1.equals("Student")){

            System.out.print("Please select student's grade :");
            String grade = input.next();
            Student student1 = new Student(name,address,numbers,email,grade);
            System.out.print(student1.toString());
        }
        else{
            System.out.print("Please enter necessary office and salary :");
            String office = input.next();
            int salary = input.nextInt();
            System.out.print("Please enter employment time (Example:2020 2 23) :");
            int year = input.nextInt();
            int month = input.nextInt();
            int day = input.nextInt();
            System.out.print("Please select (Faculty/Staff) :");
            String select2 = input.next();
            if(select2.equals("Faculty")){
                System.out.println("Please enter necessary Worktime and rank :");
                System.out.print("WorkStart time is ");
                double workstart = input.nextDouble();
                System.out.print("WorkEnd time is ");
                double workend = input.nextDouble();
                System.out.print("The rank is ");
                String rank = input.next();
                Faculty faculty1 = new Faculty(name,address,numbers,email,office,salary,year,month,
                        day,workstart,workend,rank);
                System.out.print(faculty1.toString());
            }
            else{
                System.out.print("Please enter necessary Position :");
                String call = input.next();
                Staff staff1 = new Staff(name,address,numbers,email,office,salary,year,month,day,call);
                System.out.print(staff1.toString());
            }
        }
    }
}