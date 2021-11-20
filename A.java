class A{
    public static void main(String[] arg){
        Student obj[10];

        for (int i=0;i<10;i++){obj[i]= new Student(i);}
    }
}

class Student{
    String name;

    Student(int i){
    System.out.println("Object "+i);
    }
}