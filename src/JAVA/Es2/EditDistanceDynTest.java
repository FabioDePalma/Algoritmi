import org.junit.Test;
import static org.junit.Assert.*;

public class EditDistanceDynTest{

    @Test
    public void mini(){
        assertEquals(2, EditDistanceDyn.min(5,2,4));
    }

    @Test
    public void EditDistanceDyn_test0() {
        String word1 = "casa";
        String word2 = "cassa";
        int s1Size = word1.length();
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(1, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test1() {
        String word1 = "casa";
        String word2 = "cara";
        int s1Size = word1.length();
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(2, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test2() {
        String word1 = "vinaio";
        String word2 = "vino";
        int s1Size = word1.length();
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(2, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test3() {
        String word1 = "tassa";
        String word2 = "passato";
        int s1Size = word1.length();
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(4, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test4() {
        String word1 = "pioppo";
        String word2 = "pioppo";
        int s1Size = word1.length();
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(0, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test5() {
        String word1 = "";
        String word2 = "casa";
        int s1Size = word1.length();
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(word2.length(), EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test6() {
        String word1 = "casa";
        String word2 = "";
        int s1Size = word1.length();
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(word1.length(), EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test7() {
        String word1 = "";
        String word2 = "";
        int s1Size = word1.length();
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(0, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test8() {
        String word1 = null;
        String word2 = null;
        int s1Size = 0;
        int s2Size = 0;
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(-1, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test9() {
        String word1 = "casa";
        String word2 = null;
        int s1Size = word1.length();
        int s2Size = 0;
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(-1, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

    @Test
    public void EditDistanceDyn_test10() {
        String word1 = null;
        String word2 = "casa";
        int s1Size = 0;
        int s2Size = word2.length();
        int[][] matrix = new int[s1Size][s2Size];

        assertEquals(-1, EditDistanceDyn.distanceDyn(word1, word2, s1Size, s2Size, matrix));
    }

}

//compile test: javac -cp .;junit-4.13.jar;hamcrest-core-1.3.jar EditDistanceDynTest.java
//run test: java -cp .;junit-4.13.jar;hamcrest-core-1.3.jar org.junit.runner.JUnitCore EditDistanceDynTest
