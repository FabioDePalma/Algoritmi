import org.junit.Test;
import static org.junit.Assert.*;

public class EditDistanceTest{

    @Test
    public void mini(){
        assertEquals(2, EditDistance.min(5,2,4));
    }

    @Test
    public void editDistance_test0() {
        String word1 = "casa";
        String word2 = "cassa";

        assertEquals(1, EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test1() {
        String word1 = "casa";
        String word2 = "cara";

        assertEquals(2, EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test2() {
        String word1 = "vinaio";
        String word2 = "vino";

        assertEquals(2, EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test3() {
        String word1 = "tassa";
        String word2 = "passato";

        assertEquals(4, EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test4() {
        String word1 = "pioppo";
        String word2 = "pioppo";

        assertEquals(0, EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test5() {
        String word1 = "";
        String word2 = "casa";

        assertEquals(word2.length(), EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test6() {
        String word1 = "casa";
        String word2 = "";

        assertEquals(word1.length(), EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test7() {
        String word1 = "";
        String word2 = "";

        assertEquals(0, EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test8() {
        String word1 = null;
        String word2 = null;

        assertEquals(-1, EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test9() {
        String word1 = "casa";
        String word2 = null;

        assertEquals(-1, EditDistance.distance(word1, word2));
    }

    @Test
    public void editDistance_test10() {
        String word1 = null;
        String word2 = "casa";

        assertEquals(-1, EditDistance.distance(word1, word2));
    }

}



//compile test: javac -cp .;junit-4.13.jar;hamcrest-core-1.3.jar EditDistanceTest.java
//run test: java -cp .;junit-4.13.jar;hamcrest-core-1.3.jar org.junit.runner.JUnitCore EditDistanceTest
